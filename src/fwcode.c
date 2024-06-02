#include "fwcode.h"

fw_code_t fw_code_R(fw_code_t op, fw_reg_t rd, fw_reg_t rj, fw_reg_t rk)
{
    return (op << FW_CODE_OP_OFFSET) & FW_CODE_OP_MASK | (rd << FW_CODE_RD_OFFSET) & FW_CODE_RD_MASK | (rj << FW_CODE_RJ_OFFSET) & FW_CODE_RJ_MASK | (rk << FW_CODE_RK_OFFSET) & FW_CODE_RK_MASK;
}
fw_code_t fw_code_I(fw_code_t op, fw_reg_t rd, fw_reg_t rj, fw_immediate_t immediate)
{
    return (op << FW_CODE_OP_OFFSET) & FW_CODE_OP_MASK | (rd << FW_CODE_RD_OFFSET) & FW_CODE_RD_MASK | (rj << FW_CODE_RJ_OFFSET) & FW_CODE_RJ_MASK | (immediate << FW_CODE_IMMEDIATE_OFFSET) & FW_CODE_IMMEDIATE_MASK;
}
