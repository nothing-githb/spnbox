//
// Created by Halis Şahin on 27.01.2022.
//

#ifndef SPNBOX_TABLEMNG_H
#define SPNBOX_TABLEMNG_H

#include <config.h>

/**
 * input must be uint16_t
 */
#define WBT(input)        (lookup_table[*(input)])

#if 8 == N_IN
extern uint8_t lookup_table[1<<N_IN];
#elif 16 == N_IN
extern uint16_t lookup_table[1<<N_IN];
#elif 24 == N_IN
extern uint32_t lookup_table[1<<N_IN];
#elif 32 == N_IN
extern uint32_t lookup_table[1<<N_IN];
#endif

void generate_lookuptable(uint8_t* master_key);

void get_data_from_lookup_table(uint16_t* input);

void get_looktable_fromfile();

void small_block_cipher(uint8_t* in, uint8_t* key);

#endif //SPNBOX_TABLEMNG_H
