#pragma once

#include <cmath>
#include "Point.h"

struct Cell3D {
private:
	const std::array<double_t, 3> kgauss_points_1dim = { -1.0 * sqrt(0.6), 0.0, sqrt(0.6) };
	const std::array<double_t, 3> kgauss_weights_1dim = { 5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0 };

	void init() {
		baricenter.x = 0.5 * (points[7]->x + points[0]->x);
		baricenter.y = 0.5 * (points[7]->y + points[0]->y);
		baricenter.z = 0.5 * (points[7]->z + points[0]->z);

		for (size_t i = 0; i < 3; i++)
			for (size_t j = 0; j < 3; j++)
				for (size_t k = 0; k < 3; k++)
				{
					gauss_weights[/*i * j * k*/(i * 3 + j) * 3 + k] = kgauss_weights_1dim[i] * 
																	  kgauss_weights_1dim[j] * 
																      kgauss_weights_1dim[k];

					gauss_points[/*i * j * k*/(i * 3 + j) * 3 + k].x = kgauss_points_1dim[i];
					gauss_points[/*i * j * k*/(i * 3 + j) * 3 + k].y = kgauss_points_1dim[j];
					gauss_points[/*i * j * k*/(i * 3 + j) * 3 + k].z = kgauss_points_1dim[k];
				}
		jacobian = mes / 8.0;
		for (size_t j = 0; j < 27; j++)
		{
			gauss_points[j].x = (gauss_points[j].x + 1.0) * (points[7]->x - points[0]->x) / 2.0 + points[0]->x;
			gauss_points[j].y = (gauss_points[j].y + 1.0) * (points[7]->y - points[0]->y) / 2.0 + points[0]->y;
			gauss_points[j].z = (gauss_points[j].z + 1.0) * (points[7]->z - points[0]->z) / 2.0 + points[0]->z;
		}
	}

public:
	std::array<Point, 27> gauss_points;
	std::array<double_t, 27> gauss_weights;
	std::array<Point*, 8> points;
	Point baricenter;
	double_t mes;
	double_t jacobian;
	double_t bx; double_t by; double_t bz;
	Cell3D() { bx = 0; by = 0; bz = 0; points = {}; }
	Cell3D(std::array<Point*, 8> _points) : points(_points) { bx = 0; by = 0; bz = 0; mes = 0; }
	Cell3D(std::array<Point*, 8> _points, double_t _bx, double_t _by, double_t _bz) : 
		points(_points), bx(_bx), by(_by), bz(_bz) {
		mes = (points[7]->x - points[0]->x) * 
			  (points[7]->y - points[0]->y) * 
			  (points[7]->z - points[0]->z);
		init();
	}
};