
#include <config.h>


#if N_IN == 8

#include <spn/spn8.h>
#include <tables/8bit.h>
#include <tables/tables.h>
#include <stdlib.h>
#include <stdio.h>
#include <types.h>
#include <spnbox.h>
#include <sbox.h>
#include <tableMng.h>

#define OUTER_DEBUG 0
#define SBC_DEBUG 0
#define MC_DEBUG 0

#define ROUND                           10
#define SIZE_OF_MATRIX                  16
#define T                               SIZE_OF_MATRIX
#define NUM_OF_ROUND                    64

uint8_t outer_table[SIZE_OF_MATRIX][SIZE_OF_MATRIX] = {
        {0x08,0x16,0x8a,0x01,0x70,0x8d,0x24,0x76,0xa8,0x91,0xad,0x48,0x05,0xb5,0xaf,0xf8},
        {0x16,0x08,0x01,0x8a,0x8d,0x70,0x76,0x24,0x91,0xa8,0x48,0xad,0xb5,0x05,0xf8,0xaf},
        {0x8a,0x01,0x08,0x16,0x24,0x76,0x70,0x8d,0xad,0x48,0xa8,0x91,0xaf,0xf8,0x05,0xb5},
        {0x01,0x8a,0x16,0x08,0x76,0x24,0x8d,0x70,0x48,0xad,0x91,0xa8,0xf8,0xaf,0xb5,0x05},
        {0x70,0x8d,0x24,0x76,0x08,0x16,0x8a,0x01,0x05,0xb5,0xaf,0xf8,0xa8,0x91,0xad,0x48},
        {0x8d,0x70,0x76,0x24,0x16,0x08,0x01,0x8a,0xb5,0x05,0xf8,0xaf,0x91,0xa8,0x48,0xad},
        {0xad,0x48,0xa8,0x91,0xaf,0xf8,0x05,0xb5,0x8a,0x01,0x08,0x16,0x24,0x76,0x70,0x8d},
        {0x48,0xad,0x91,0xa8,0xf8,0xaf,0xb5,0x05,0x01,0x8a,0x16,0x08,0x76,0x24,0x8d,0x70},
        {0x05,0xb5,0xaf,0xf8,0xa8,0x91,0xad,0x48,0x70,0x8d,0x24,0x76,0x08,0x16,0x8a,0x01},
        {0xb5,0x05,0xf8,0xaf,0x91,0xa8,0x48,0xad,0x8d,0x70,0x76,0x24,0x16,0x08,0x01,0x8a},
        {0xaf,0xf8,0x05,0xb5,0xad,0x48,0xa8,0x91,0x24,0x76,0x70,0x8d,0x8a,0x01,0x08,0x16},
        {0xf8,0xaf,0xb5,0x05,0x48,0xad,0x91,0xa8,0x76,0x24,0x8d,0x70,0x01,0x8a,0x16,0x08},
        {0x05,0xb5,0xaf,0xf8,0xa8,0x91,0xad,0x48,0x70,0x8d,0x24,0x76,0x08,0x16,0x8a,0x01},
        {0xb5,0x05,0xf8,0xaf,0x91,0xa8,0x48,0xad,0x8d,0x70,0x76,0x24,0x16,0x08,0x01,0x8a},
        {0xad,0x48,0xa8,0x91,0xaf,0xf8,0x05,0xb5,0x8a,0x01,0x08,0x16,0x24,0x76,0x70,0x8d},
        {0x48,0xad,0x91,0xa8,0xf8,0xaf,0xb5,0x05,0x01,0x8a,0x16,0x08,0x76,0x24,0x8d,0x70}};

const uint8_t* omtrx[SIZE_OF_MATRIX][SIZE_OF_MATRIX] = {
        {TABLE(8, 08),TABLE(8, 16),TABLE(8, 8a),TABLE(8, 01),TABLE(8, 70),TABLE(8, 8d),TABLE(8, 24),TABLE(8, 76),TABLE(8, a8),TABLE(8, 91),TABLE(8, ad),TABLE(8, 48),TABLE(8, 05),TABLE(8, b5),TABLE(8, af),TABLE(8, f8)},
        {TABLE(8, 16),TABLE(8, 08),TABLE(8, 01),TABLE(8, 8a),TABLE(8, 8d),TABLE(8, 70),TABLE(8, 76),TABLE(8, 24),TABLE(8, 91),TABLE(8, a8),TABLE(8, 48),TABLE(8, ad),TABLE(8, b5),TABLE(8, 05),TABLE(8, f8),TABLE(8, af)},
        {TABLE(8, 8a),TABLE(8, 01),TABLE(8, 08),TABLE(8, 16),TABLE(8, 24),TABLE(8, 76),TABLE(8, 70),TABLE(8, 8d),TABLE(8, ad),TABLE(8, 48),TABLE(8, a8),TABLE(8, 91),TABLE(8, af),TABLE(8, f8),TABLE(8, 05),TABLE(8, b5)},
        {TABLE(8, 01),TABLE(8, 8a),TABLE(8, 16),TABLE(8, 08),TABLE(8, 76),TABLE(8, 24),TABLE(8, 8d),TABLE(8, 70),TABLE(8, 48),TABLE(8, ad),TABLE(8, 91),TABLE(8, a8),TABLE(8, f8),TABLE(8, af),TABLE(8, b5),TABLE(8, 05)},
        {TABLE(8, 70),TABLE(8, 8d),TABLE(8, 24),TABLE(8, 76),TABLE(8, 08),TABLE(8, 16),TABLE(8, 8a),TABLE(8, 01),TABLE(8, 05),TABLE(8, b5),TABLE(8, af),TABLE(8, f8),TABLE(8, a8),TABLE(8, 91),TABLE(8, ad),TABLE(8, 48)},
        {TABLE(8, 8d),TABLE(8, 70),TABLE(8, 76),TABLE(8, 24),TABLE(8, 16),TABLE(8, 08),TABLE(8, 01),TABLE(8, 8a),TABLE(8, b5),TABLE(8, 05),TABLE(8, f8),TABLE(8, af),TABLE(8, 91),TABLE(8, a8),TABLE(8, 48),TABLE(8, ad)},
        {TABLE(8, ad),TABLE(8, 48),TABLE(8, a8),TABLE(8, 91),TABLE(8, af),TABLE(8, f8),TABLE(8, 05),TABLE(8, b5),TABLE(8, 8a),TABLE(8, 01),TABLE(8, 08),TABLE(8, 16),TABLE(8, 24),TABLE(8, 76),TABLE(8, 70),TABLE(8, 8d)},
        {TABLE(8, 48),TABLE(8, ad),TABLE(8, 91),TABLE(8, a8),TABLE(8, f8),TABLE(8, af),TABLE(8, b5),TABLE(8, 05),TABLE(8, 01),TABLE(8, 8a),TABLE(8, 16),TABLE(8, 08),TABLE(8, 76),TABLE(8, 24),TABLE(8, 8d),TABLE(8, 70)},
        {TABLE(8, 05),TABLE(8, b5),TABLE(8, af),TABLE(8, f8),TABLE(8, a8),TABLE(8, 91),TABLE(8, ad),TABLE(8, 48),TABLE(8, 70),TABLE(8, 8d),TABLE(8, 24),TABLE(8, 76),TABLE(8, 08),TABLE(8, 16),TABLE(8, 8a),TABLE(8, 01)},
        {TABLE(8, b5),TABLE(8, 05),TABLE(8, f8),TABLE(8, af),TABLE(8, 91),TABLE(8, a8),TABLE(8, 48),TABLE(8, ad),TABLE(8, 8d),TABLE(8, 70),TABLE(8, 76),TABLE(8, 24),TABLE(8, 16),TABLE(8, 08),TABLE(8, 01),TABLE(8, 8a)},
        {TABLE(8, af),TABLE(8, f8),TABLE(8, 05),TABLE(8, b5),TABLE(8, ad),TABLE(8, 48),TABLE(8, a8),TABLE(8, 91),TABLE(8, 24),TABLE(8, 76),TABLE(8, 70),TABLE(8, 8d),TABLE(8, 8a),TABLE(8, 01),TABLE(8, 08),TABLE(8, 16)},
        {TABLE(8, f8),TABLE(8, af),TABLE(8, b5),TABLE(8, 05),TABLE(8, 48),TABLE(8, ad),TABLE(8, 91),TABLE(8, a8),TABLE(8, 76),TABLE(8, 24),TABLE(8, 8d),TABLE(8, 70),TABLE(8, 01),TABLE(8, 8a),TABLE(8, 16),TABLE(8, 08)},
        {TABLE(8, 05),TABLE(8, b5),TABLE(8, af),TABLE(8, f8),TABLE(8, a8),TABLE(8, 91),TABLE(8, ad),TABLE(8, 48),TABLE(8, 70),TABLE(8, 8d),TABLE(8, 24),TABLE(8, 76),TABLE(8, 08),TABLE(8, 16),TABLE(8, 8a),TABLE(8, 01)},
        {TABLE(8, b5),TABLE(8, 05),TABLE(8, f8),TABLE(8, af),TABLE(8, 91),TABLE(8, a8),TABLE(8, 48),TABLE(8, ad),TABLE(8, 8d),TABLE(8, 70),TABLE(8, 76),TABLE(8, 24),TABLE(8, 16),TABLE(8, 08),TABLE(8, 01),TABLE(8, 8a)},
        {TABLE(8, ad),TABLE(8, 48),TABLE(8, a8),TABLE(8, 91),TABLE(8, af),TABLE(8, f8),TABLE(8, 05),TABLE(8, b5),TABLE(8, 8a),TABLE(8, 01),TABLE(8, 08),TABLE(8, 16),TABLE(8, 24),TABLE(8, 76),TABLE(8, 70),TABLE(8, 8d)},
        {TABLE(8, 48),TABLE(8, ad),TABLE(8, 91),TABLE(8, a8),TABLE(8, f8),TABLE(8, af),TABLE(8, b5),TABLE(8, 05),TABLE(8, 01),TABLE(8, 8a),TABLE(8, 16),TABLE(8, 08),TABLE(8, 76),TABLE(8, 24),TABLE(8, 8d),TABLE(8, 70)}};


void linear(uint8_t* input, uint8_t*  matrix[SIZE_OF_MATRIX][SIZE_OF_MATRIX])
{
    int i = 0, j;
    uint8_t tmp_value;
    //UINT(N_IN) tmp_value[SIZE_OF_MATRIX];
    uint8_t new_values[SIZE_OF_MATRIX];

    for (i = 0; i < SIZE_OF_MATRIX; i++)
    {
        tmp_value = 0;
        new_values[i] = 0;
        for (j = 0; j < SIZE_OF_MATRIX; j++)
        {
            tmp_value = (MUL(GET_TABLE(matrix, i, j, UINT(N_IN)), *(input + j), UINT(N_IN)));
            if (MC_DEBUG)
                printf("%u * %d = %u\n", *(input + j), outer_table[i][j], tmp_value);
            new_values[i] ^= tmp_value;
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

        // Nothing

        for(j = NUM_OF_BYTES-1; j >= 0; j--)
        {
            if (SBC_DEBUG) printf("AK %d: %d ^ %d = %d\n", key_index, *(in + j), key[key_index],  AK(*(in + j), key[key_index]));
            *(in + j) = AK(*(in + j), key[key_index]);
            key_index++;
        }
        if (SBC_DEBUG) printf("-----------------------------------\n");
    }

}

/*******************   (inv)nonlinear layer of SPNBOX16  ****************************/
static void nonlinear(uint8_t* input, uint8_t* extended_key)
{
    if (SBC_DEBUG) printf("Small Block Cipher\n\n");

    for(int j = 0; j < T; j++)
        small_block_cipher(input+j, extended_key);
}

static void nonlinear_wb(uint8_t* input)
{
    if (SBC_DEBUG) printf("Small Block Cipher\n\n");

    for(int j = 0; j < T; j++)
        *(input+j) = lookup_table[*(input+j)];
}
/*******************     nonlinear layer of SPNBOX16     **********************/

void encrypt_bb_8(uint8_t* plain_text, uint8_t* extended_key)
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
            if (OUTER_DEBUG) printf("RC: %d ^ %d = %d\n", *(plain_text+j), r * T + j + 1, *(plain_text+j) ^ (r * T + j + 1));
            *(plain_text+j) ^= r * T + j + 1;
        }
    }
}

void encrypt_wb_8(uint8_t* plain_text)
{
    for (int r = 0; r < ROUND; r++)
    {
        if (OUTER_DEBUG) printf("OUTER round %d\n", r);

        /**  nonlinear layer  **/
        nonlinear_wb(plain_text);

        if (OUTER_DEBUG) printf("Mix Columns Outer\n\n");

        /**  linear layer  **/
        linear(plain_text, omtrx);

        if (OUTER_DEBUG) printf("Add Round Constant\n\n");

        /**  affine layer  **/
        for(int j = 0; j < T; j++)
        {
            if (OUTER_DEBUG) printf("RC: %d ^ %d = %d\n", *(plain_text+j), r * T + j + 1, *(plain_text+j) ^ (r * T + j + 1));
            *(plain_text+j) ^= r * T + j + 1;
        }
    }
}

#endif