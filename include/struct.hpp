#pragma once

#undef snprintf
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

struct PlayerData
{
    std::string username;
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