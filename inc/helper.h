//
// Created by Halis Şahin on 21.09.2021.
//

#ifndef MCS_HELPER_H
#define MCS_HELPER_H

#include <types.h>

#define XOR(a,b)                ((a) ^ (b))

/* Concatenate strings */
#define CONCAT(a, b)            (a ## b)

void getNumFromUser(const char *msg, int *num);

void printBytes(const char *msg, ADDR addr, int length);

void change_bit_service(ADDR data, int data_byte, char * msg);

void gmix_column(unsigned char *r);

#endif //MCS_HELPER_H
