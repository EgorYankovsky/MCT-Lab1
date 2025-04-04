#pragma once


#include "../Mesh/Mesh3D.h"
#include "../Structure/Receiver.h"

class DirectTask {
private:
	static const std::string _receivers_data_path;
	static const std::string _output_result_path;
	Mesh3D* _mesh = nullptr_t();
	std::vector<Receiver>* _receivers = nullptr_t();
public:
	DirectTask() {};
	DirectTask(Mesh3D* mesh) {
		_mesh = mesh;
	}
	~DirectTask() {};

	void solve(std::string path_to_read_coordinates = _receivers_data_path);
	void foutput_result();
	void coutput_result();
};