#pragma once
#include "Vector3.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "LinearTransform3.h"

class AffineTransform3 AffineTransform3
{
public:
    AffineTransform3();
    AffineTransform3(const Matrix4& m);

    bool operator == (const AffineTransform3& t) const;
    bool operator != (const AffineTransform3& t) const;

    AffineTransform3& Translate(float x, float y, float z);
    AffineTransform3& Translate(const Vector3& v);

    AffineTransform3& Multiply(const LinearTransform3& t);
    AffineTransform3& Multiply(const AffineTransform3& t);

    Matrix4 Matrix4() const;
    const Matrix3& Matrix3() const { return matrix3; }

    Matrix3 matrix3;
    Vector3 translation;
    
};