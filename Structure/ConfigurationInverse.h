#pragma once


struct InverseConfiguration {
	size_t param1 = 0;
	size_t param2 = 1;
	double_t eps1 = 1e-15;
	double_t param3 = 2.0;
	double_t param4 = 10.0;
	double_t eps2 = 1e-15;
	double_t param5 = 2.0;
	double_t param6 = 0.01;
	double_t eps3 = 1e-5;

	friend void operator>> (std::ifstream fin, InverseConfiguration& ic) {
		/*Write reading here.*/
	}
} default_configuration;
