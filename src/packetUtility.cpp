#include "packetUtility.hpp"

void PacketUtility::sendPacket(const Packet& packet, ENetPeer *peer) {
    if (peer == nullptr)
        return;

    std::string packetData = packet.SerializeAsString();

    ENetPacket *enetPacket = enet_packet_create(packetData.c_str(), packetData.size()+1, ENET_PACKET_FLAG_RELIABLE);
    if (enet_peer_send(peer, 0, enetPacket) != 0)
        enet_packet_destroy(enetPacket);
}

void PacketUtility::sendPacket(const IncomingPacket& packet, ENetPeer *peer) {
    if (peer == nullptr)
        return;

    std::string packetData = packet.SerializeAsString();

    ENetPacket *enetPacket = enet_packet_create(packetData.c_str(), packetData.size()+1, ENET_PACKET_FLAG_RELIABLE);
    if (enet_peer_send(peer, 0, enetPacket) != 0)
        enet_packet_destroy(enetPacket);
}
