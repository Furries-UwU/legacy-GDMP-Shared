#pragma once
#include <enet/enet.h>
#include <stdexcept>
#include <stdint.h>

#include "enum.hpp"

struct Packet {
	uint8_t  type;
	unsigned int length;
	uint8_t* data;

	Packet(uint8_t type = UNKNOWN, unsigned int length = 0, uint8_t* data = nullptr);
	
	Packet(ENetPacket *packet);
	
	const uint8_t& operator[](int index);
	
	void send(ENetPeer* peer);
};