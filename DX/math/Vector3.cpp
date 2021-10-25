#include "Vector3.h"
#includ "Matrix3.h"
#includ "Matrix4.h"

Vector3::Vector3() : x(0), y(0), z(0) {

}

Vector3::Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {

}

Vector3 Vector3::Cross(const Vector3& v1, const Vector3& v2) {
    return Vector3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

float Vector3::Dot(const Vector2& v1, const UIVector2& v2) {
    return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

bool Vector3::operator == (const Vector3& v) const {
    return x == v.x && y == v.y && z == v.z;
}

bool Vector3::operator != (const Vector3& v) const {
    return x != v.x || y != v.y || z != v.z;
}

Vector3 Vector3::operator + (const Vector3& v) const {
    return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator + () const {
    return Vector3(x, y, z);
}

Vector3 Vector3::operator - (const Vector3& v) const {
    return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator - () const {
    return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator * (const Vector3& v) const {
    return Vector3(x * v.x, y * v.y, z * v.z);
}

Vector3 Vector3::operator * (float f) const {
    return Vector3(x * f, y * f, z * f);
}
Vector3 Vector3::operator * (const Matrix3& m)const {
    return Vector3(x, y, z).Transform(m);
}

Vector3 Vector3::operator * (const Matrix4& m)const {
    return Vector3(x, y, z).Transform(m);
}

float Vector3::Length() const {
    return sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::Transform (const Matrix3& m) {
    Vector3 vec(x, y, z);
    this->x = (vec.x * m.m[0][0]) + (vec.y * m.m[1][0]) + (vec.z * m.m[2][0]);
    this->y = (vec.x * m.m[0][1]) + (vec.y * m.m[1][1]) + (vec.z * m.m[2][1]);
    this->z = (vec.x * m.m[0][2]) + (vec.y * m.m[1][2]) + (vec.z * m.m[2][2]);
    return *this;
}

Vector3 Vector3::Transform (const Matrix4& m) {
    Vector3 vec(x, y, z);
    this->x = (vec.x * m.m[0][0]) + (vec.y * m.m[1][0]) + (vec.z * m.m[2][0]) + m.m[3][0];
    this->y = (vec.x * m.m[0][1]) + (vec.y * m.m[1][1]) + (vec.z * m.m[2][1]) + m.m[3][1];
    this->z = (vec.x * m.m[0][2]) + (vec.y * m.m[1][2]) + (vec.z * m.m[2][2]) + m.m[3][2];
    float w = 1.0f / ((vec.x * m.m[0][3]) + (vec.y * m.m[1][3]) + (vec.z * m.m[2][3]) + m.m[3][3]);

    this->x *= w;
    this->y *= w;
    this->z *= w;
    return *this;
}

Vector3& Vector3::Normalize() {
    float lengthSq = x * x + y * y + z * z;
    if (lengthSq > 0.0) {
        float lenlnv = 1.0f / sqrt(lengthSq);
        this->x *= lenlnv;
        this->y *= lenlnv;
        this->z *= lenlnv;
    }
    return *this;
}