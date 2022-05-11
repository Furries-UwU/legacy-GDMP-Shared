#pragma once
#include <enet/enet.h>
#include <stdexcept>
#include <stdint.h>

#pragma pack(push, 1)
struct Packet {
    uint8_t type;
    uint8_t* data;
};
#pragma pack(pop)

void sendPacket(ENetPeer *peer, Packet packet, unsigned int packetLength);
