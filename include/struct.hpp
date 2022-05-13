#pragma once
#include <string>

#include "enum.hpp"

struct ServerPlayerData
{
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

struct BaseRenderData
{
	bool m_isShip;
	bool m_isBird;
	bool m_isBall;
	bool m_isDart;
	bool m_isRobot;
	bool m_isSpider;
    bool m_isUpsideDown;
    bool m_isDashing;
    float posX;
	float posY;
    float rotation;
};

struct RenderData {
    BaseRenderData playerOne;
    BaseRenderData playerTwo;
    bool visible;
    bool dual;
};

// Client

struct ClientPlayerData
{
    unsigned int playerId;
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
    BaseRenderData playerOne;
    BaseRenderData playerTwo;
    bool visible;
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