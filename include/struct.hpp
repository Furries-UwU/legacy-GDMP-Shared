#pragma once
#include <string>

#include "enum.hpp"

struct Position {
    float x;
    float y;
};

struct BaseRenderData {
    Position position;
    float rotation;
    float scale;
    bool isShip;
    bool isBall;
    bool isUFO;
    bool isWave;
    bool isRobot;
    bool isSpider;
    int primaryColor;
    int secondaryColor;
    bool glow;
    int iconId;
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