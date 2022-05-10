#pragma once

#include <enet/enet.h>
#include <stdexcept>
#include <stdint.h>

struct Packet {
    uint8_t type;
    uint8_t* data;

    Packet(uint8_t type) {
        this->type = type;
    }

    Packet(uint8_t type, uint8_t* data) {
        this->type = type;
        this->data = data;
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

struct PlayerData
{
    const char *username;
    int ship;
    int ball;
    int bird;
    int dart;
    int robot;
    int spider;
    int glow;
    int color;
    int color2;
};

void sendPacket(ENetPeer *peer, Packet packet, unsigned int length);
