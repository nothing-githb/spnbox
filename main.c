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

    clock_t start = 0, end = 0;
    double cpu_time_used;

    int i = 0;

    uint8_t input[16] = "002345678901234";

    uint8_t master_key[crypto_kdf_KEYBYTES] = "0112233445566778";

    //generate_lookuptable(&master_key);

    //get_looktable_fromfile();

    //uint8_t extended_key[SIZE_OF_KEY];
    uint8_t extended_key[66] = "01234567861123456789012345678901234567890123456789012345678901234";

    //key_schedule(master_key, &extended_key);

    printBytes("key", master_key, 16);

    printBytes("extended key", extended_key, SIZE_OF_KEY);

    printBytes("input", input, 16);

    start = clock();

    while(i++ < TEST_COUNT)
    {
        //encrypt_wb_16(input);
#if N_IN == 8
        encrypt_bb_8(input, extended_key);
#elif N_IN == 16
        encrypt_bb_16(input, extended_key);
#elif N_IN == 24
        encrypt_bb_24(input, extended_key);
#elif N_IN == 32
        encrypt_bb_32(input, extended_key);
#endif
    }

    end = clock();

    printf("%lu - %lu\n", start, end);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Cpu time used : %f\n\n", cpu_time_used);

    i = 0;

    start = clock();

    while(i++ < TEST_COUNT)
    {
        AES_encrypt(ip, out, &AESKey);
    }

    end = clock();

    printf("%lu - %lu\n", start, end);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Cpu time used : %f\n\n", cpu_time_used);

    printBytes("output", input, 16);

    //printf("%d %u\n", 17982 == MUL(GET_TABLE(SPN(N_IN).omtrx, 0, 3, uint16_t), 5286, uint16_t), MUL(GET_TABLE(SPN(N_IN).omtrx, 0, 3, uint16_t), 5286, uint16_t));
    //printf("%d %u\n", 12060 == MUL(GET_TABLE(SPN(N_IN).omtrx, 0, 4, uint16_t), 3450, uint16_t), MUL(GET_TABLE(SPN(N_IN).omtrx, 0, 4, uint16_t), 3450, uint16_t));


    uint8x16_t p_text;
    p_text=vld1q_u8(input);

#ifdef __aarch64__
    printf("__aarch64__\n");
#endif


    double sum = 0;
    double add = 1;
    // Start measuring time
    struct timespec begin, end2;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);

    int iterations = 1000*1000*1000;
    for (int i=0; i<iterations; i++) {
        sum += add;
        add /= 2.0;
    }

    // Stop measuring time and calculate the elapsed time
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end2);
    long seconds = end2.tv_sec - begin.tv_sec;
    long nanoseconds = end2.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;

    printf("Result: %.20f\n", sum);

    printf("Time measured: %.3f seconds.\n", elapsed);

    unsigned long long elapsed2 = seconds*1000000000 + nanoseconds;

    printf("Result: %.20f\n", sum);

    int *STCSR = (int *)0xE000E010;
    int *STRVR = (int *)0xE000E014;
    int *STCVR = (int *)0xE000E018;

    printf("Time measured: %llu seconds.%d\n", elapsed2,  *STCVR - *STCVR - 2);


    return 0;
}
