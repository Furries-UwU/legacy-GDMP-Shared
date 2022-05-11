#pragma once
#include <enet/enet.h>
#include <stdexcept>
#include <stdint.h>

struct Packet {
	uint8_t type;
	uint8_t* data;
};

void sendPacket(ENetPeer *peer, Packet packet);
