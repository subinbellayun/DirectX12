#include "AffineTransform2.h"
#include "LinearTransform2.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3.h"

AffineTransform2::AffineTransform2()
    : matrix2()
    , translation()
{
}

AffineTransform2::AffineTransform2(const Matrix3& m)
    : matrix2(m.m[0][0], m.m[0][1],
              m.m[1][0], m.m[1][1])
    , translation(m.m[2][0], m.m[2][1])
{
}

bool AffineTransform2::operator==(const AffineTransform2& t) const
{
    if (translation == t.translation)
        return matrix2 == t.matrix2;
    return false;
}

bool AffineTransform2::operator!=(const AffineTransform2& t) const
{
    if (translation != t.translation)
        return true;
    return matrix2 != t.matrix2;
}

AffineTransform2& AffineTransform2::Translate(float x, float y)
{
    translation.x += x;
    translation.y += y;
    return *this;
}

AffineTransform2& AffineTransform2::Translate(const Vector2& v)
{
    translation.x += v.x;
    translation.y += v.y;
    return *this;
}

AffineTransform2& AffineTransform2::Multiply(const AffineTransform2& t)
{
    translation *= t.matrix2;
    matrix2 *= t.matrix2;
    return *this;
}

AffineTransform2& AffineTransform2::Multiply(const AffineTransform2& t)
{
    translation = translation * t.matrix2 + t.translation;
    matrix2 *= t.matrix2;
    return *this;
}

Matrix3 AffineTransform2::Matrix3() const
{
    return Matrix3{ matrix2.m[0][0], matrix2.m[0][1], 0.f
           , matrix2.m[1][0], matrix2.m[1][1], 0.f
           , translation.x, translation.y, 1.0f};
}