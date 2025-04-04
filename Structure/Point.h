#pragma once

#include <cmath>

struct Point {
	double_t x;
	double_t y;
	double_t z;
	Point() : x(0.0), y(0.0), z(0.0) {};
	Point(double_t _x, double_t _y, double_t _z) : x(_x), y(_y), z(_z) {};
	~Point() {};
};