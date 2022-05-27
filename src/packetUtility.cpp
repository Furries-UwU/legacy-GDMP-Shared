#include "packetUtility.hpp"

void PacketUtility::sendPacket(Packet packet, ENetPeer *peer) {
    if (peer == nullptr)
        return;

    std::vector<uint8_t> packetData(packet.ByteSizeLong());
    packet.SerializeToArray(packetData.data(), packet.ByteSizeLong());

    ENetPacket *enetPacket = enet_packet_create(packetData.data(), packetData.size(), ENET_PACKET_FLAG_RELIABLE);
    if (enet_peer_send(peer, 0, enetPacket) != 0)
        enet_packet_destroy(enetPacket);
}

void PacketUtility::sendPacket(IncomingPacket packet, ENetPeer *peer) {
    if (peer == nullptr)
        return;

    std::vector<uint8_t> packetData(packet.ByteSizeLong());
    packet.SerializeToArray(packetData.data(), packet.ByteSizeLong());

    ENetPacket *enetPacket = enet_packet_create(packetData.data(), packetData.size(), ENET_PACKET_FLAG_RELIABLE);
    if (enet_peer_send(peer, 0, enetPacket) != 0)
        enet_packet_destroy(enetPacket);
}
