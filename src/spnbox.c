
/**
#define RC_0  (0x0004000300020001ULL)
#define RC_1  (0x0008000700060005ULL)
#define RC_2  (0x000c000b000a0009ULL)
#define RC_3  (0x0010000f000e000dULL)
#define RC_4  (0x0014001300120011ULL)
#define RC_5  (0x0018001700160015ULL)
#define RC_6  (0x001c001b001a0019ULL)
#define RC_7  (0x0020001f001e001dULL)
#define RC_8  (0x0024002300220021ULL)
#define RC_9  (0x0028002700260025ULL)
#define RC_10 (0x002c002b002a0029ULL)
#define RC_11 (0x0030002f002e002dULL)
#define RC_12 (0x0034003300320031ULL)
#define RC_13 (0x0038003700360035ULL)
#define RC_14 (0x003c003b003a0039ULL)
#define RC_15 (0x0040003f003e003dULL)
#define RC_16 (0x0044004300420041ULL)
#define RC_17 (0x0048004700460045ULL)
#define RC_18 (0x004c004b004a0049ULL)
#define RC_19 (0x0050004f004e004dULL)


//#define MUL_LINE(p) (omtrx[p][0][*x0] ^ omtrx[p][1][*x1] ^ omtrx[p][2][*x2] ^ omtrx[p][3][*x3] ^ omtrx[p][4][*x4] ^ omtrx[p][5][*x5] ^ omtrx[p][6][*x6] ^ omtrx[p][7][*x7])

#define MUL_L0 (*x0 ^ T_16(03)[*x1] ^ T_16(04)[*x2] ^ T_16(05)[*x3] ^ T_16(06)[*x4] ^ T_16(08)[*x5] ^ T_16(0b)[*x6] ^ T_16(07)[*x7])
#define MUL_L1 (T_16(03)[*x0] ^ *x1 ^ T_16(05)[*x2] ^ T_16(04)[*x3] ^ T_16(08)[*x4] ^ T_16(06)[*x5] ^ T_16(07)[*x6] ^ T_16(0b)[*x7])
#define MUL_L2 (T_16(04)[*x0] ^ T_16(05)[*x1] ^ *x2 ^ T_16(03)[*x3] ^ T_16(0b)[*x4] ^ T_16(07)[*x5] ^ T_16(06)[*x6] ^ T_16(08)[*x7])
#define MUL_L3 (T_16(05)[*x0] ^ T_16(04)[*x1] ^ T_16(03)[*x2] ^ *x3 ^ T_16(07)[*x4] ^ T_16(0b)[*x5] ^ T_16(08)[*x6] ^ T_16(06)[*x7])
#define MUL_L4 (T_16(06)[*x0] ^ T_16(08)[*x1] ^ T_16(0b)[*x2] ^ T_16(07)[*x3] ^ *x4 ^ T_16(03)[*x5] ^ T_16(04)[*x6] ^ T_16(05)[*x7])
#define MUL_L5 (T_16(08)[*x0] ^ T_16(06)[*x1] ^ T_16(07)[*x2] ^ T_16(0b)[*x3] ^ T_16(03)[*x4] ^ *x5 ^ T_16(05)[*x6] ^ T_16(04)[*x7])
#define MUL_L6 (T_16(0b)[*x0] ^ T_16(07)[*x1] ^ T_16(06)[*x2] ^ T_16(08)[*x3] ^ T_16(04)[*x4] ^ T_16(05)[*x5] ^ *x6 ^ T_16(03)[*x7])
#define MUL_L7 (T_16(07)[*x0] ^ T_16(0b)[*x1] ^ T_16(08)[*x2] ^ T_16(06)[*x3] ^ T_16(05)[*x4] ^ T_16(04)[*x5] ^ T_16(03)[*x6] ^ *x7)

static uint16_t values[SIZE_OF_MATRIX];
static uint16_t* val_0 = &values[0];
static uint16_t* val_1 = &values[1];
static uint16_t* val_2 = &values[2];
static uint16_t* val_3 = &values[3];
static uint16_t* val_4 = &values[4];
static uint16_t* val_5 = &values[5];
static uint16_t* val_6 = &values[6];
static uint16_t* val_7 = &values[7];

static uint16_t* x0 = NULL;
static uint16_t* x1 = NULL;
static uint16_t* x2 = NULL;
static uint16_t* x3 = NULL;
static uint16_t* x4 = NULL;
static uint16_t* x5 = NULL;
static uint16_t* x6 = NULL;
static uint16_t* x7 = NULL;

void encrypt_wb_16(uint16_t* plain_text)
{
    x0 = plain_text;
    x1 = plain_text+1;
    x2 = plain_text+2;
    x3 = plain_text+3;
    x4 = plain_text+4;
    x5 = plain_text+5;
    x6 = plain_text+6;
    x7 = plain_text+7;

    *x0 = WBT(x0); *x1 = WBT(x1); *x2 = WBT(x2); *x3 = WBT(x3); *x4 = WBT(x4); *x5 = WBT(x5); *x6 = WBT(x6); *x7 = WBT(x7);

    *val_0 = MUL_L0; *val_1 = MUL_L1; *val_2 = MUL_L2; *val_3 = MUL_L3; *val_4 = MUL_L4; *val_5 = MUL_L5; *val_6 = MUL_L6; *val_7 = MUL_L7;

    *((uint64_t *)x0) = *((uint64_t*)val_0);
    *((uint64_t *)x4) = *((uint64_t*)val_4);

    *((uint64_t *)x0) ^= RC_0;
    *((uint64_t *)x4) ^= RC_1;

    *x0 = WBT(x0); *x1 = WBT(x1); *x2 = WBT(x2); *x3 = WBT(x3); *x4 = WBT(x4); *x5 = WBT(x5); *x6 = WBT(x6); *x7 = WBT(x7);

    *val_0 = MUL_L0; *val_1 = MUL_L1; *val_2 = MUL_L2; *val_3 = MUL_L3; *val_4 = MUL_L4; *val_5 = MUL_L5; *val_6 = MUL_L6; *val_7 = MUL_L7;

    *((uint64_t *)x0) = *((uint64_t*)val_0);
    *((uint64_t *)x4) = *((uint64_t*)val_4);

    *((uint64_t *)x0) ^= RC_2;
    *((uint64_t *)x4) ^= RC_3;

    *x0 = WBT(x0); *x1 = WBT(x1); *x2 = WBT(x2); *x3 = WBT(x3); *x4 = WBT(x4); *x5 = WBT(x5); *x6 = WBT(x6); *x7 = WBT(x7);

    *val_0 = MUL_L0; *val_1 = MUL_L1; *val_2 = MUL_L2; *val_3 = MUL_L3; *val_4 = MUL_L4; *val_5 = MUL_L5; *val_6 = MUL_L6; *val_7 = MUL_L7;

    *((uint64_t *)x0) = *((uint64_t*)val_0);
    *((uint64_t *)x4) = *((uint64_t*)val_4);

    *((uint64_t *)x0) ^= RC_4;
    *((uint64_t *)x4) ^= RC_5;

    *x0 = WBT(x0); *x1 = WBT(x1); *x2 = WBT(x2); *x3 = WBT(x3); *x4 = WBT(x4); *x5 = WBT(x5); *x6 = WBT(x6); *x7 = WBT(x7);

    *val_0 = MUL_L0; *val_1 = MUL_L1; *val_2 = MUL_L2; *val_3 = MUL_L3; *val_4 = MUL_L4; *val_5 = MUL_L5; *val_6 = MUL_L6; *val_7 = MUL_L7;

    *((uint64_t *)x0) = *((uint64_t*)val_0);
    *((uint64_t *)x4) = *((uint64_t*)val_4);

    *((uint64_t *)x0) ^= RC_6;
    *((uint64_t *)x4) ^= RC_7;

    *x0 = WBT(x0); *x1 = WBT(x1); *x2 = WBT(x2); *x3 = WBT(x3); *x4 = WBT(x4); *x5 = WBT(x5); *x6 = WBT(x6); *x7 = WBT(x7);

    *val_0 = MUL_L0; *val_1 = MUL_L1; *val_2 = MUL_L2; *val_3 = MUL_L3; *val_4 = MUL_L4; *val_5 = MUL_L5; *val_6 = MUL_L6; *val_7 = MUL_L7;

    *((uint64_t *)x0) = *((uint64_t*)val_0);
    *((uint64_t *)x4) = *((uint64_t*)val_4);

    *((uint64_t *)x0) ^= RC_8;
    *((uint64_t *)x4) ^= RC_9;

    *x0 = WBT(x0); *x1 = WBT(x1); *x2 = WBT(x2); *x3 = WBT(x3); *x4 = WBT(x4); *x5 = WBT(x5); *x6 = WBT(x6); *x7 = WBT(x7);

    *val_0 = MUL_L0; *val_1 = MUL_L1; *val_2 = MUL_L2; *val_3 = MUL_L3; *val_4 = MUL_L4; *val_5 = MUL_L5; *val_6 = MUL_L6; *val_7 = MUL_L7;

    *((uint64_t *)x0) = *((uint64_t*)val_0);
    *((uint64_t *)x4) = *((uint64_t*)val_4);

    *((uint64_t *)x0) ^= RC_10;
    *((uint64_t *)x4) ^= RC_11;

    *x0 = WBT(x0); *x1 = WBT(x1); *x2 = WBT(x2); *x3 = WBT(x3); *x4 = WBT(x4); *x5 = WBT(x5); *x6 = WBT(x6); *x7 = WBT(x7);

    *val_0 = MUL_L0; *val_1 = MUL_L1; *val_2 = MUL_L2; *val_3 = MUL_L3; *val_4 = MUL_L4; *val_5 = MUL_L5; *val_6 = MUL_L6; *val_7 = MUL_L7;

    *((uint64_t *)x0) = *((uint64_t*)val_0);
    *((uint64_t *)x4) = *((uint64_t*)val_4);

    *((uint64_t *)x0) ^= RC_12;
    *((uint64_t *)x4) ^= RC_13;

    *x0 = WBT(x0); *x1 = WBT(x1); *x2 = WBT(x2); *x3 = WBT(x3); *x4 = WBT(x4); *x5 = WBT(x5); *x6 = WBT(x6); *x7 = WBT(x7);

    *val_0 = MUL_L0; *val_1 = MUL_L1; *val_2 = MUL_L2; *val_3 = MUL_L3; *val_4 = MUL_L4; *val_5 = MUL_L5; *val_6 = MUL_L6; *val_7 = MUL_L7;

    *((uint64_t *)x0) = *((uint64_t*)val_0);
    *((uint64_t *)x4) = *((uint64_t*)val_4);

    *((uint64_t *)x0) ^= RC_14;
    *((uint64_t *)x4) ^= RC_15;

    *x0 = WBT(x0); *x1 = WBT(x1); *x2 = WBT(x2); *x3 = WBT(x3); *x4 = WBT(x4); *x5 = WBT(x5); *x6 = WBT(x6); *x7 = WBT(x7);

    *val_0 = MUL_L0; *val_1 = MUL_L1; *val_2 = MUL_L2; *val_3 = MUL_L3; *val_4 = MUL_L4; *val_5 = MUL_L5; *val_6 = MUL_L6; *val_7 = MUL_L7;

    *((uint64_t *)x0) = *((uint64_t*)val_0);
    *((uint64_t *)x4) = *((uint64_t*)val_4);

    *((uint64_t *)x0) ^= RC_16;
    *((uint64_t *)x4) ^= RC_17;

    *x0 = WBT(x0); *x1 = WBT(x1); *x2 = WBT(x2); *x3 = WBT(x3); *x4 = WBT(x4); *x5 = WBT(x5); *x6 = WBT(x6); *x7 = WBT(x7);

    *val_0 = MUL_L0; *val_1 = MUL_L1; *val_2 = MUL_L2; *val_3 = MUL_L3; *val_4 = MUL_L4; *val_5 = MUL_L5; *val_6 = MUL_L6; *val_7 = MUL_L7;

    *((uint64_t *)x0) = *((uint64_t*)val_0);
    *((uint64_t *)x4) = *((uint64_t*)val_4);

    *((uint64_t *)x0) ^= RC_18;
    *((uint64_t *)x4) ^= RC_19;
}
*/
