#pragma once
#include <steam/steamnetworkingsockets.h>
#include <steam/isteamnetworkingutils.h>

#include <stdexcept>
#include <stdint.h>

#include "enum.hpp"
#include "util.hpp"

struct Packet {
	uint8_t  type;
	uint32_t length; // I hope that i won't do something dumb
	uint8_t* data;

	Packet(uint8_t type = UNKNOWN, uint32_t length = 0, uint8_t* data = nullptr);
	
	Packet(ISteamNetworkingMessage *incomingMessage);
	
	const uint8_t& operator[](int index);
	
	void send(ISteamNetworkingSockets *interface, HSteamNetConnection connection);
};