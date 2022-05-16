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

void Packet::sendPacket(ENetPeer* peer) {
    auto trueLength = this->length + 5;
    ENetPacket* enetPacket = enet_packet_create(nullptr, trueLength, ENET_PACKET_FLAG_RELIABLE);
    if (!enetPacket)
        return;

    auto packetData = new uint8_t[trueLength];

    for (int i = 0; i < trueLength; i++) {
        packetData[i] = this->operator[](i);
    }

    memcpy(enetPacket->data, data, trueLength);

    delete[] packetData;

    if (enet_peer_send(peer, 0, enetPacket) != 0)
        enet_packet_destroy(enetPacket);
}

const uint8_t& Packet::operator[](int index) {
    if (index == 0) {
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