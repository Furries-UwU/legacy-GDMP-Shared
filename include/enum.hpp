#pragma once

enum PacketType: uint8_t {
	UNKNOWN,
	C2S_PLAYER_DATA, // Client -> Server
	C2S_RENDER_DATA, // Client -> Server
	S2C_UPDATE_PLAYER_RENDER_DATA, // Server -> Client
	S2C_UPDATE_PLAYER_DATA, // Server -> Client
	X2X_JOIN_LEVEL, // Client -> Server
	X2X_LEAVE_LEVEL, // Client -> Server
	S2C_PLAYER_JOIN_LEVEL, // Server -> Client
	S2C_PLAYER_LEAVE_LEVEL // Server -> Client
};

enum Gamemode {
	CUBE,
	SHIP,
	BALL,
	UFO,
	WAVE,
	ROBOT,
	SPIDER,

	NONE,
	OWO,
	UWU,
	NYAAA
};