#pragma once

#include <cmath>

struct Cell3D {
	std::array<size_t, 8> points;
	double_t bx; double_t by; double_t bz;
	Cell3D() { bx = 0; by = 0; bz = 0; }
	Cell3D(std::array<size_t, 8> _points) : points(_points) { bx = 0; by = 0; bz = 0; }
};
