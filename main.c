#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sodium.h>
#include <time.h>

#include "helper.h"
#include "config.h"
#include "sbox.h"
#include <time.h>
#include <spnbox.h>
#include <tables/tables.h>
#include <tableMng.h>
#include <arm_neon.h>
#include <spn/spn32.h>
#include <spn/spn24.h>
#include <spn/spn16.h>
#include <spn/spn8.h>
#include <unistd.h>

#define INIT_SODIUM do{ if (sodium_init() < 0) printf("Sodium initialization failed \n\r"); }while(0)

#include <stdint.h>     //for int8_t

#define TEST_COUNT 1

#define mul16_5_3 100

#define __CONCAT(hex, x, y)   (mul##hex##_##x##_##y)
#define xx(k, x,y) __CONCAT(k, x, y)
#define cc(k, x,y) xx(k, x, y)

#define STR_IMPL_(x) #x      //stringify argument
#define STR(x) STR_IMPL_(x)

#if defined(__x86_64__)
#ifdef __GNUC__
#include <x86intrin.h>
#endif
#ifdef _MSC_VER_
#include <intrin.h>
#endif
#pragma intrinsic(__rdtsc)

uint64_t get_rdtsc()
{
    return __rdtsc();
}
#endif

int main()
{
    INIT_SODIUM;

    AES_KEY AESKey; // FIXME must be removed
    unsigned char ip[16], out[16], key[16];
    // FIXME there is no need the key in new WBT-Ek
    randombytes_buf(key, 16);   // Generate random key
    AES_set_encrypt_key(&key, 128, &AESKey);    // Set AES encryption key

    memset(ip, 0x01, 16);
    memset(out, 0x01, 16);

    uint64_t start = 0, end = 0;

    double cpu_time_used;

    int i = 0;

    uint8_t input[16] = "002345678901234";

    uint8_t master_key[crypto_kdf_KEYBYTES] = "0112233445566778";

    generate_lookuptable(&master_key);

    get_looktable_fromfile();

    //uint8_t extended_key[SIZE_OF_KEY];
    uint8_t extended_key[66] = "01234567861123456789012345678901234567890123456789012345678901234";

    //key_schedule(master_key, &extended_key);

    printBytes("key", master_key, 16);

    printBytes("extended key", extended_key, SIZE_OF_KEY);

    printBytes("input", input, 16);

#if defined(__x86_64__)
    start = get_rdtsc;
#else
    start = clock();
#endif

    while(i++ < TEST_COUNT)
    {
#if N_IN == 8

#if WB_TEST == 1
        encrypt_wb_8(input);
#else
        encrypt_bb_8(input, extended_key);
#endif

#elif N_IN == 16

#if WB_TEST == 1
        encrypt_wb_16(input);
#else
        encrypt_bb_16(input, extended_key);
#endif

#elif N_IN == 24

#if WB_TEST == 1
        encrypt_wb_24(input);
#else
        encrypt_bb_24(input, extended_key);
#endif

#elif N_IN == 32

#if WB_TEST == 1
        encrypt_bb_32(input);
#else
        encrypt_bb_32(input, extended_key);
#endif

#endif
    }

#if defined(__x86_64__)
    end = get_rdtsc;
#else
    end = clock();
#endif
    printBytes("output", input, 16);

    printf("start : %llu \nend : %llu \ndiff : %llu\n", start, end, end - start);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Cpu time used : %f\n\n", cpu_time_used);

    i = 0;

    start = clock();

    while(i++ < TEST_COUNT)
    {
        AES_encrypt(ip, out, &AESKey);
    }

    end = clock();

    printf("start : %llu \nend : %llu \ndiff : %llu\n", start, end, end - start);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Cpu time used : %f\n\n", cpu_time_used);


    //printf("%d %u\n", 17982 == MUL(GET_TABLE(SPN(N_IN).omtrx, 0, 3, uint16_t), 5286, uint16_t), MUL(GET_TABLE(SPN(N_IN).omtrx, 0, 3, uint16_t), 5286, uint16_t));
    //printf("%d %u\n", 12060 == MUL(GET_TABLE(SPN(N_IN).omtrx, 0, 4, uint16_t), 3450, uint16_t), MUL(GET_TABLE(SPN(N_IN).omtrx, 0, 4, uint16_t), 3450, uint16_t));

    return 0;
}
