#pragma once
#include "Vector3.h"
#include "Matrix3.h"
#include "Matrix4.h"

class LinearTransform3 LinearTransform3
{
public:
    LinearTransform3();
    LinearTransform3(const Matrix3& m);

    bool operator == (const LinearTransform3& t) const;
    bool operator != (const LinearTransform3& t) const;

    LinearTransform3& Scale(const Vector3& v);
    LinearTransform3& Scale(float x, float y, float z);
    
    LinearTransform3& RotateX(float r);
    LinearTransform3& RotateY(float r);
    LinearTransform3& RotateZ(float r);
    LinearTransform3& Rotate(const Vector3& axis, float r);

    LinearTransform3& Multiply(const Matrix3& t);

    Matrix3& Matrix3() { return matrix3; }
    const Matrix3& Matrix3() const { return matrix3; }

    Matrix3 matrix3;
    
};