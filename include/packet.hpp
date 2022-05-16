#pragma once

#include <enet/enet.h>
#include <stdexcept>
#include <vector>

#include "struct.hpp"
#include "enum.hpp"

using json = nlohmann::json;

class Packet {
public:
    uint8_t type;
    unsigned int length;
    uint8_t *data;

    explicit Packet(uint8_t type = Unknown, unsigned int length = 0, uint8_t *data = nullptr);

    static Packet serialize(ENetPacket *packet);

    void sendPacket(ENetPeer *peer) const;

    const uint8_t& operator[](int index) const;
};