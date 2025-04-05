#include "InverseTask.h"

const std::string _configuration_path = "\\Data\\Input\\ConfigurationInverseTask.txt";

void InverseTask::read_configuration() {
	try {
		std::ifstream fin(_configuration_path);
		if (!fin.is_open()) throw std::runtime_error("Can't open file.");

		fin.close();
	}
	catch (const std::runtime_error& rterr) {
		std::cerr << "Runtime error: " << rterr.what() << "Default parameters set." << std::endl;
		_ic = default_configuration;
	}
	catch (const std::exception& ex) {
		std::cerr << "Unexpected exception: " << ex.what() << "Default parameters set." << std::endl;
		_ic = default_configuration;
	}
}

void InverseTask::solve() {

}
