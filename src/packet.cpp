#include "packet.hpp"

Packet::Packet(uint8_t type, unsigned int length, uint8_t *data) {
    this->type = type;
    this->length = length;
    this->data = data;
}

Packet Packet::serialize(ENetPacket *eNetPacket) {
    Packet packet;

    if (eNetPacket->dataLength < 5) {
        packet.type = UNKNOWN;
        packet.length = 0;
        packet.data = nullptr;
    } else if (eNetPacket->dataLength == 5) {
        packet.type = eNetPacket->data[0];
        packet.length = 0;
        packet.data = nullptr;
    } else {
        packet.type = eNetPacket->data[0];
        packet.data = eNetPacket->data + 5;
    }

    return packet;
}


void Packet::sendPacket(ENetPeer *peer) const {
    ENetPacket *packet = enet_packet_create(nullptr, this->length + 5, ENET_PACKET_FLAG_RELIABLE);

    uint8_t* data = new uint8_t[length];

    for (unsigned int i = 0; i < length; i++) {
        data[i] = this->operator[](i);
    }

    if (enet_peer_send(peer, 0, packet) != 0)
        enet_packet_destroy(packet);
}

const uint8_t& Packet::operator[](int index) {
    if (!index) {
        return this->type;
    }
    else if (index < 5) {
        return reinterpret_cast<uint8_t*>(&this->length)[index - 1];
    }
    else if (index < this->length + 5) {
        return this->data[index - 5];
    }
    else {
        throw std::out_of_range("Out of packet range");
    }
}