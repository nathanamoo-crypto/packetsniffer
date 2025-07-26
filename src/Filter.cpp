#include "Filter.h"

bool Filter::match(const RawPacket &pkt, const std::string &protocolFilter) {
    if (protocolFilter.empty()) return true;
    return pkt.protocol == protocolFilter;
}
