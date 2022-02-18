//
// Created by Halis Şahin on 21.09.2021.
//

#include <stdio.h>
#include <helper.h>

// TODO optimize, change with table instead of bit shifting
static inline void changeBitOfByte(ADDR base, const unsigned int byte, const unsigned int bit)
{
    int *number = (int *)(&base[byte]);
    printf("byte %d bit  %d : %d --> ", byte, bit, BIT_CHECK(number, bit));
    if (BIT_CHECK(number, bit)) BIT_CLEAR(number, bit);
    else    BIT_SET(number, bit);
    printf("%d\n\r", BIT_CHECK(number, bit));
}

inline void getNumFromUser(const char *msg, int *num)
{
    printf("%s", msg);
    scanf("%d",num);
}

void printBytes(const char *msg, ADDR addr, int length)
{
    int i;
    printf("----%s---", msg);
    for (i = 0; i < length; i++)
    {
        if (i % 20 == 0)
            printf("\n");
        printf("%4d ", ((unsigned char *)addr)[i]);
    }
    printf("\n\n");
}

void change_bit_service(ADDR data, int data_byte, char * msg)
{
    int byte, bit;
    printBytes(msg, data, data_byte);
    getNumFromUser("Get nth byte for change:", &byte);
    getNumFromUser("Get nth bit for change: ", &bit);
    changeBitOfByte(data, byte, bit);    // Change bit
    printBytes(msg, data, data_byte);
}

void gmix_column(unsigned char *r)
{
    unsigned char a[4];
    unsigned char b[4];
    unsigned char c;
    unsigned char h;
    /* The array 'a' is simply a copy of the input array 'r'
     * The array 'b' is each element of the array 'a' multiplied by 2
     * in Rijndael's Galois field
     * a[n] ^ b[n] is element n multiplied by 3 in Rijndael's Galois field */
    for (c = 0; c < 4; c++)
    {
        a[c] = r[c];
        /* h is 0xff if the high bit of r[c] is set, 0 otherwise */
        h = (r[c] >> 7) & 1; /* arithmetic right shift, thus shifting in either zeros or ones */
        b[c] = r[c] << 1; /* implicitly removes high bit because b[c] is an 8-bit char, so we xor by 0x1b and not 0x11b in the next line */
        b[c] ^= h * 0x1B; /* Rijndael's Galois field */
    }

    r[0] = b[0] ^ a[3] ^ a[2] ^ b[1] ^ a[1]; /* 2 * a0 + a3 + a2 + 3 * a1 */
    r[1] = b[1] ^ a[0] ^ a[3] ^ b[2] ^ a[2]; /* 2 * a1 + a0 + a3 + 3 * a2 */
    r[2] = b[2] ^ a[1] ^ a[0] ^ b[3] ^ a[3]; /* 2 * a2 + a1 + a0 + 3 * a3 */
    r[3] = b[3] ^ a[2] ^ a[1] ^ b[0] ^ a[0]; /* 2 * a3 + a2 + a1 + 3 * a0 */
}
