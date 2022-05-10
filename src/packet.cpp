#include "include/packet.hpp";

void sendPacket(ENetPeer *peer, Packet packet, unsigned int length) {
    ENetPacket *packet = enet_packet_create(nullptr, length, ENET_PACKET_FLAG_RELIABLE);
    if (!packet)
        return;
    std::memcpy(packet->data, &packet, length);
    if (enet_peer_send(peer, 0, packet) != 0)
        enet_packet_destroy(packet);
}