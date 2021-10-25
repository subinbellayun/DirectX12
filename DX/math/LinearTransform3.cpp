#include "LinearTransform3.h"
#include "Vector3.h"
#include "Vector4.h"

LinearTransform3::LinearTransform3()
    : matrix3()
{
}

LinearTransform3::LinearTransform3(const Matrix3& m)
    : matrix3(m)
{
}

bool LinearTransform3::operator==(const LinearTransform3& t) const
{
    return matrix3 == t.matrix3;
}

bool LinearTransform3::operator!=(const LinearTransform3& t) const
{
    return matrix3 != t.matrix3;
}

LinearTransform3& LinearTransform3::Scale(float x, float y, float z)
{
    matrix3.m[0][0] *= x;
    matrix3.m[0][1] *= y;
    matrix3.m[0][2] *= z;
    matrix3.m[1][0] *= x;
    matrix3.m[1][1] *= y;
    matrix3.m[1][2] *= z;
    matrix3.m[2][0] *= x;
    matrix3.m[2][1] *= y;
    matrix3.m[2][2] *= z;
    return *this;
}

LinearTransform3& LinearTransform3::Scale(const Vector3& v)
{
    return Scale(v.x, v.y, v.z);
}

LinearTransform3& LinearTransform3::RotateX(float r)
{
    float cosR = cos(r);
    float sinR = sin(r);
    
    Matrix3 mat;
    mat.SetIdentity();
    mat.m[1][1] = cosR;
    mat.m[1][2] = sinR;
    mat.m[2][1] = -sinR;
    mat.m[2][2] = cosR;
    matrix3.Multiply(mat);
    return *this;

}

LinearTransform3& LinearTransform3::RotateY(float r)
{
    float cosR = cos(r);
    float sinR = sin(r);
    
    Matrix3 mat;
    mat.SetIdentity();
    mat.m[0][0] = cosR;
    mat.m[0][2] = -sinR;
    mat.m[2][0] = sinR;
    mat.m[2][2] = cosR;
    matrix3.Multiply(mat);
    return *this;
}

LinearTransform3& LinearTransform3::RotateZ(float r)
{
    float cosR = cos(r);
    float sinR = sin(r);
    
    Matrix3 mat;
    mat.SetIdentity();
    mat.m[0][0] = cosR;
    mat.m[0][1] = sinR;
    mat.m[1][0] = -sinR;
    mat.m[1][1] = cosR;
    matrix3.Multiply(mat);
    return *this;
}

LinearTransform3& LinearTransform3::Rotate(const Vector3& axis, float r)
{
    float cosR = cos(r);
    float sinR = sin(r);
    float revCos = 1.f - cosR;
    matrix3 *= Matrix3{ cosR + revCos * (axis.x * axis.x),
                          revCos * (axis.x * axis.y) + (sinR * axis.z),
                          revCos * (axis.x * axis.z) - (sinR * axis.y),
                          revCos * (axis.x * axis.y) - (sinR * axis.z),
                          cosR + revCos * (axis.y * axis.y),
                          revCos * (axis.y * axis.z) + (sinR * axis.x),
                          revCos * (axis.x * axis.z) + (sinR * axis.y),
                          revCos * (axis.y * axis.z) - (sinR * axis.x),
                          cosR + revCos * (axis.z * axis.z) };
    return *this;
}

LinearTransform3& LinearTransform3::Multiply(const Matrix3& t)
{
    matrix2.Multiply(t);
    return *this;
}