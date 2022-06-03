#pragma once
#include <string>

#include "enum.hpp"

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct ColorData {
    Color primaryColor;
    Color secondaryColor;
    bool glow;
};

struct IconData {
    uint16_t cubeId;
    uint16_t shipId;
    uint16_t ballId;
    uint16_t ufoId;
    uint16_t waveId;
    uint16_t robotId;
    uint16_t spiderId;
};

struct BaseRenderData {
    float x;
    float y;
    float rotation;
    float scale;
    bool visible;
    Gamemode gamemode;
};

// Holds the data for the RENDER_DATA packet
struct RenderData {
    BaseRenderData playerOne;
    BaseRenderData playerTwo;
};

struct IncomingColorData {
    uint16_t playerId;
    ColorData colorData;
};

struct IncomingIconData {
    uint16_t playerId;
    IconData iconData;
};

struct IncomingRenderData {
    uint16_t playerId;
    RenderData renderData;
};

struct IncomingUsername {
    uint16_t playerId;
    std::string username;
};