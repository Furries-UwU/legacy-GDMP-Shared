#include "packet.hpp"

Packet::Packet(uint8_t type, uint32_t length, uint8_t* data) {
    this->type = type;
    this->data = data;
    this->length = length + 5;
}

const uint8_t& Packet::operator[](int index) const {
    if (!index) {
        return this->type;
    }
    else if (index < sizeof(this->length)) {
        return (this->length >> (8 * index - 1)) & 0xFF;
    }
    else if (index < this->length) {
        return this->data[index - (1 + sizeof(this->length))];
    }
    else {
        throw std::range_error("Out of packet range");
    }
}

void sendPacket(ENetPeer* peer, Packet packet) {
    ENetPacket* enetPacket = enet_packet_create(nullptr, packet.length, ENET_PACKET_FLAG_RELIABLE);
    if (!enetPacket)
        return;

    uint8_t* data = new uint8_t[packet.length];

    for (unsigned int i = 0; i < packet.length; i++) {
        data[i] = packet[i];
    }

    memcpy(enetPacket->data, data, packet.length);

    delete[] data;

    if (enet_peer_send(peer, 0, enetPacket) != 0)
        enet_packet_destroy(enetPacket);
}