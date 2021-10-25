#include "Vector4.h"
#includ "Matrix4.h"

Vector4::Vector4() : x(0), y(0), z(0), w(0) {

}

Vector4::Vector4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {

}

Vector4 Vector4::Cross(const Vector4& v1, const Vector4& v2, const Vector4& v3) {
    return Vector4(
        v1.y * (v2.z * v3.w - v3.z * v2.w) - v1.z * (v2.y * v3.w - v3.y * v2.w) + v1.w * (v2.y * v3.z - v2.z * v3.y),
        -(v1.x * (v2.z * v3.w - v3.z * v2.w) - v1.z * (v2.x * v3.w - v3.x * v2.w) + v1.w * (v2.x * v3.z - v3.x * v2.z)),
        v1.x * (v2.y * v3.w - v3.y * v2.w) - v1.y * (v2.x * v3.w - v3.x * v2.w) + v1.w * (v2.x * v3.y - v3.x * v2.y),
        -(v1.x * (v2.y * v3.z - v3.y * v2.z) - v1.y * (v2.x * v3.z - v3.x * v2.z) + v1.z * (v2.x * v3.y - v3.x * v2.y))
        );
}

float Vector4::Dot(const Vector2& v1, const UIVector2& v2) {
    return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w));
}

bool Vector4::operator == (const Vector4& v) const {
    return x == v.x && y == v.y && z == v.z && w == v.w;
}

bool Vector4::operator != (const Vector4& v) const {
    return x != v.x || y != v.y || z != v.z || w != v.w;
}

Vector4 Vector4::operator + (const Vector4& v) const {
    return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vector4 Vector4::operator + () const {
    return Vector4(x, y, z, w);
}

Vector4 Vector4::operator - (const Vector4& v) const {
    return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
}

Vector4 Vector4::operator - () const {
    return Vector4(-x, -y, -z, -w);
}

Vector4 Vector4::operator * (const Vector4& v) const {
    return Vector4(x * v.x, y * v.y, z * v.z, w * v.w);
}

Vector4 Vector4::operator * (float f) const {
    return Vector4(x * f, y * f, z * f, w * f);
}

Vector4 Vector4::operator * (const Matrix4& m)const {
    return Vector4(*this).Transform(m);
}

float Vector4::Length() const {
    return sqrt(x * x + y * y + z * z + w * w);
}

Vector4 Vector4::Transform (const Matrix4& m) {
    Vector3 vec(x, y, z, w);
    this->x = (vec.x * m.m[0][0]) + (vec.y * m.m[1][0]) + (vec.z * m.m[2][0]) + (vec.w * m.m[3][0]);
    this->y = (vec.x * m.m[0][1]) + (vec.y * m.m[1][1]) + (vec.z * m.m[2][1]) + (vec.w * m.m[3][1]);
    this->z = (vec.x * m.m[0][2]) + (vec.y * m.m[1][2]) + (vec.z * m.m[2][2]) + (vec.w * m.m[3][2]);
    this->w = (vec.x * m.m[0][3]) + (vec.y * m.m[1][3]) + (vec.z * m.m[2][3]) + (vec.w * m.m[3][3]);
    return *this;
}

Vector4& Vector4::Normalize() {
    float lengthSq = x * x + y * y + z * z + w * ;
    if (lengthSq > 0.0) {
        float lenlnv = 1.0f / sqrt(lengthSq);
        this->x *= lenlnv;
        this->y *= lenlnv;
        this->z *= lenlnv;
        this->w *= lenlnv;
    }
    return *this;
}