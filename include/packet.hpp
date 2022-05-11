#pragma once
#include <enet/enet.h>
#include <stdexcept>
#include <stdint.h>

struct Packet {
	uint8_t type;
	uint8_t* data;
	uint32_t length;

	Packet(uint8_t type, uint32_t length, uint8_t* data);
	const uint8_t& operator[](int index) const;
};

void sendPacket(ENetPeer* peer, Packet packet);