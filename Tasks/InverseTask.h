#pragma once

#include "DirectTask.h"

class InverseTask {
private:
	DirectTask* _direct_task = nullptr_t();
public:
	InverseTask() {};
	InverseTask(DirectTask direct_task) {
		_direct_task = &direct_task;
	}	
	~InverseTask() {};

	void solve();
};
