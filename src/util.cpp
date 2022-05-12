#include "util.hpp"

int Util::uint8_t_to_int(uint8_t* number) {
	return number[0] | (number[1] << 8) | (number[2] << 16) | (number[3] << 24);
}