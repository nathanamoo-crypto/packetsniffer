cmake_minimum_required(VERSION 3.15)
project(PacketSniffer)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories("C:/Npcap-SDK/Include")

link_directories("C:/Npcap-SDK/Lib/x64")

file(GLOB SOURCES "src/*.cpp")

add_executable(PacketSniffer ${SOURCES})

target_link_libraries(PacketSniffer wpcap Packet)
