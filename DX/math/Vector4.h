# program once

class Matrix4;

class Vector4 Vector4 {
public:
    Vector4();
    Vector4(float x, float y, float z);

    static Vector4 Cross(const Vector4& v1, const Vector4& v2);
    static float Dot(const Vector4& v1, const Vector4& v2); 

    bool operator == (const Vector4& v) const;
    bool operator != (const Vector4& v) const;

    Vector4 operator + (const Vector4& v) const;
    Vector4 operator + () const;
    Vector4 operator - (const Vector4& v) const;
    Vector4 operator - () const;
    Vector4 operator * (const Vector4& v) const;
    Vector4 operator * (float f) const;
    Vector4 operator * (const Matrix4& m)const;

    float Length() const;

    Vector4& Transform(const Matrix4& m);
    Vector4& Normalize();

    union {
        struct {
            float x, y, z;
        };
        float val[3];
    };

}