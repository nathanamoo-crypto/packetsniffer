#include "PacketCapture.h"
#include "ProtocolParser.h"
#include "TrafficAnalyzer.h"
#include "Filter.h"
#include "Exporter.h"
#include <iostream>
#include <vector>

int main() {
    PacketCapture capturer;
    ProtocolParser parser;
    TrafficAnalyzer analyzer;
    Filter filter;
    Exporter exporter;

    std::vector<RawPacket> allPackets;

    if (!capturer.openDevice("eth0")) { // Replace with your interface
        std::cerr << "Failed to open device.\n";
        return 1;
    }

    std::cout << "Capturing packets... Press Ctrl+C to stop.\n";
    for (int i = 0; i < 100; ++i) { // capture 100 packets
        RawPacket pkt = capturer.capturePacket();
        parser.parsePacket(pkt);
        if (filter.match(pkt, "TCP")) { // Only process TCP packets
            analyzer.addPacket(pkt);
            allPackets.push_back(pkt);
        }
    }

    analyzer.printStats();
    exporter.exportToCSV(allPackets, "packets.csv");

    capturer.closeDevice();
    return 0;
}
