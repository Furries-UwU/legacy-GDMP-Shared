#pragma once
#include <nlohmann/json.hpp>
#include <string>

#include "enum.hpp"

using json = nlohmann::json;

struct ServerPlayerData
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
    int posX;
    int posY;
    int rotation;
    bool flipped; // as in upside-down
    bool dual;
};

// Client

struct ClientPlayerData
{
    unsigned int playerId;
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

struct PlayerRenderData
{
    unsigned int playerId;
    Gamemode gamemode;
    int posX;
    int posY;
    int rotation;
    bool flipped; // as in upside-down
    bool dual;
};

struct PlayerJoinLevel
{
    unsigned int playerId;
};

struct PlayerLeaveLevel
{
    unsigned int playerId;
};

void to_json(json& j, const ServerPlayerData& p);
void from_json(const json& j, ServerPlayerData& p);

void to_json(json& j, const ClientPlayerData& p);
void from_json(const json& j, ClientPlayerData& p);