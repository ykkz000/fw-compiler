#include <stdio.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include <arpa/inet.h>
#include <libxml/parser.h>
#include "fwcompile.h"
#include "logger.h"

const static char COMPILED_FILE_PATH[] = "/etc/nt_fw/nt_fw.fw";

void parse_root(FILE *output_file, xmlNodePtr root);
void parse_rule(FILE *output_file, xmlNodePtr rule);
void parse_saddr(FILE *output_file, xmlNodePtr saddr);
void parse_daddr(FILE *output_file, xmlNodePtr daddr);
void parse_sport(FILE *output_file, xmlNodePtr sport);
void parse_dport(FILE *output_file, xmlNodePtr dport);
void parse_network_layer_protocol(FILE *output_file, xmlNodePtr network_layer_protocol);
void parse_transport_layer_protocol(FILE *output_file, xmlNodePtr transport_layer_protocol);

int main(int argc, char **argv)
{
    xmlDocPtr doc;
    xmlNodePtr root;
    FILE *output_file;

    if (argc != 2)
    {
        LOG_ERROR("Arguement error");
    }
    doc = xmlParseFile(argv[1]);
    root = xmlDocGetRootElement(doc);
    output_file = fopen(COMPILED_FILE_PATH, "w");
    parse_root(output_file, root);
    fclose(output_file);
    xmlFreeDoc(doc);
    return 0;
}

void parse_root(FILE *output_file, xmlNodePtr root)
{
    xmlNodePtr rule;

    for (rule = root->xmlChildrenNode; rule != NULL; rule = rule->next)
    {
        if (rule->type == XML_ELEMENT_NODE && xmlStrcmp(rule->name, (const xmlChar *)"rule") == 0)
        {
            parse_rule(output_file, rule);
        }
    }
    fw_end(output_file);
}

void parse_rule(FILE *output_file, xmlNodePtr rule)
{
    xmlNodePtr node;

    fw_rule_begin(output_file);
    for (node = rule->xmlChildrenNode; node != NULL; node = node->next)
    {
        if (rule->type != XML_ELEMENT_NODE)
        {
            continue;
        }
        if (xmlStrcmp(node->name, (const xmlChar *)"saddr") == 0)
        {
            parse_saddr(output_file, node);
        }
        else if (xmlStrcmp(node->name, (const xmlChar *)"daddr") == 0)
        {
            parse_daddr(output_file, node);
        }
        else if (xmlStrcmp(node->name, (const xmlChar *)"sport") == 0)
        {
            parse_sport(output_file, node);
        }
        else if (xmlStrcmp(node->name, (const xmlChar *)"dport") == 0)
        {
            parse_dport(output_file, node);
        }
        else if (xmlStrcmp(node->name, (const xmlChar *)"NLProtocol") == 0)
        {
            parse_network_layer_protocol(output_file, node);
        }
        else if (xmlStrcmp(node->name, (const xmlChar *)"TLProtocol") == 0)
        {
            parse_transport_layer_protocol(output_file, node);
        }
    }
    fw_rule_end(output_file);
}
void parse_saddr(FILE *output_file, xmlNodePtr saddr)
{
    uint32_t addr;

    addr = inet_addr((char *)saddr->content);
    fw_saddr_ipv4(output_file, addr);
}
void parse_daddr(FILE *output_file, xmlNodePtr daddr)
{
    uint32_t addr;

    addr = inet_addr((char *)daddr->content);
    fw_daddr_ipv4(output_file, addr);
}
void parse_sport(FILE *output_file, xmlNodePtr sport)
{
    uint16_t port;

    port = (uint16_t)atoi((char *) sport->content);
    fw_sport(output_file, port);
}
void parse_dport(FILE *output_file, xmlNodePtr dport)
{
    uint16_t port;

    port = (uint16_t)atoi((char *) dport->content);
    fw_dport(output_file, port);
}
void parse_network_layer_protocol(FILE *output_file, xmlNodePtr network_layer_protocol)
{
    uint16_t proto;

    if (xmlStrcmp(network_layer_protocol->content, (const xmlChar *)"IPv4") == 0)
    {
        proto = (uint16_t) ETH_P_IP;
    }
    else if (xmlStrcmp(network_layer_protocol->content, (const xmlChar *)"IPv6") == 0)
    {
        proto = (uint16_t) ETH_P_IPV6;
    }
    else if (xmlStrcmp(network_layer_protocol->content, (const xmlChar *)"ARP") == 0)
    {
        proto = (uint16_t) ETH_P_ARP;
    }
    else if (xmlStrcmp(network_layer_protocol->content, (const xmlChar *)"RARP") == 0)
    {
        proto = (uint16_t) ETH_P_RARP;
    }
    else
    {
        LOG_WARN("Unknown network layer protocol %s", network_layer_protocol->content);
        return;
    }
    fw_network_layer_protocol(output_file, proto);
}
void parse_transport_layer_protocol(FILE *output_file, xmlNodePtr transport_layer_protocol)
{
    uint16_t proto;

    if (xmlStrcmp(transport_layer_protocol->content, (const xmlChar *)"TCP") == 0)
    {
        proto = (uint16_t) IPPROTO_TCP;
    }
    else if (xmlStrcmp(transport_layer_protocol->content, (const xmlChar *)"UDP") == 0)
    {
        proto = (uint16_t) IPPROTO_UDP;
    }
    else if (xmlStrcmp(transport_layer_protocol->content, (const xmlChar *)"ICMP") == 0)
    {
        proto = (uint16_t) IPPROTO_ICMP;
    }
    else
    {
        LOG_WARN("Unknown transport layer protocol %s", transport_layer_protocol->content);
        return;
    }
    fw_transport_layer_protocol(output_file, proto);
}
