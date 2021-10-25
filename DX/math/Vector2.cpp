#include "Vector2.h"
#include "Matrix2.h"
#include "Matrix3.h"

Vector2::Vector2(): x(0), y(0){

}

Vector2::Vector2(float x_, float y_) : x(x_), y(y_) {

}

Vector2 Vector2::Cross(const Vector2& v1) {
    return Vector3(v1.x * v1.y);
}

float Vector2::Dot(const Vector2& v1, const UIVector2& v2) {
    return ((v1.x * v2.x) + (v1.y * v2.y));
}

bool Vector2::operator == (const Vector2& v) const {
    return x == v.x && y == v.y;
}

bool Vector2::operator != (const Vector2& v) const {
    return x != v.x || y != v.y;
}

Vector2 Vector2::operator + (const Vector2& v) const {
    return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator + () const {
    return Vector2(x, y);
}

Vector2 Vector2::operator - (const Vector2& v) const {
    return Vector2(x - v.x, y - v.y);
}

Vector2 Vector2::operator - () const {
    return Vector2(-x, -y);
}

Vector2 Vector2::operator * (const Vector2& v) const {
    return Vector2(x * v.x, y * v.y);
}

Vector2 Vector2::operator * (float f) const {
    return Vector2(x * f, y * f);
}
Vector2 Vector2::operator * (const Matrix2& m)const {
    return Vector2(x, y).Transform(m);
}

Vector2 Vector2::operator * (const Matrix3& m)const {
    return Vector2(x, y).Transform(m);
}

float Vector2::Length() const {
    return sqrt(x * x + y * y);
}

Vector2 Vector2::Transform (const Matrix2& m) {
    Vector2 vec(x, y);
    this->x = (vec.x * m.m[0][0]) + (vec.y * m.m[1][0]);
    this->y = (vec.x * m.m[0][1]) + (vec.y * m.m[1][1]);
    return *this;
}

Vector2 Vector2::Transform (const Matrix3& m) {
    Vector2 vec(x, y);
    this->x = (vec.x * m.m[0][0]) + (vec.y * m.m[1][0]) + m.m[2][0];
    this->y = (vec.x * m.m[0][1]) + (vec.y * m.m[1][1]) + m.m[2][1];
    float w = 1.0f / ((vec.x * m.m[0][2]) + (vec.y * m.m[1][2]) + m.m[2][2]);

    this->x *= w;
    this->y *= w;
    return *this;
}

Vector2& Vevtor2::Normalize() {
    float lengthSq = x * x + y * y;
    if (lengthSq > 0.0) {
        float lenlnv = 1.0f / sqrt(lengthSq);
        this->x *= lenlnv;
        this->y *= lenlnv;
    }
    return *this;
}