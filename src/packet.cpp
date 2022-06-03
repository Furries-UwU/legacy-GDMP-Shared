#include "packet.hpp"

Packet::Packet(uint8_t type, int length, uint8_t* data) {
    this->type = type;
    this->length = length;
    this->data = data;
}

Packet::Packet(ENetPacket* packet) {
    if (packet->dataLength < 5) {
        this->type = UNKNOWN;
        this->length = 0;
        this->data = nullptr;
    }
    else if (packet->dataLength == 5) {
        this->type = packet->data[0];
        this->length = 0;
        this->data = nullptr;
    }
    else {
        this->type = packet->data[0];
        this->length = packet->data[1] | (packet->data[2] << 8) | (packet->data[3] << 16) | (packet->data[4] << 24); // Util::uint_8_t_to_int doesn't work here for some reason
        this->data = packet->data + 5;
    }
}

const uint8_t& Packet::operator[](int index) {
    if (!index) {
        return this->type;
    } else if (index < 5) {
        return reinterpret_cast<uint8_t*>(&this->length)[index - 1];
    }
    else if (index < this->length + 5) {
        return this->data[index - 5];
    } else {
        throw std::out_of_range("Out of packet range");
    }
}

void Packet::send(ENetPeer* peer) {
    int packetLength = this->length + 5;
    ENetPacket* enetPacket = enet_packet_create(nullptr, packetLength, ENET_PACKET_FLAG_RELIABLE);
    if (!enetPacket)
        return;

    auto* packetData = new uint8_t[packetLength];

    for (int i = 0; i < packetLength; i++) {
        packetData[i] = this->operator[](i);
    }

    memcpy(enetPacket->data, packetData, packetLength);

    delete[] packetData;

    if (enet_peer_send(peer, 0, enetPacket) != 0)
        enet_packet_destroy(enetPacket);
}