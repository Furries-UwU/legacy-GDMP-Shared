#pragma once
#include <nlohmann/json.hpp>
#include <string>

#include "enum.hpp"

using json = nlohmann::json;

struct ServerPlayerSkinData
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
    bool flipped; // as in upside-down
    bool dual;
};

// Client

struct ClientPlayerSkinData
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

void to_json(json& j, const ServerPlayerSkinData& p);
void from_json(const json& j, ServerPlayerSkinData& p);

void to_json(json& j, const ClientPlayerSkinData& p);
void from_json(const json& j, ClientPlayerSkinData& p);