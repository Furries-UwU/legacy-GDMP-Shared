#include "packetUtility.hpp"

void PacketUtility::sendPacket(ENetPeer *peer, const Packet& packet) {
    if (peer == nullptr)
        return;

    const char* data = packet.SerializeAsString().c_str();

    ENetPacket *enetPacket = enet_packet_create(data, strlen(data), ENET_PACKET_FLAG_RELIABLE);
    if (enet_peer_send(peer, 0, enetPacket) != 0)
        enet_packet_destroy(enetPacket);
}

void PacketUtility::sendPacket(ENetPeer *peer, const IncomingPacket& packet) {
    if (peer == nullptr)
        return;

    const char* data = packet.SerializeAsString().c_str();

    ENetPacket *enetPacket = enet_packet_create(data, strlen(data), ENET_PACKET_FLAG_RELIABLE);
    if (enet_peer_send(peer, 0, enetPacket) != 0)
        enet_packet_destroy(enetPacket);
}