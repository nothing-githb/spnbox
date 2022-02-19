



#include <config.h>

#if N_IN == 24

#include <spn/spn24.h>
#include <tables/8bit.h>
#include <tables/24bit.h>
#include <tables/tables.h>
#include <stdlib.h>
#include <stdio.h>
#include <types.h>
#include <spnbox.h>
#include <sbox.h>
#include <tableMng.h>

#define BIT24 (0x00111111)

#define OUTER_DEBUG 0
#define SBC_DEBUG 0
#define MC_DEBUG 0

#define ROUND                           10
#define SIZE_OF_MATRIX                  5
#define T                               SIZE_OF_MATRIX
#define NUM_OF_ROUND                    20

uint8_t inner_table[3][3] = {{0x02,0x01,0x01},
                             {0x03,0x01,0x01},
                             {0x01,0x03,0x02}};

uint32_t outer_table[5][5] = {{0x01,0x04,0x03,0x05,0x02},
                              {0x02,0x01,0x04,0x03,0x05},
                              {0x05,0x02,0x01,0x04,0x03},
                              {0x03,0x05,0x02,0x01,0x04},
                              {0x04,0x03,0x05,0x02,0x01}};

const uint8_t* inner_matrix[3][3] = {{TABLE(8, 02), TABLE(8, 01), TABLE(8, 01)},
                                     {TABLE(8, 03), TABLE(8, 02), TABLE(8, 01)},
                                     {TABLE(8, 01), TABLE(8, 03), TABLE(8, 02)}};

const uint32_t* omtrx[SIZE_OF_MATRIX][SIZE_OF_MATRIX] = {
        {TABLE(24, 01), TABLE(24, 04), TABLE(24, 03), TABLE(24, 05), TABLE(24, 02)},
        {TABLE(24, 02), TABLE(24, 01), TABLE(24, 04), TABLE(24, 03), TABLE(24, 05)},
        {TABLE(24, 05), TABLE(24, 02), TABLE(24, 01), TABLE(24, 04), TABLE(24, 03)},
        {TABLE(24, 03), TABLE(24, 05), TABLE(24, 02), TABLE(24, 01), TABLE(24, 04)},
        {TABLE(24, 04), TABLE(24, 03), TABLE(24, 05), TABLE(24, 02), TABLE(24, 01)}};

void mix_columns_with_bytes(uint8_t* input)
{
    uint8_t new_values[NUM_OF_BYTES];

    if (MC_DEBUG)
        printf("MC INNER:\n");

    for (int i = 0; i < NUM_OF_BYTES; i++)
    {
        new_values[i] = 0;
        for (int j = 0; j < NUM_OF_BYTES; j++)
        {
            if (MC_DEBUG) printf("%u * %d = %u\n", *(input + j), inner_table[i][j], inner_matrix[i][j][*(input + j)]);
            new_values[i] ^= inner_matrix[i][j][*(input + j)];
        }
    }

    for (int i = 0; i < NUM_OF_BYTES; i++)
    {
        if (MC_DEBUG) printf("%d.: %8u - %8u\n", i, new_values[i], *(input + i));
        *(input + i) = new_values[i];
    }
}

void linear(uint32_t* input, uint32_t*  matrix[SIZE_OF_MATRIX][SIZE_OF_MATRIX])
{
    int i = 0, j;
    uint32_t tmp_value;
    //UINT(N_IN) tmp_value[SIZE_OF_MATRIX];
    uint32_t new_values[SIZE_OF_MATRIX];

    for (i = 0; i < SIZE_OF_MATRIX; i++)
    {
        tmp_value = 0;
        new_values[i] = 0;
        for (j = 0; j < SIZE_OF_MATRIX; j++)
        {
            tmp_value = (MUL(GET_TABLE(matrix, i, j, uint32_t), (BIT24 & (*(input + j))), uint32_t));
            if (MC_DEBUG)
                printf("%u * %d = %u\n", (BIT24 & (*(input + j))), outer_table[i][j], tmp_value);
            new_values[i] ^= (BIT24 & (tmp_value));
        }

        if (MC_DEBUG)
            printf("matrix[%d] : %u \n", i, new_values[i]);

    }

    for (i = 0; i < SIZE_OF_MATRIX; i++)
    {
        *(input + i) = new_values[i];
        if (MC_DEBUG)
            printf("matrix[%d] : %8u - %8u\n", i, new_values[i], *(input + i));
    }

}

void small_block_cipher(uint8_t* in, uint8_t* key)
{
    int i = 0, j = 0, key_index = 0;

    for(i = NUM_OF_BYTES-1; i >= 0; i--)
    {
        if (SBC_DEBUG)
            printf("AK %d: %d ^ %d = %d\n", key_index, *(in + i), key[key_index],  AK(*(in + i), key[key_index]));

        *(in + i) = AK(*(in + i), key[key_index]);
        key_index++;
    }

    for(i = 1; i <= NUM_OF_ROUND; i++)
    {
        if (SBC_DEBUG) printf("SBC round : %d\n", i);

        for(j = NUM_OF_BYTES-1; j >= 0; j--)
        {
            if (SBC_DEBUG) printf("SB: %u - %u\n", *(in + j), SB(*(in + j)));
            *(in + j) = SB(*(in + j));
        }

        mix_columns_with_bytes(in);

        for(j = NUM_OF_BYTES-1; j >= 0; j--)
        {
            if (SBC_DEBUG) printf("AK %d: %d ^ %d = %d\n", key_index, *(in + j), key[key_index],  AK(*(in + j), key[key_index]));
            *(in + j) = AK(*(in + j), key[key_index]);
            key_index++;
        }
        if (SBC_DEBUG) printf("-----------------------------------\n");
    }

}

/*******************   (inv)nonlinear layer of SPNBOX24  **********************/
static void nonlinear(uint8_t* input, uint8_t* extended_key)
{
    if (SBC_DEBUG) printf("Small Block Cipher\n\n");

    for(int j = 0; j < T; j++)
        small_block_cipher(input+j*3, extended_key);
}

static void nonlinear_wb(uint8_t* input)
{
    if (SBC_DEBUG) printf("Small Block Cipher\n\n");

    for(int j = 0; j < T; j++)
        *(input+j) = lookup_table[*(input+j)];
}
/*******************     nonlinear layer of SPNBOX24     **********************/

void encrypt_bb_24(uint8_t* plain_text, uint8_t* extended_key)
{
    for (int r = 0; r < ROUND; r++)
    {
        if (OUTER_DEBUG) printf("OUTER round %d\n", r);

        /**  nonlinear layer  **/
        nonlinear(plain_text, extended_key);

        if (OUTER_DEBUG) printf("Mix Columns Outer\n\n");

        /**  linear layer  **/
        linear(plain_text, omtrx);

        if (OUTER_DEBUG) printf("Add Round Constant\n\n");

        /**  affine layer  **/
        for(int j = 0; j < T; j++)
        {
            if (OUTER_DEBUG) printf("RC: %d ^ %d = %d\n", *(plain_text+j*3), r * T + j + 1, *(plain_text+j*3) ^ (r * T + j + 1));
            *(plain_text+j*3) ^= r * T + j + 1;
        }
    }
}


#endif



