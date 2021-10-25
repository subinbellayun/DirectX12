#include "AffineTransform3.h"
#include "LinearTransform3.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"

AffineTransform3::AffineTransform3()
    : matrix3()
    , translation()
{
}

AffineTransform3::AffineTransform3(const Matrix4& m)
    : matrix3(m.m[0][0], m.m[0][1], m.m[0][2],
              m.m[1][0], m.m[1][1], m.m[1][2],
              m.m[2][0], m.m[2][1], m.m[2][2])
    , translation(m.m[3][0], m.m[3][1], m.m[3][2])
{
}

bool AffineTransform3::operator==(const AffineTransform3& t) const
{
    if (translation == t.translation)
        return matrix3 == t.matrix3;
    return false;
}

bool AffineTransform3::operator!=(const AffineTransform3& t) const
{
    if (translation != t.translation)
        return true;
    return matrix3 != t.matrix3;
}

AffineTransform3& AffineTransform3::Translate(float x, float y, float z)
{
    translation.x += x;
    translation.y += y;
    translation.z += z;
    return *this;
}

AffineTransform3& AffineTransform3::Translate(const Vector3& v)
{
    translation.x += v.x;
    translation.y += v.y;
    translation.z += v.z;
    return *this;
}

AffineTransform3& AffineTransform3::Multiply(const LinearTransform3& t)
{
    translation *= t.matrix3;
    matrix3 *= t.matrix3;
    return *this;
}

AffineTransform3& AffineTransform3::Multiply(const AffineTransform3& t)
{
    translation = translation * t.matrix3 + t.translation;
    matrix3 *= t.matrix3;
    return *this;
}

Matrix4 AffineTransform3::Matrix4() const
{
    return Matrix4{ matrix3.m[0][0], matrix3.m[0][1], matrix3.m[0][2], 0.f
           , matrix3.m[1][0], matrix3.m[1][1], matrix3.m[1][2], 0.f
           , matrix3.m[2][0], matrix3.m[2][1], matrix3.m[2][2], 0.f
           , translation.x, translation.y, translation.z, 1.0f };
}