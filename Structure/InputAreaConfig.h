#pragma once

#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <array>

#include "..\\Structure\IncludeArea.h"

struct InputAreaConfig {
	const std::string kdefault_path = "Data\\Input\\InputArea.txt";
	double_t x0; double_t x1; size_t delimeters_x;
	double_t y0; double_t y1; size_t delimeters_y;
	double_t z0; double_t z1; size_t delimeters_z;
	size_t includes_amount;
	std::vector<IncludeArea> includes;

	InputAreaConfig() {
		x0 = 0; x1 = 0; delimeters_x = 0;
		y0 = 0; y1 = 0; delimeters_y = 0;
		z0 = 0; z1 = 0; delimeters_z = 0;
		includes_amount = 0;
	}
	~InputAreaConfig() {}

	friend void operator>>(std::ifstream& is, InputAreaConfig& iac) {
		try {
			is.open(iac.kdefault_path);
			if (not is.is_open()) throw std::runtime_error("Can't open file " + iac.kdefault_path);
			is >> iac.x0 >> iac.x1 >>
				iac.y0 >> iac.y1 >>
				iac.z0 >> iac.z1 >>
				iac.delimeters_x >> iac.delimeters_y >> iac.delimeters_z >>
				iac.includes_amount;
			iac.includes.resize(iac.includes_amount);
			for (size_t i(0); i < iac.includes_amount; ++i)
				is >> iac.includes[i].x0 >> iac.includes[i].x1 >>
				iac.includes[i].y0 >> iac.includes[i].y1 >>
				iac.includes[i].z0 >> iac.includes[i].z1 >>
				iac.includes[i].px >> iac.includes[i].py >> iac.includes[i].pz;
			is.close();
		}
		catch (const std::runtime_error& rterr) {
			std::cerr << "Runtime error: " + std::string(rterr.what());
			exit(EXIT_FAILURE);
		}
		catch (const std::exception& ex) {
			std::cerr << "Unexpected error: " + std::string(ex.what());
		}
	}
};