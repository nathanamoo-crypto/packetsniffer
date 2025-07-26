#ifndef PACKET_CAPTURE_H
#define PACKET_CAPTURE_H

#include <vector>
#include <string>
#include <cstdint>

/// Structure to hold captured packet data and parsed metadata
struct RawPacket {
    std::vector<uint8_t> data;
    std::string srcIP;
    std::string dstIP;
    uint16_t srcPort;
    uint16_t dstPort;
    std::string protocol;
};

/// Handles opening a raw socket and capturing packets
class PacketCapture {
public:
    PacketCapture();
    ~PacketCapture();

    bool openDevice(const std::string& interfaceName);
    RawPacket capturePacket(); // captures a single packet
    void closeDevice();

private:
    int sockfd; // raw socket descriptor
};

#endif
