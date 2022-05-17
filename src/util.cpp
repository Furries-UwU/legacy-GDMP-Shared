#include "util.hpp"

uint32_t Util::uint8_t_to_uint32_t(const uint8_t* number) {
	return number[0] | (number[1] << 8) | (number[2] << 16) | (number[3] << 24);
}