#ifndef FWCODE_H
#define FWCODE_H

#include <stdint.h>

typedef uint32_t fw_code_t;
typedef uint32_t fw_reg_t;
typedef fw_reg_t fw_addr_t;
typedef uint8_t fw_byte_t;
typedef uint16_t fw_immediate_t;

#define FW_CODE_OP_OFFSET 26
#define FW_CODE_OP_MASK 0xFC000000
#define FW_CODE_IMMEDIATE_OFFSET 10
#define FW_CODE_IMMEDIATE_MASK 0x03FFFC00
#define FW_CODE_RK_OFFSET 10
#define FW_CODE_RK_MASK 0x00007C00
#define FW_CODE_RJ_OFFSET 5
#define FW_CODE_RJ_MASK 0x000003E0
#define FW_CODE_RD_OFFSET 0
#define FW_CODE_RD_MASK 0x0000001F

#define FW_CODE_OP_NOP 0x00
#define FW_CODE_OP_LAND 0x01
#define FW_CODE_OP_LOR 0x02
#define FW_CODE_OP_LNOT 0x03
#define FW_CODE_OP_CMPEQU 0x04
#define FW_CODE_OP_SWAP 0x05
#define FW_CODE_OP_ADDI 0x06
#define FW_CODE_OP_HLT 0x07

#define FW_SR_HLT 0x00000001

fw_code_t fw_code_R(fw_code_t op, fw_reg_t rd, fw_reg_t rj, fw_reg_t rk);
fw_code_t fw_code_I(fw_code_t op, fw_reg_t rd, fw_reg_t rj, fw_immediate_t immediate);

#endif