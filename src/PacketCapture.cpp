#include "PacketCapture.h"
#include <pcap.h>
#include <iostream>

pcap_t* capHandle = nullptr;

PacketCapture::PacketCapture() {
    handle = nullptr;
}

PacketCapture::~PacketCapture() {
    closeDevice();
}

bool PacketCapture::openDevice(const std::string& interfaceName) {
    char errbuf[PCAP_ERRBUF_SIZE];

    // open the capture handle
    pcap_t* p = pcap_open_live(interfaceName.c_str(), 65536, 1, 1000, errbuf);
    if (!p) {
        std::cerr << "Failed to open adapter: " << errbuf << std::endl;
        return false;
    }
    handle = p;
    return true;
}

RawPacket PacketCapture::capturePacket() {
    RawPacket pkt;
    if (!handle) return pkt;

    struct pcap_pkthdr* header;
    const u_char* data;

    int res = pcap_next_ex((pcap_t*)handle, &header, &data);
    if (res > 0) {
        pkt.data.assign(data, data + header->len);
    }
    return pkt;
}

void PacketCapture::closeDevice() {
    if (handle) {
        pcap_close((pcap_t*)handle);
        handle = nullptr;
    }
}

void PacketCapture::listDevices() {
    pcap_if_t* alldevs;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        std::cerr << "Error finding devices: " << errbuf << std::endl;
        return;
    }

    std::cout << "Available adapters:\n";
    for (pcap_if_t* d = alldevs; d != nullptr; d = d->next) {
        std::cout << d->name;
        if (d->description) std::cout << " - " << d->description;
        std::cout << std::endl;
    }

    pcap_freealldevs(alldevs);
}
