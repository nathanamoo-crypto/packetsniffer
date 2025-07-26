#ifndef TRAFFIC_ANALYZER_H
#define TRAFFIC_ANALYZER_H

#include "PacketCapture.h"

/// Tracks and prints statistics about captured packets
class TrafficAnalyzer {
public:
    void addPacket(const RawPacket& pkt);
    void printStats() const;

private:
    int tcpCount = 0;
    int udpCount = 0;
    int otherCount = 0;
};

#endif
