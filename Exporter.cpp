#include "Exporter.h"
#include <fstream>

void Exporter::exportToCSV(const std::vector<RawPacket>& packets, const std::string& filename) {
    std::ofstream file(filename);
    file << "SrcIP,DstIP,Protocol,SrcPort,DstPort\n";
    for (const auto &pkt : packets) {
        file << pkt.srcIP << "," << pkt.dstIP << "," << pkt.protocol << ","
             << pkt.srcPort << "," << pkt.dstPort << "\n";
    }
    file.close();
}
