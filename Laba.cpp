#include "MainHeader.h"

int main() {
    InputAreaConfig iac;
    std::ifstream fin;
    fin >> iac;
    
    Mesh3D mesh(iac);

    // Direct task problem list:
    //      1. According to 10 y.o. work, my answer at Bx should be in 10**7 greater than current.
    DirectTask dt(&mesh);
    dt.solve();
    dt.foutput_result(/*default path as argument: Data\Output\*/);
    dt.draw_answer();
    
    InverseTask it(dt);
    return 0;
}