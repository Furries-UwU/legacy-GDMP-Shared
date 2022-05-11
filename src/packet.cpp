#include "packet.hpp"

void sendPacket(ENetPeer *peer, Packet packet, unsigned int packetLength) {
    ENetPacket *enetPacket = enet_packet_create(nullptr, packetLength, ENET_PACKET_FLAG_RELIABLE);
    if (!enetPacket)
        return;

    uint8_t* data = (uint8_t*)&packet;
	
    memcpy(enetPacket->data, &data, packetLength);
	
    if (enet_peer_send(peer, 0, enetPacket) != 0)
        enet_packet_destroy(enetPacket);
}