#include "packet.hpp"

void sendPacket(ENetPeer *peer, Packet packet, unsigned int dataLength) {
    ENetPacket *enetPacket = enet_packet_create(nullptr, dataLength, ENET_PACKET_FLAG_RELIABLE);
    if (!enetPacket)
        return;

	memcpy(enetPacket->data, reinterpret_cast<uint8_t*>(&packet), dataLength);
	
    if (enet_peer_send(peer, 0, enetPacket) != 0)
        enet_packet_destroy(enetPacket);
}