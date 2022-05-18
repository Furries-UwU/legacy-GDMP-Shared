#pragma once
#include <string>

#include "enum.hpp"

struct Position {
    float x;
    float y;
    float rotation;
};

struct Color {
    byte red;
    byte green;
    byte blue;
};

struct IconData {
    int iconId;
    int iconIdCube; // used for ship & ufo
    Gamemode gamemode;
    float scale;
    bool glow;
    Color primaryColor;
    Color secondaryColor;
};

struct BaseRenderData {
    Position position;
    IconData iconData;
};

struct RenderData {
    BaseRenderData playerOne;
    BaseRenderData playerTwo;
    bool isDual;
    bool isVisible;
};

struct IncomingRenderData {
    int playerId;
    RenderData renderData;
};

struct IncomingUsername {
    int playerId;
    std::string username;
};