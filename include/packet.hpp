#pragma once
#include <enet/enet.h>
#include <stdexcept>
#include <stdint.h>

struct Packet {
    uint8_t type;
    uint8_t data[];

    Packet(uint8_t type) {
        this->type = type;
    }

    Packet(uint8_t type, uint8_t data[]) {
        this->type = type;
        memcpy(this->data, data, sizeof(data));
    }

    uint8_t& operator[](int index) {
        if (!index) {
            return this->type;
        }
        else if (index < sizeof(this)+1) {
            return this->data[index - 1];
        }
        else {
            throw std::out_of_range("Out of packet range");
        }
    }
};

void sendPacket(ENetPeer *peer, Packet packet, unsigned int length);
