# program once
#include ""

class Matrix3;
class Matrix4;

class Vector3 Vector3 {
public:
    Vector3();
    Vector3(float x, float y, float z);

    static Vector3 Cross(const Vector3& v1, const Vector3& v2); // < cross product
    static float Dot(const Vector3& v1, const Vector3& v2); // < dot product

    bool operator == (const Vector3& v) const;
    bool operator != (const Vector3& v) const;

    Vector3 operator + (const Vector3& v) const;
    Vector3 operator + () const;
    Vector3 operator - (const Vector3& v) const;
    Vector3 operator - () const;
    Vector3 operator * (const Vector3& v) const;
    Vector3 operator * (float f) const;
    Vector3 operator * (const Matrix3& m)const;
    Vector3 operator * (const Matrix4& m)const;

    float Length() const;

    Vector3& Transform(const Matrix3& m); // < Linear Transform
    Vector3& Transform(const Matrix4& m); // < Homogeneous Transform
    Vector3& Normalize();

    union {
        struct {
            float x, y, z;
        };
        float val[3];
    };

}