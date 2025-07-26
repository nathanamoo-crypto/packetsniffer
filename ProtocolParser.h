#ifndef PROTOCOL_PARSER_H
#define PROTOCOL_PARSER_H

#include "PacketCapture.h"

/// Parses raw packet bytes into metadata like IP addresses and ports
class ProtocolParser {
public:
    void parsePacket(RawPacket &packet);
};

#endif
