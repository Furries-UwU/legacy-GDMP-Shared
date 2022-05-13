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
	CUBE,
	SHIP,
	BALL,
	UFO,
	WAVE,
	ROBOT,
	SPIDER,

	
	OWO,
	UWU,
	NYAAA
};