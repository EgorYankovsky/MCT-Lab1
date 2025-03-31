#include "MainHeader.h"

int main() {
    InputAreaConfig iac;
    std::ifstream fin;
    fin >> iac;
    Mesh3D mesh(iac);
    return 0;
}