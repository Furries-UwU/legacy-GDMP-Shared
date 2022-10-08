#pragma once

#include <cstdint>

enum PacketType:uint8_t {
    UNKNOWN = 0,
    JOIN_LEVEL = 1,
    LEAVE_LEVEL = 2,
    RENDER_DATA = 3,
    COLOR_DATA = 4,
    ICON_DATA = 5
};

enum Gamemode:uint8_t {
    NONE = 0,
    CUBE = 1,
    SHIP = 2,
    BALL = 3,
    UFO = 4,
    WAVE = 5,
    ROBOT = 6,
    SPIDER = 7
};