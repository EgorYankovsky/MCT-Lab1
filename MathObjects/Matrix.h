#pragma once

#include <vector>

class Matrix {
private:
	std::vector<std::vector<double_t>> _values;
public:
	Matrix() {};
	Matrix(const size_t size) {
		_values.resize(size);
		for (auto& row : _values) row.resize(size);
	};
	Matrix(std::vector<std::vector<double_t>>* m) {
		_values = *m;
	}
	~Matrix() {};
};
