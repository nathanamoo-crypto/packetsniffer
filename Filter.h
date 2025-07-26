#ifndef FILTER_H
#define FILTER_H

#include "PacketCapture.h"
#include <string>

/// Filters packets based on user-defined criteria
class Filter {
public:
    bool match(const RawPacket& pkt, const std::string& protocolFilter);
};

#endif
