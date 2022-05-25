#pragma once

enum PacketType {
    USERNAME,
    RENDER_DATA,
    COLOR_DATA,
    ICON_DATA,
    JOIN_LEVEL,
    LEAVE_LEVEL
};

enum Gamemode : unsigned char {
    CUBE,
    SHIP,
    BALL,
    UFO,
    WAVE,
    ROBOT,
    SPIDER
};