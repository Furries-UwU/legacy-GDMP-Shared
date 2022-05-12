#pragma once
#include <nlohmann/json.hpp>
#include <string>

#include "enum.hpp"

using json = nlohmann::json;

struct PlayerData
{
    std::string username;
    unsigned int ship;
    unsigned int ball;
    unsigned int bird;
    unsigned int dart;
    unsigned int robot;
    unsigned int spider;
    unsigned int glow;
    unsigned int color;
    unsigned int color2;
};

struct RenderData
{
    Gamemode gamemode;
    unsigned int posX;
    unsigned int posY;
    unsigned int rotation;
    bool flipped;
    bool dual;
};

void to_json(json& j, const PlayerData& p);
void from_json(const json& j, PlayerData& p);