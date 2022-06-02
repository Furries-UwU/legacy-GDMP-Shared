#pragma once
#include <enet/enet.h>
#include <stdexcept>
#include <cstring>

#include "enum.hpp"
#include "util.hpp"

struct Packet {
	uint8_t  type;
	int length;
	uint8_t* data;

	explicit Packet(uint8_t type = UNKNOWN, int length = 0, uint8_t* data = nullptr);
	
	explicit Packet(ENetPacket *packet);
	
	const uint8_t& operator[](int index);
	
	void send(ENetPeer* peer);
};