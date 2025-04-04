#pragma once

#include <vector>

#include "Point.h"
#include "Vector.h"


struct Receiver {
	Point coordinates;
	Vector3D b_values;
	Receiver() { }
	Receiver(double_t x, double_t y, double_t z, double_t bx_value, double_t by_value, double_t bz_value) {
		coordinates.x = x;
		coordinates.y = y;
		coordinates.z = z;
		b_values.x = bx_value;
		b_values.y = by_value;
		b_values.z = bz_value;
	};
	~Receiver() {}
};