#pragma once

#include <cmath>

struct Vector3D {
	double_t x;
	double_t y;
	double_t z;
	Vector3D() : x(0.0), y(0.0), z(0.0) {}
	Vector3D(double_t _x, double_t _y, double_t _z) : x(_x), y(_y), z(_z) {}
	~Vector3D() {};
};

double_t norm(const Vector3D vec);
Vector3D operator+ (Vector3D v1, Vector3D v2);
void operator+= (Vector3D& v1, const Vector3D v2);
