#pragma once

enum PacketType {
	UNKNOWN,
	USERNAME, // Unused for now
	ICON_DATA,
	COLOR_DATA,
	RENDER_DATA,
	JOIN_LEVEL,
	LEAVE_LEVEL
};

enum Gamemode {
	UNKNOWN,
	CUBE,
	SHIP,
	BALL,
	UFO,
	WAVE,
	ROBOT,
	SPIDER,

	OWO = 254,
	UWU = 255,
	NYAAA = 256
};