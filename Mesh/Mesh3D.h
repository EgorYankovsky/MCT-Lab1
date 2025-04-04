#pragma once

#include <vector>

#include "../Structure/InputAreaConfig.h"
#include "../Structure/Point.h"
#include "../Structure/Cell3D.h"
#include "../Structure/Vector.h"

class Mesh3D {
private:
	bool _is_generated;
	std::vector<double_t> _x;
	std::vector<double_t> _y;
	std::vector<double_t> _z;
	
	std::vector<Point> _points;
	std::vector<Cell3D> _cells;

	// Add data for includes here.

	bool is_cell_inside_include(std::array<Point*, 8> points_int_refs, IncludeArea arr);
public:
	Mesh3D() {
		_x = {};
		_y = {};
		_z = {};
		_points = {};
		_is_generated = false;
		std::cout << "Warning! Mesh is empty, input area configuration isn't initialized" << std::endl; 
	}

	Mesh3D(const InputAreaConfig& iac) {
		_x = {};
		_y = {};
		_z = {};
		_points = {};
		generate_points(iac);
		generate_cells(iac);
		_is_generated = true;
	}

	~Mesh3D() {}

	void generate_points(const InputAreaConfig& iac);
	void generate_cells(const InputAreaConfig& iac);

	Vector3D get_b_at(double_t x, double_t y, double_t z);
};
