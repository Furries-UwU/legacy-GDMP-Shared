#pragma once
#include <nlohmann/json.hpp>
#include <string>

#include "enum.hpp"

using json = nlohmann::json;

struct Position {
    float x;
    float y;
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
    float rotation;
    float scale;
    bool isShip;
    bool isBall;
    bool isUFO;
    bool isWave;
    bool isRobot;
    bool isSpider;
};

struct RenderData {
    BaseRenderData playerOne;
    BaseRenderData playerTwo;
    bool isDual;
    bool isVisible;
};

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

struct IncomingUsername {
    int playerId;
    std::string username;
};

////////////////////////////////////////////////////////////////////////////////

void to_json(json &j, const Position &p);
void from_json(const json &j, Position &p);

void to_json(json &j, const IconData &p);
void from_json(const json &j, IconData &p);

void to_json(json &j, const ColorData &p);
void from_json(const json &j, ColorData &p);

void to_json(json &j, const BaseRenderData &p);
void from_json(const json &j, BaseRenderData &p);

void to_json(json &j, const RenderData &p);
void from_json(const json &j, RenderData &p);

void to_json(json &j, const IncomingIconData &p);
void from_json(const json &j, IncomingIconData &p);

void to_json(json &j, const IncomingColorData &p);
void from_json(const json &j, IncomingColorData &p);

void to_json(json &j, const IncomingRenderData &p);
void from_json(const json &j, IncomingRenderData &p);

void to_json(json &j, const IncomingUsername &p);
void from_json(const json &j, IncomingUsername &p);