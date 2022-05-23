#pragma once

enum PacketType {
    UNKNOWN,
    USERNAME [[maybe_unused]], // Unused for now
    RENDER_DATA,
    COLOR_DATA,
    ICON_DATA,
    JOIN_LEVEL,
    LEAVE_LEVEL
};

enum Gamemode:unsigned char {
    NONE,
    CUBE,
    SHIP,
    BALL,
    UFO,
    WAVE,
    ROBOT,
    SPIDER
};