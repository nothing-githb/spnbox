//
// Created by Halis Şahin on 27.01.2022.
//

#include <gmp.h>        /* GNU multiprecision library */
#include <config.h>
#include <spnbox.h>
#include <helper.h>
#include <string.h>     /* memset */
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sodium.h>
#include <tableMng.h>

static const char* filename = "lookuptable.txt";

uint16_t lookup_table[1<<N_IN];

void get_looktable_fromfile()
{
    int i = 0;

    FILE* file = fopen(filename, "rb");

    if (!file)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while(i < (1<<N_IN))
    {
        fread(&lookup_table[i], NUM_OF_BYTES, 1, file);
        i++;
    }

    fclose(file);
}

void increment_bytes(unsigned char *bytes, const int size, const unsigned long long count)
{
    mpz_t bytes_to_value;

    // Calculate message hash value
    mpz_init(bytes_to_value);
    mpz_import(bytes_to_value, 1, 1, size, 0, 0, bytes);

    if (LT_DEBUG)
        gmp_printf("inc: Initial value: %Zd \n", bytes_to_value);

    mpz_add_ui(bytes_to_value, bytes_to_value, count);

    if (LT_DEBUG)
        gmp_printf("inc: Incremented value: %Zd \n", bytes_to_value);

    // mpz_export (void *rop, size_t *countp, int order, size_t size, int endian, size_t nails, const mpz_t op)
    mpz_export(bytes, NULL, 1, size, 0, 0, bytes_to_value);

    mpz_clear(bytes_to_value);
}

unsigned long get_value_of_byte(unsigned char *bytes, const int size)
{
    unsigned long value = 0;
    mpz_t bytes_to_value;

    mpz_init(bytes_to_value);
    mpz_import(bytes_to_value, 1, 1, size, 0, 0, bytes);

    value = mpz_get_ui(bytes_to_value);

    mpz_clear(bytes_to_value);

    return value;
}
#define CONTEXT "Examples"

void key_schedule(uint8_t* key, uint8_t* output)
{
    uint8_t subkey[SIZE_OF_KEY];
    uint8_t subkey1[16];

    memset(subkey, 0x00, SIZE_OF_KEY);

    crypto_kdf_derive_from_key(subkey, 64, 1, CONTEXT, key);
    crypto_kdf_derive_from_key(subkey1, sizeof(subkey1), 2, CONTEXT, key);
    memcpy(subkey+64, subkey1, NUM_OF_BYTES);

    if (KC_DEBUG)
        printBytes("last key", subkey, SIZE_OF_KEY);

    memcpy(output, subkey, SIZE_OF_KEY);
}

void generate_lookuptable(uint8_t* master_key)
{
    uint64_t i = 0;
    uint8_t  input[NUM_OF_BYTES];
    uint8_t  output[NUM_OF_BYTES];

    uint8_t  extended_key[SIZE_OF_KEY];
    FILE*    output_file = NULL;

    printf("Table generation\n");

    memset(input, 0x00, NUM_OF_BYTES);
    memset(output, 0x00, NUM_OF_BYTES);

    key_schedule(master_key, &extended_key);

    output_file = fopen(filename, "wb+");

    if (!output_file)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while(i++ < (1<<N_IN))
    {
        //printf("%d %d --> ", *(input), *(input+1));
        small_block_cipher(input, extended_key);
        //printf("%d %d\n", *(input), *(input+1));

        fwrite(input, NUM_OF_BYTES, 1, output_file);
        increment_bytes(output, NUM_OF_BYTES, 1);
        memcpy(input, output, 2);
    }

    fclose(output_file);
}
