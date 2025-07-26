#include "TrafficAnalyzer.h"
#include <iostream>

void TrafficAnalyzer::addPacket(const RawPacket &pkt) {
    if (pkt.protocol == "TCP") tcpCount++;
    else if (pkt.protocol == "UDP") udpCount++;
    else otherCount++;
}

void TrafficAnalyzer::printStats() const {
    std::cout << "[Stats] TCP: " << tcpCount
              << " UDP: " << udpCount
              << " Other: " << otherCount << std::endl;
}
