#include "DirectTask.h"

const std::string DirectTask::_receivers_data_path = "Data\\Input\\Receivers.txt";
const std::string DirectTask::_output_result_path = "Data\\Output\\DirectAnswer.txt";

void DirectTask::solve(std::string path_to_read_coordinates) {
    try {
        std::ifstream fin(path_to_read_coordinates);
        if (!fin.is_open()) throw std::runtime_error("Can't open file: " + path_to_read_coordinates);
        _receivers = new std::vector<Receiver>();
        size_t receivers_amount = 0;
        fin >> receivers_amount;
        for (size_t i(0); i < receivers_amount; ++i) {
            double_t x = 0, y = 0, z = 0;
            fin >> x >> y >> z;
            Vector3D b_i = _mesh->get_b_at(x, y, z);
            _receivers->emplace_back(x, y, z, b_i.x, b_i.y, b_i.z);
        }
        fin.close();
    }
    catch (const std::runtime_error& rterr) {
        std::cerr << "Runtime error: " << rterr.what();
        exit(EXIT_FAILURE);
    }
    catch (const std::exception& ex) {
        std::cerr << "Unexpected exception: " << ex.what() << " Potential program crash. Returned nullptr." << std::endl;
        _receivers = nullptr_t();
    }
}

void DirectTask::foutput_result() {
    try {
        std::ofstream fout(_output_result_path);
        for (size_t i(0); i < _receivers->size(); ++i)
            fout << _receivers->at(i).coordinates.x << " " << 
                    _receivers->at(i).coordinates.y << " " <<
                    _receivers->at(i).coordinates.z << " " <<
                    _receivers->at(i).b_values.x << " " <<
                    _receivers->at(i).b_values.y << " " <<
                    _receivers->at(i).b_values.z << " " << std::endl;
        fout.close();
    }
    catch (const std::runtime_error& rterr) {
        std::cerr << "Runtime error: " << rterr.what();
        exit(EXIT_FAILURE);
    }
    catch (const std::exception& ex) {
        std::cerr << "Unexpected exception: " << ex.what() << " Potential program crash. Returned nullptr." << std::endl;
        _receivers = nullptr_t();
    }
}

void DirectTask::coutput_result() {
    for (size_t i(0); i < _receivers->size(); ++i)
        std::cout << _receivers->at(i).coordinates.x << " " <<
                     _receivers->at(i).coordinates.y << " " <<
                     _receivers->at(i).coordinates.z << " " <<
                     _receivers->at(i).b_values.x << " " <<
                     _receivers->at(i).b_values.y << " " <<
                     _receivers->at(i).b_values.z << " " << std::endl;
}
