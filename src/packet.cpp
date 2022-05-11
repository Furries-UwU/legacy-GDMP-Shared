#include "packet.hpp"

void sendPacket(ENetPeer* peer, Packet packet, unsigned int packetLength) {
    ENetPacket* enetPacket = enet_packet_create(nullptr, packetLength, ENET_PACKET_FLAG_RELIABLE);
    if (!enetPacket)
        return;

    unsigned int packetTypeSize = sizeof(packet.type);

    memcpy(enetPacket->data, &packet.type, packetTypeSize);
    memcpy(enetPacket->data + packetTypeSize, packet.data, packetLength - packetTypeSize);

    if (enet_peer_send(peer, 0, enetPacket) != 0)
        enet_packet_destroy(enetPacket);
}