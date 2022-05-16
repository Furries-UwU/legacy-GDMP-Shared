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

    packet->data[0] = this->type;
    packet->data[1] = (this->length >> 24) & 0xFF;
    packet->data[2] = (this->length >> 16) & 0xFF;
    packet->data[3] = (this->length >> 8) & 0xFF;
    packet->data[4] = this->length & 0xFF;
    memcpy(packet->data + 5, this->data, this->length);


    if (enet_peer_send(peer, 0, packet) != 0)
        enet_packet_destroy(packet);
}

const uint8_t &Packet::operator[](int index) {
    if (!index) {
        return this->type;
    } else if (index < 5) {
        return reinterpret_cast<uint8_t *>(&this->length)[index - 1];
    } else if (index < this->length + 5) {
        return this->data[index - 5];
    } else {
        throw std::out_of_range("Out of packet range");
    }
}