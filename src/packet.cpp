#include "packet.hpp"

Packet::Packet(uint8_t type) {
    this->type = type;
}

Packet::Packet(uint8_t type, uint32_t length, uint8_t* data) {
    this->type = type;
    this->length = length + 5; // +1, because of type, +4 because of uint32_t
    this->data = data;
}

const uint8_t& Packet::operator[](int index) {
    if (!index) { // 0
        return this->type;
    }
    else if (index < 5) { // 1, 2, 3, 4
        return ((uint8_t*)&this->length)[index - 1];
    }
    else if (index < this->length - 5) { // 5, 6, 7, 8, 9, ...
        return this->data[index - 5];
    }
    else {
        throw std::out_of_range("Out of packet range");
    }
}

void Packet::send(ENetPeer* peer) {
    ENetPacket* enetPacket = enet_packet_create(nullptr, this->length, ENET_PACKET_FLAG_RELIABLE);
    if (!enetPacket)
        return;


    uint8_t* data = new uint8_t[this->length];

    for (unsigned int i = 0; i < this->length; i++) {
        data[i] = this->operator[](i);
    }

    memcpy(enetPacket->data, data, this->length);

    delete[] data;

    if (enet_peer_send(peer, 0, enetPacket) != 0)
        enet_packet_destroy(enetPacket);
}