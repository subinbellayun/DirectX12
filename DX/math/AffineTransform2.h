#pragma once
#include "Vector2.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include "LinearTransform2.h"

class AffineTransform2 AffineTransform2
{
public:
    AffineTransform2();
    AffineTransform2(const Matrix3& m);

    bool operator == (const AffineTransform2& t) const;
    bool operator != (const AffineTransform2& t) const;

    AffineTransform2& Translate(float x, float y);
    AffineTransform2& Translate(const Vector2& v);

    AffineTransform2& Multiply(const LinearTransform2& t);
    AffineTransform2& Multiply(const AffineTransform2& t);

    Matrix3 Matrix3() const;
    const Matrix2& Matrix2() const { return matrix2; }

    Matrix2 matrix2;
    Vector2 translation;
    
};