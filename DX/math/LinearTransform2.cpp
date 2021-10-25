#include "LinearTransform2.h"
#include "Vector2.h"
#include "Vector3.h"

LinearTransform2::LinearTransform2()
    : matrix2()
{
}

LinearTransform2::LinearTransform2(const Matrix2& m)
    : matrix2(m)
{
}

bool LinearTransform2::operator==(const LinearTransform2& t) const
{
    return matrix2 == t.matrix2;
}

bool LinearTransform2::operator!=(const LinearTransform2& t) const
{
    return matrix2 != t.matrix2;
}

LinearTransform2& LinearTransform2::Scale(float x, float y)
{
    matrix2.m[0][0] *= x;
    matrix2.m[0][1] *= y;
    matrix2.m[1][0] *= x;
    matrix2.m[1][1] *= y;
    return *this;
}

LinearTransform2& LinearTransform2::Scale(const Vector2& v)
{
    return Scale(v.x, v.y);
}

LinearTransform2& LinearTransform2::Rotate(float angle)
{
    float cosR = cosf(angle);
    float sinR = sinf(angle);

    Matrix2 mat(cosR, sinR, -sinR, cosR);
    matrix2.Multiply(mat);
    return *this;
}

LinearTransform2& LinearTransform2::Multiply(const Matrix2& t)
{
    matrix2.Multiply(t);
    return *this;
}