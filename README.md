# packetsniffer
Create a network packet analyzer that can capture, decode, and analyze network traffic (usingraw sockets where permitted).Key Features: Packet capture, protocol parsing (TCP, UDP, HTTP), traffic analysis, filtering, export tovarious formats.Learning Goals: Network programming, protocol analysis, binary data parsing
 How to use on Windows
Install Npcap
👉 https://npcap.com/
(During install, check “Install Npcap in WinPcap API-compatible Mode”.)

Install Npcap SDK (for header/libs)

Copy Include/pcap.h into your project include path

Link against wpcap.lib and Packet.lib (Npcap SDK provides these)

Call PacketCapture::listDevices() to see your interface names:

Copy
Edit
\\Device\\NPF_{XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX}
Use one of these strings in openDevice().

Compile and run

Use Visual Studio or CMake on Windows.

Add -lwpcap -lPacket to your linker settings.