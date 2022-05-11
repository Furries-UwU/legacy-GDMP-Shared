#pragma once
#include <enet/enet.h>
#include <stdexcept>
#include <stdint.h>

struct Packet {
    uint8_t type;
    uint8_t* data;

    Packet(uint8_t packetType) {
        this->type = packetType;
    }

    Packet(uint8_t packetType, uint8_t* packetData) {
        this->type = packetType;
        this->data = packetData;
    }
};

void sendPacket(ENetPeer *peer, Packet packet, unsigned int packetLength);
