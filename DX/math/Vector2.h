# program once

class Matrix2;
class Matrix3;

class Vector2 Vector2 {
public:
    Vector2();
    Vector2(float x, float y);

    static Vector2 Cross(const Vector2& v1);
    static float Dot(const Vector2& v1, const Vector2& v2);

    bool operator == (const Vector2& v) const;
    bool operator != (const Vector2& v) const;

    Vector2 operator + (const Vector2& v) const;
    Vector2 operator + () const;
    Vector2 operator - (const Vector2& v) const;
    Vector2 operator - () const;
    Vector2 operator * (const Vector2& v) const;
    Vector2 operator * (float f) const;
    Vector2 operator * (const Matrix2& m)const;
    Vector2 operator * (const Matrix3& m)const;

    float Length() const;

    Vector2& Transform(const Matrix2& m);
    Vector2& Transform(const Matrix3& m);
    Vector2& Normalize();

    union {
        struct {
            float x, y;
        };
        float val[2];
    };

}