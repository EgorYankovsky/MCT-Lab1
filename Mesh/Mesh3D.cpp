#include "Mesh3D.h"

bool Mesh3D::is_cell_inside_include(std::array<Point*, 8> points_int_refs, IncludeArea arr) {
    if (arr.x0 <= points_int_refs[0]->x && points_int_refs[7]->x <= arr.x1 &&
        arr.y0 <= points_int_refs[0]->y && points_int_refs[7]->y <= arr.y1 &&
        arr.z0 <= points_int_refs[0]->z && points_int_refs[7]->z <= arr.z1)
        return true;
    return false;
}

void Mesh3D::generate_points(const InputAreaConfig& iac) {
    double_t hx = (iac.x1 - iac.x0) / iac.delimeters_x,
             hy = (iac.y1 - iac.y0) / iac.delimeters_y,
             hz = (iac.z1 - iac.z0) / iac.delimeters_z;
    _points.resize((iac.delimeters_x + 1) * (iac.delimeters_y + 1) * (iac.delimeters_z + 1));
    for (size_t k(0), m(0); k <= iac.delimeters_z; ++k) {
        for (size_t j(0); j <= iac.delimeters_y; ++j) {
            for (size_t i(0); i <= iac.delimeters_x; ++i) {
                _points[m].x = iac.x0 + i * hx;
                _points[m].y = iac.y0 + j * hy;
                _points[m].z = iac.z0 + k * hz;
                ++m;
            }
        }
    }
}

void Mesh3D::generate_cells(const InputAreaConfig& iac) {
    auto nx = iac.delimeters_x + 1;
    auto nxy = (iac.delimeters_x + 1) * (iac.delimeters_y + 1);
    for (size_t k(0), m(0); k < iac.delimeters_z; ++k) {
        for (size_t j(0); j < iac.delimeters_y; ++j) {
            for (size_t i(0); i < iac.delimeters_x; ++i) {
                //std::array<size_t, 8> points_int_refs{
                //     k      * nxy +  j      * nx + i,
                //     k      * nxy +  j      * nx + i + 1,
                //     k      * nxy + (j + 1) * nx + i,
                //     k      * nxy + (j + 1) * nx + i + 1,
                //    (k + 1) * nxy +  j      * nx + i,
                //    (k + 1) * nxy +  j      * nx + i + 1,
                //    (k + 1) * nxy + (j + 1) * nx + i,
                //    (k + 1) * nxy + (j + 1) * nx + i + 1,
                //};

                std::array<Point*, 8> points_int_refs{
                     &_points[k * nxy + j * nx + i],
                     &_points[k * nxy + j * nx + i + 1],
                     &_points[k * nxy + (j + 1) * nx + i],
                     &_points[k * nxy + (j + 1) * nx + i + 1],
                     &_points[(k + 1) * nxy + j * nx + i],
                     &_points[(k + 1) * nxy + j * nx + i + 1],
                     &_points[(k + 1) * nxy + (j + 1) * nx + i],
                     &_points[(k + 1) * nxy + (j + 1) * nx + i + 1],
                };

                double_t bx_i(0), by_i(0), bz_i(0);
                for (const auto& include : iac.includes) {
                    if (is_cell_inside_include(points_int_refs, include)) {
                        bx_i = include.bx;
                        by_i = include.by;
                        bz_i = include.bz;
                    }
                }
                _cells.emplace_back(points_int_refs, bx_i, by_i, bz_i);
            }
        }
    }
}