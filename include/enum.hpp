#pragma once

enum PacketType {
    UNKNOWN,
    USERNAME [[maybe_unused]], // Unused for now
    ICON_DATA,
    COLOR_DATA,
    RENDER_DATA,
    JOIN_LEVEL,
    LEAVE_LEVEL
};

enum Gamemode {
    NONE,
    CUBE,
    SHIP,
    BALL,
    UFO,
    WAVE,
    ROBOT,
    SPIDER
};