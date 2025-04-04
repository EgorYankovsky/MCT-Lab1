#include "MainHeader.h"

int main() {
    InputAreaConfig iac;
    std::ifstream fin;
    fin >> iac;
    Mesh3D mesh(iac);
    DirectTask dt(&mesh);
    dt.solve();
    dt.foutput_result();
    return 0;
}