#include "PacketCapture.h"
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <linux/if_ether.h>

PacketCapture::PacketCapture() : sockfd(-1) {}

PacketCapture::~PacketCapture() {
    if (sockfd != -1) close(sockfd);
}

bool PacketCapture::openDevice(const std::string& interfaceName) {
    sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sockfd < 0) {
        perror("Socket creation failed");
        return false;
    }
    // Optionally bind to interface here
    return true;
}

RawPacket PacketCapture::capturePacket() {
    uint8_t buffer[65536];
    ssize_t data_size = recvfrom(sockfd, buffer, sizeof(buffer), 0, nullptr, nullptr);
    RawPacket pkt;
    if (data_size > 0) {
        pkt.data.assign(buffer, buffer + data_size);
    }
    return pkt;
}

void PacketCapture::closeDevice() {
    if (sockfd != -1) close(sockfd);
    sockfd = -1;
}
