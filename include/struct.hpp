#pragma once
#include "enum.hpp"

struct Position {
    int x;
    int y;
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

struct ColorData {
    int primaryColor;
    int secondaryColor;
    bool glow;
};

struct BaseRenderData {
    Position position;
    int rotation;
    int scale;
    bool isShip;
    bool isBall;
    bool isUFO;
    bool isWave;
    bool isRobot;
    bool isSpider;
};

struct RenderData {
    int playerId;
    BaseRenderData playerOne;
    BaseRenderData playerTwo;
    bool isDual;
    bool isVisible;
};

// Used by server to send to client

struct IncomingIconData {
    int playerId;
    IconData iconData;
};

struct IncomingColorData {
    int playerId;
    ColorData colorData;
};

struct IncomingRenderData {
    int playerId;
    RenderData renderData;
};