#pragma once
#include "Vector2.h"
#include "Matrix2.h"
#include "Matrix3.h"

class LinearTransform2 LinearTransform2
{
public:
    LinearTransform2();
    LinearTransform2(const Matrix2& m);

    bool operator == (const LinearTransform2& t) const;
    bool operator != (const LinearTransform2& t) const;

    LinearTransform2& Scale(const Vector2& v);
    LinearTransform2& Scale(float x, float y);
    
    LinearTransform2& Rotate(float angle);
    LinearTransform2& Multiply(const Matrix2& t);

    Matrix2& Matrix2() { return matrix2; }
    const Matrix2& Matrix2() const { return matrix2; }

    Matrix2 matrix2;
    
};