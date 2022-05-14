#pragma once
#include <stdint.h>
#include "enum.hpp"

class Util {
public:
	static uint32_t uint8_t_to_uint32_t(uint8_t* number);
	static Gamemode fromBitwise(short flags);
	static short toBitwise(Gamemode gamemode);
	static short toBitwise(bool isShip, bool isBall, bool isUFO, bool isWave, bool isRobot, bool isSpider);
};