#include "Vector.h"

double_t norm(const Vector3D vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

Vector3D operator+(Vector3D v1, Vector3D v2) {
    return Vector3D(v1.x + v2.x, 
                    v1.y + v2.y, 
                    v1.z + v2.z);
}

void operator+=(Vector3D& v1, const Vector3D v2) {
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;
}
