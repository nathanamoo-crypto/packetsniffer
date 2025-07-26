#include "ProtocolParser.h"
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>

void ProtocolParser::parsePacket(RawPacket &packet) {
    if (packet.data.size() < 34) return; // Ethernet (14) + minimal IP header (20)

    struct iphdr *iph = (struct iphdr*)(packet.data.data() + 14); // skip Ethernet
    packet.srcIP = inet_ntoa(*(in_addr*)&iph->saddr);
    packet.dstIP = inet_ntoa(*(in_addr*)&iph->daddr);

    switch(iph->protocol) {
        case IPPROTO_TCP: {
            packet.protocol = "TCP";
            auto *tcph = (struct tcphdr*)(packet.data.data() + 14 + iph->ihl*4);
            packet.srcPort = ntohs(tcph->source);
            packet.dstPort = ntohs(tcph->dest);
            break;
        }
        case IPPROTO_UDP: {
            packet.protocol = "UDP";
            auto *udph = (struct udphdr*)(packet.data.data() + 14 + iph->ihl*4);
            packet.srcPort = ntohs(udph->source);
            packet.dstPort = ntohs(udph->dest);
            break;
        }
        default:
            packet.protocol = "OTHER";
            break;
    }
}
