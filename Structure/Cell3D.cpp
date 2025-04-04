#include "Cell3D.h"

Vector3D Cell3D::get_b(double_t x, double_t y, double_t z) {
    Vector3D res;
    for (size_t i(0); i < 27; ++i) {
        double_t dx = x - gauss_points[i].x,
                 dy = y - gauss_points[i].y,
                 dz = z - gauss_points[i].z;
        double_t r = sqrt(dx * dx + dy * dy + dz * dz), r2 = 1.0 / (r * r);
        double_t coef = jacobian * gauss_weights[i] / (4.0 * M_PI * r * r * r);
        double_t bx = coef * (px * (3.0 * dx * dx * r2 - 1.0) + 
                              py * (3.0 * dx * dy * r2) + 
                              pz * (3.0 * dx * dz * r2));
        double_t by = coef * (px * (3.0 * dx * dy * r2) + 
                              py * (3.0 * dy * dy * r2 - 1.0) + 
                              pz * (3.0 * dy * dz * r2));
        double_t bz = coef * (px * (3.0 * dx * dz * r2) + 
                              py * (3.0 * dy * dz * r2) + 
                              pz * (3.0 * dz * dz * r2 - 1.0));
        res += Vector3D(bx, by, bz);
    }
    return res;
}
