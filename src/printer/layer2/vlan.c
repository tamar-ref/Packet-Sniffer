#include "../../../headers/printer/layer2/vlan.h"

void print_vlan(Vlan vlan)
{
    uint16_t pcp = (vlan.tci >> 13) & 0x07;
    uint16_t dei = (vlan.tci >> 12) & 0x01;
    uint16_t vid = vlan.tci & 0x0FFF;

    printf("\n%-*s: VLAN\n",
           PRINT_LABEL_WIDTH,
           "Protocol");

    printf("%-*s: 0x%04X\n",
           PRINT_LABEL_WIDTH,
           "TPID",
           vlan.tpid);

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "Priority (PCP)",
           pcp);

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "DEI",
           dei);

    printf("%-*s: %u\n",
           PRINT_LABEL_WIDTH,
           "VLAN ID",
           vid);

    printf("%-*s: 0x%04X\n",
           PRINT_LABEL_WIDTH,
           "EtherType",
           vlan.ether_type);
}