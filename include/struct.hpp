#pragma once
#include <string>

#include "enum.hpp"

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct BaseRenderData {
    float x;
    float y;
    float rotation;
    float scale;
    bool visible;
    Gamemode gamemode;
    Color primaryColor;
    Color secondaryColor;
    bool glow;
    uint16_t cubeId;
    uint16_t shipId;
    uint16_t ballId;
    uint16_t ufoId;
    uint16_t waveId;
    uint16_t robotId;
    uint16_t spiderId;
};

// Holds the data for the RENDER_DATA packet
struct RenderData {
    BaseRenderData playerOne;
    BaseRenderData playerTwo;
};

struct IncomingRenderData {
    uint16_t playerId;
    RenderData renderData;
};