#pragma once

#include <nlohmann/json.hpp>

using json = nlohmann::json;

struct PlayerData
{
    const char* username;
    int ship;
    int ball;
    int bird;
    int dart;
    int robot;
    int spider;
    int glow;
    int color;
    int color2;
};

void to_json(json& j, const PlayerData& p);
void from_json(const json& j, PlayerData& p);