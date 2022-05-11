#pragma once
#include <enet/enet.h>
#include <stdexcept>
#include <stdint.h>

struct Packet {
	uint8_t type;
	void** data;
};

void sendPacket(ENetPeer *peer, Packet packet);
