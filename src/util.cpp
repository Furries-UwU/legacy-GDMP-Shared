#include "util.hpp"

uint32_t Util::uint8_t_to_uint32_t(uint8_t* number) {
	return number[0] | (number[1] << 8) | (number[2] << 16) | (number[3] << 24);
}

Gamemode Util::fromBitwise(short flags) {
	if ((flags & CUBE) == CUBE) {
		return CUBE;
	}
	else if ((flags & SHIP) == SHIP) {
		return SHIP;
	}
	else if ((flags & BALL) == BALL) {
		return BALL;
	}
	else if ((flags & UFO) == UFO) {
		return UFO;
	}
	else if ((flags & WAVE) == WAVE) {
		return WAVE;
	}
	else if ((flags & ROBOT) == ROBOT) {
		return ROBOT;
	}
	else if ((flags & SPIDER) == SPIDER) {
		return SPIDER;
	}
	else {
		return UNKNOWN;
	}
}

short Util::toBitwise(Gamemode gamemode) {
	switch (gamemode) {
	case CUBE:
		return CUBE;
	case SHIP:
		return SHIP;
	case BALL:
		return BALL;
	case UFO:
		return UFO;
	case WAVE:
		return WAVE;
	case ROBOT:
		return ROBOT;
	case SPIDER:
		return SPIDER;
	default:
		return UNKNOWN;
	}
}

short Util::toBitwise(bool isCube, bool isShip, bool isBall, bool isUFO, bool isWave, bool isRobot, bool isSpider) {
	short flags = 0;

	if (isCube)
		flags |= CUBE;

	if (isShip)
		flags |= SHIP;

	if (isBall)
		flags |= BALL;

	if (isUFO)
		flags |= UFO;

	if (isWave)
		flags |= WAVE;

	if (isRobot)
		flags |= ROBOT;

	if (isSpider)
		flags |= SPIDER;

	return flags;
}