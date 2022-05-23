#pragma once
#include <string>

#include "enum.hpp"

struct Position {
    float x;
    float y;
};

struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

struct ColorData {
    Color primaryColor;
    Color secondaryColor;
    bool glow;
};

struct IconData {
    int cubeId;
    int shipId;
    int ballId;
    int ufoId;
    int waveId;
    int robotId;
    int spiderId;
};

struct BaseRenderData {
    Position position;
    float rotation;
    Gamemode gamemode;
};

struct RenderData {
    BaseRenderData playerOne;
    BaseRenderData playerTwo;
    bool isDual;
    bool isVisible;
};

struct IncomingColorData {
    int playerId;
    ColorData colorData;
};

struct IncomingIconData {
    int playerId;
    IconData iconData;
};

struct IncomingRenderData {
    int playerId;
    RenderData renderData;
};

struct IncomingUsername {
    int playerId;
    std::string username;
};