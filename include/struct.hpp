#pragma once
#include <string>

#include "enum.hpp"

struct ServerPlayerData
{
    unsigned int cube;
    unsigned int ship;
    unsigned int ball;
    unsigned int bird;
    unsigned int dart;
    unsigned int robot;
    unsigned int spider;
    unsigned int glow;
    int primaryColor;
    int secondaryColor;
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
    float m_playerSpeed;
    float posX;
	float posY;
    float rotation;
    float scale;
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
    unsigned int cube;
    unsigned int ship;
    unsigned int ball;
    unsigned int bird;
    unsigned int dart;
    unsigned int robot;
    unsigned int spider;
    unsigned int glow;
    int primaryColor;
    int secondaryColor;
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