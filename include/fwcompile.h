#ifndef FWCOMPILE_H
#define FWCOMPILE_H

#include <stdio.h>
#include <stdint.h>

/**
 * Zero Register
*/
#define FW_ZERO_REG 0
/**
 * Result Register
*/
#define FW_RESULT_REG 1
/**
 * Single Rule Result Register
*/
#define FW_SINGLE_RULE_RESULT_REG 2
/**
 * 32-bit IPv4 Source Address Register
*/
#define FW_SADDR_IPV4_REG 20
/**
 * 32-bit IPv4 Destination Address Register
*/
#define FW_DADDR_IPV4_REG 24
/**
 * Low 16-bit IPv4 Source Port Register
*/
#define FW_SPORT_IPV4_REG 28
/**
 * Low 16-bit IPv4 Destination Port Register
*/
#define FW_DPORT_IPV4_REG 29
/**
 * Low 8-bit Network Layer Protocol Register
*/
#define FW_NETWORK_LAYER_PROTOCOL_REG 30
/**
 * Low 8-bit Transport Layer Protocol Register
*/
#define FW_TRANSPORT_LAYER_PROTOCOL_REG 31
/**
 * Gerneric Usage Register 1
*/
#define FW_GENERIC_USAGE_REG_1 3

/**
 * Rule Begin
 * @param file File to write to
 * @return Number of bytes written
*/
size_t fw_rule_begin(FILE *file);
/**
 * Compare IPv4 Source Address
 * @param file File to write to
 * @param saddr_ipv4 IPv4 Source Address
 * @return Number of bytes written
*/
size_t fw_saddr_ipv4(FILE *file, uint32_t saddr_ipv4);
/**
 * Compare IPv4 Destination Address
 * @param file File to write to
 * @param daddr_ipv4 IPv4 Destination Address
 * @return Number of bytes written
*/
size_t fw_daddr_ipv4(FILE *file, uint32_t daddr_ipv4);
/**
 * Compare Source Port
 * @param file File to write to
 * @param sport_ipv4 IPv4 Source Port
 * @return Number of bytes written
*/
size_t fw_sport(FILE *file, uint16_t sport_ipv4);
/**
 * Compare Destination Port
 * @param file File to write to
 * @param dport_ipv4 IPv4 Destination Port
 * @return Number of bytes written
*/
size_t fw_dport(FILE *file, uint16_t dport_ipv4);
/**
 * Compare Network Layer Protocol and Transport Layer Protocol
 * @param file File to write to
 * @param network_layer_protocol Network Layer Protocol
 * @return Number of bytes written
*/
size_t fw_network_layer_protocol(FILE *file, uint16_t network_layer_protocol);
/**
 * Compare Transport Layer Protocol
 * @param file File to write to
 * @param transport_layer_protocol Transport Layer Protocol
 * @return Number of bytes written
*/
size_t fw_transport_layer_protocol(FILE *file, uint16_t transport_layer_protocol);
/**
 * Rule End
 * @param file File to write to
 * @return Number of bytes written
*/
size_t fw_rule_end(FILE *file);
/**
 * End Program
 * @param file File to write to
 * @return Number of bytes written
*/
size_t fw_end(FILE *file);

#endif
