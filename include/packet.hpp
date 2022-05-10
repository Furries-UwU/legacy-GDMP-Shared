#pragma once

struct Packet {
    uint8_t type;
    unsigned int length;
    uint8_t* data;

    Packet(uint8_t type, unsigned int length, uint8_t* data) {
        this->type = type;
        this->length = length + 1;
        this->data = data;
    }

    uint8_t& operator[](int index) {
        if (!index) {
            return this->type;
        } else {
            return this->data[index - 1];
        }
    }
}

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