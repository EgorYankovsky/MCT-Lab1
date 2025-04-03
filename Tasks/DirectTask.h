#pragma once

#include "../Mesh/Mesh3D.h"
#include <memory>

class DirectTask {
private:
	Mesh3D* _mesh = nullptr_t();
public:
	DirectTask() {};
	DirectTask(Mesh3D mesh) {
		_mesh = &mesh;
	}
	~DirectTask() {};

	void solve();
};
