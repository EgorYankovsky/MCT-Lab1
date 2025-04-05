#pragma once

#include <vector>

class Vector {
private:
	std::vector<double_t> _values;
public:
	Vector() {};
	Vector(const size_t size) {
		_values.resize(size);
	}
	Vector(std::vector<double_t>* v) {
		_values = *v;
	};
	~Vector() {};
};
