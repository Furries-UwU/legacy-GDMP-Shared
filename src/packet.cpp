#include "packet.hpp"

void sendPacket(ENetPeer *peer, Packet packet, unsigned int packetLength) {
    ENetPacket *enetPacket = enet_packet_create(nullptr, packetLength, ENET_PACKET_FLAG_RELIABLE);
    if (!enetPacket)
        return;

	memcpy(enetPacket->data, reinterpret_cast<uint8_t*>(&packet), packetLength);
	
    if (enet_peer_send(peer, 0, enetPacket) != 0)
        enet_packet_destroy(enetPacket);
}