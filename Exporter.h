#ifndef EXPORTER_H
#define EXPORTER_H

#include "PacketCapture.h"
#include <string>
#include <vector>

/// Exports captured packets to a file
class Exporter {
public:
    void exportToCSV(const std::vector<RawPacket>& packets, const std::string& filename);
};

#endif
