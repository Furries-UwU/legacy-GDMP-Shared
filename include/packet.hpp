#pragma once

struct Packet {
	uint8_t type;
	uint length;
	uint8_t *data;
}

struct PlayerData
{
    const char *username;
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