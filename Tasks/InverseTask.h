#pragma once

#include "DirectTask.h"
#include "..\\MathObjects\\Matrix.h"
#include "..\\MathObjects\\Vector.h"
#include "..\\Structure\\ConfigurationInverse.h"

class InverseTask {
private:
	DirectTask* _direct_task;
	Matrix* _A;
	Matrix* _L;
	Vector* _b;
	InverseConfiguration _ic;

	static const std::string _configuration_path;

	void read_configuration();
public:
	InverseTask() {
		_direct_task = nullptr_t();
		_A = nullptr_t();
		_L = nullptr_t();
		_b = nullptr_t();
		std::cout << "Warning: null inverse task initialized." << std::endl;
		read_configuration();
	};
	InverseTask(DirectTask direct_task) {
		_direct_task = &direct_task;
		_A = new Matrix(3 * _direct_task->get_cells_amount());
		_L = new Matrix(3 * _direct_task->get_cells_amount());
		_b = new Vector(3 * _direct_task->get_cells_amount());
		read_configuration();
	}	
	~InverseTask() {
		delete _A, _b, _direct_task;
	};

	void solve();
};
