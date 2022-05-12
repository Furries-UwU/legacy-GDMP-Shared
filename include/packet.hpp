#pragma once
#include <enet/enet.h>
#include <stdexcept>
#include <stdint.h>

struct Packet {
	uint8_t type;
	uint32_t length;
	uint8_t* data;

	Packet(uint8_t type) : Packet(type, 0, nullptr) {};
	Packet(uint8_t type, uint32_t length, uint8_t* data);
	
	Packet(ENetPacket packet);
	
	const uint8_t& operator[](int index);
	
	void send(ENetPeer* peer);
};