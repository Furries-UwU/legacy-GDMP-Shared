#pragma once

enum PacketType: uint8_t {
	UNKNOWN,
	PLAYER_DATA, // Client -> Server
	RENDER_DATA, // Client -> Server 
	UPDATE_PLAYER_RENDER_DATA, // Server -> Client
	UPDATE_PLAYER_DATA, // Server -> Client
	JOIN_LEVEL, // Client -> Server
	LEAVE_LEVEL, // Client -> Server
	PLAYER_JOIN_LEVEL, // Server -> Client
	PLAYER_LEAVE_LEVEL // Server -> Client
};

enum Gamemode {
	CUBE = 1,
	SHIP = 2,
	BALL = 4,
	UFO = 8,
	WAVE = 16,
	ROBOT = 32,
	SPIDER = 64,

	NONE = 32764,
	OWO = 32765,
	UWU = 32766,
	NYAAA = 32767
};