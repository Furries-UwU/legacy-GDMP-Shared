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
    Gamemode playerOneGamemode;
    Gamemode playerTwoGamemode;
    int playerOneX;
    int playerTwoX;
    int playerOneY;
    int playerTwoY;
    int playerOneRotation;
    int playerTwoRotation;
    bool playerOneFlipped;
    bool playerTwoFlipped;
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
    Gamemode playerOneGamemode;
	Gamemode playerTwoGamemode;
    int playerOneX;
    int playerTwoX;
	int playerOneY;
	int playerTwoY;
	int playerOneRotation;
	int playerTwoRotation;
	bool playerOneFlipped;
	bool playerTwoFlipped;
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