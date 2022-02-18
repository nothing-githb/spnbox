//
// Created by Halis Şahin on 26.01.2022.
//

#ifndef SPNBOX_SPNBOX_H
#define SPNBOX_SPNBOX_H

#include <stdlib.h>
#include <helper.h>

/* p XOR k */
#define AK(p, k)                (XOR(p, k))

/* Gets small block cipher struct variables with given Nin nits*/
#define SPN(p)                  (CONCAT(spn_, p))



typedef struct{
    int num_of_bytes;
    int num_of_round;
    int size_of_key;
    int** inner_table;
    int** outer_table;
    ADDR** inner_matrix;
    ADDR** outer_matrix;
} spn_t;

extern const spn_t spn_8;

extern const spn_t spn_16;

//extern const sbc_t sbc_24;

//extern const sbc_t sbc_32;

#define SIZE_OF_KEY                     66

void small_block_cipher(uint8_t* in, uint8_t* key);


#endif //SPNBOX_SPNBOX_H
