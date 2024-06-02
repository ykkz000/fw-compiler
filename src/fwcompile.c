#include "fwcompile.h"
#include "fwcode.h"

size_t fw_rule_begin(FILE *file)
{
    fw_code_t code;
    size_t size;

    size = 0;
    /*
     * Empty the single rule result register.
    */
    code = fw_code_R(FW_CODE_OP_LAND, FW_SINGLE_RULE_RESULT_REG, FW_ZERO_REG, FW_ZERO_REG);
    size += fwrite(&code, sizeof(code), 1, file);
    return size;
}
size_t fw_saddr_ipv4(FILE *file, uint32_t saddr_ipv4)
{
    fw_code_t code;
    size_t size;

    size = 0;
    /**
     * Load Generic Usage Register 1 lo 16 bits with the hi 16 bits of the source address.
    */
    code = fw_code_I(FW_CODE_OP_ADDI, FW_GENERIC_USAGE_REG_1, FW_ZERO_REG, (fw_immediate_t) ((saddr_ipv4 & 0xFFFF0000) >> 16));
    size += fwrite(&code, sizeof(code), 1, file);
    /**
     * Swap lo 16 bits of Generic Usage Register 1 with hi 16 bits of Generic Usage Register 1
    */
    code = fw_code_R(FW_CODE_OP_SWAP, FW_GENERIC_USAGE_REG_1, FW_ZERO_REG, FW_ZERO_REG);
    size += fwrite(&code, sizeof(code), 1, file);
    /**
     * Load Generic Usage Register 1 lo 16 bits with the lo 16 bits of the source address.
    */
    code = fw_code_I(FW_CODE_OP_ADDI, FW_GENERIC_USAGE_REG_1, FW_ZERO_REG, (fw_immediate_t) (saddr_ipv4 & 0x0000FFFF));
    size += fwrite(&code, sizeof(code), 1, file);
    /**
     * Compare the source address with the SADDR_IPV4 register.
    */
    code = fw_code_R(FW_CODE_OP_CMPEQU, FW_GENERIC_USAGE_REG_1, FW_SADDR_IPV4_REG, FW_GENERIC_USAGE_REG_1);
    size += fwrite(&code, sizeof(code), 1, file);
    /**
     * Update the single rule result register with the result of the comparison.
    */
    code = fw_code_R(FW_CODE_OP_LAND, FW_SINGLE_RULE_RESULT_REG, FW_SINGLE_RULE_RESULT_REG, FW_GENERIC_USAGE_REG_1);
    size += fwrite(&code, sizeof(code), 1, file);
    return size;
}
size_t fw_daddr_ipv4(FILE *file, uint32_t daddr_ipv4)
{
    fw_code_t code;
    size_t size;

    size = 0;
    /*
     * Load Generic Usage Register 1 lo 16 bits with the hi 16 bits of the destination address.
    */
    code = fw_code_I(FW_CODE_OP_ADDI, FW_GENERIC_USAGE_REG_1, FW_ZERO_REG, (fw_immediate_t) ((daddr_ipv4 & 0xFFFF0000) >> 16));
    size += fwrite(&code, sizeof(code), 1, file);
    /*
     * Swap lo 16 bits of Generic Usage Register 1 with hi 16 bits of Generic Usage Register 1
    */
    code = fw_code_R(FW_CODE_OP_SWAP, FW_GENERIC_USAGE_REG_1, FW_ZERO_REG, FW_ZERO_REG);
    size += fwrite(&code, sizeof(code), 1, file);
    /*
     * Load Generic Usage Register 1 lo 16 bits with the lo 16 bits of the destination address.
    */
    code = fw_code_I(FW_CODE_OP_ADDI, FW_GENERIC_USAGE_REG_1, FW_ZERO_REG, (fw_immediate_t) (daddr_ipv4 & 0x0000FFFF));
    size += fwrite(&code, sizeof(code), 1, file);
    /*
     * Compare the destination address with the DADDR_IPV4 register.
    */
    code = fw_code_R(FW_CODE_OP_CMPEQU, FW_GENERIC_USAGE_REG_1, FW_DADDR_IPV4_REG, FW_GENERIC_USAGE_REG_1);
    size += fwrite(&code, sizeof(code), 1, file);
    /*
     * Update the single rule result register with the result of the comparison.
    */
    code = fw_code_R(FW_CODE_OP_LAND, FW_SINGLE_RULE_RESULT_REG, FW_SINGLE_RULE_RESULT_REG, FW_GENERIC_USAGE_REG_1);
    size += fwrite(&code, sizeof(code), 1, file);
    return size;
}
size_t fw_sport(FILE *file, uint16_t sport_ipv4)
{
    fw_code_t code;
    size_t size;

    size = 0;
    /*
     * Load Generic Usage Register 1 lo 16 bits with the source port.
    */
    code = fw_code_I(FW_CODE_OP_ADDI, FW_GENERIC_USAGE_REG_1, FW_ZERO_REG, (fw_immediate_t) sport_ipv4);
    size+= fwrite(&code, sizeof(code), 1, file);
    /**
     * Compare the source port with the SPORT_IPV4 register.
    */
    code = fw_code_R(FW_CODE_OP_CMPEQU, FW_GENERIC_USAGE_REG_1, FW_SPORT_IPV4_REG, FW_GENERIC_USAGE_REG_1);
    size += fwrite(&code, sizeof(code), 1, file);
    /*
     * Update the single rule result register with the result of the comparison.
    */
    code = fw_code_R(FW_CODE_OP_LAND, FW_SINGLE_RULE_RESULT_REG, FW_SINGLE_RULE_RESULT_REG, FW_GENERIC_USAGE_REG_1);
    size += fwrite(&code, sizeof(code), 1, file);
    return size;
}
size_t fw_dport(FILE *file, uint16_t dport_ipv4)
{
    fw_code_t code;
    size_t size;

    size = 0;
    /*
     * Load Generic Usage Register 1 lo 16 bits with the destination port.
    */
    code = fw_code_I(FW_CODE_OP_ADDI, FW_GENERIC_USAGE_REG_1, FW_ZERO_REG, (fw_immediate_t) dport_ipv4);
    size += fwrite(&code, sizeof(code), 1, file);
    /*
     * Compare the destination port with the DPORT_IPV4 register.
    */
    code = fw_code_R(FW_CODE_OP_CMPEQU, FW_GENERIC_USAGE_REG_1, FW_DPORT_IPV4_REG, FW_GENERIC_USAGE_REG_1);
    size += fwrite(&code, sizeof(code), 1, file);
    /*
     * Update the single rule result register with the result of the comparison.
    */
    code = fw_code_R(FW_CODE_OP_LAND, FW_SINGLE_RULE_RESULT_REG, FW_SINGLE_RULE_RESULT_REG, FW_GENERIC_USAGE_REG_1);
    size += fwrite(&code, sizeof(code), 1, file);
    return size;
}
size_t fw_network_layer_protocol(FILE *file, uint16_t network_layer_protocol)
{
    fw_code_t code;
    size_t size;

    size = 0;
    /*
     * Load Generic Usage Register 1 lo 16 bits with the network layer protocol.
    */
    code = fw_code_I(FW_CODE_OP_ADDI, FW_GENERIC_USAGE_REG_1, FW_ZERO_REG, (fw_immediate_t) network_layer_protocol);
    size += fwrite(&code, sizeof(code), 1, file);
    /*
     * Compare the network layer protocol with the NETWORK_LAYER_PROTOCOL register.
    */
    code = fw_code_R(FW_CODE_OP_CMPEQU, FW_GENERIC_USAGE_REG_1, FW_NETWORK_LAYER_PROTOCOL_REG, FW_GENERIC_USAGE_REG_1);
    size += fwrite(&code, sizeof(code), 1, file);
    /*
     * Update the single rule result register with the result of the comparison.
    */
    code = fw_code_R(FW_CODE_OP_LAND, FW_SINGLE_RULE_RESULT_REG, FW_SINGLE_RULE_RESULT_REG, FW_GENERIC_USAGE_REG_1);
    size += fwrite(&code, sizeof(code), 1, file);
    return size;
}
size_t fw_transport_layer_protocol(FILE *file, uint16_t transport_layer_protocol)
{
    fw_code_t code;
    size_t size;

    size = 0;
    /*
     * Load Generic Usage Register 1 lo 16 bits with the transport layer protocol.
    */
    code = fw_code_I(FW_CODE_OP_ADDI, FW_GENERIC_USAGE_REG_1, FW_ZERO_REG, (fw_immediate_t) transport_layer_protocol);
    size += fwrite(&code, sizeof(code), 1, file);
    /*
     * Compare the transport layer protocol with the TRANSPORT_LAYER_PROTOCOL register.
    */
    code = fw_code_R(FW_CODE_OP_CMPEQU, FW_GENERIC_USAGE_REG_1, FW_TRANSPORT_LAYER_PROTOCOL_REG, FW_GENERIC_USAGE_REG_1);
    size += fwrite(&code, sizeof(code), 1, file);
    /*
     * Update the single rule result register with the result of the comparison.
    */
    code = fw_code_R(FW_CODE_OP_LAND, FW_SINGLE_RULE_RESULT_REG, FW_SINGLE_RULE_RESULT_REG, FW_GENERIC_USAGE_REG_1);
    size += fwrite(&code, sizeof(code), 1, file);
    return size;
}
size_t fw_rule_end(FILE *file)
{
    fw_code_t code;
    size_t size;

    size = 0;
    /*
     * Update the result register with the result of the logical AND operation.
    */
    code = fw_code_R(FW_CODE_OP_LOR, FW_RESULT_REG, FW_RESULT_REG, FW_SINGLE_RULE_RESULT_REG);
    size += fwrite(&code, sizeof(code), 1, file);
    return size;
}
size_t fw_end(FILE *file)
{
    fw_code_t code;
    size_t size;

    size = 0;
    /*
     * Halt the Program.
    */
    code = fw_code_R(FW_CODE_OP_HLT, FW_ZERO_REG, FW_ZERO_REG, FW_ZERO_REG);
    size += fwrite(&code, sizeof(code), 1, file);
    return size;
}
