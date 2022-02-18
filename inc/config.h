//
// Created by Halis Şahin on 9.01.2022.
//

#ifndef SPNBOX_CONFIG_H
#define SPNBOX_CONFIG_H

#define CONCAT_UINT(p)      uint##p##_t
#define UINT(p)             CONCAT_UINT(p)

#define N_IN                16
#define NUM_OF_BYTES        (N_IN/8)

#define SBC_DEBUG           0
#define MC_DEBUG            0
#define KC_DEBUG            0
#define OUTER_DEBUG         0
#define LT_DEBUG            0

#endif //SPNBOX_CONFIG_H
