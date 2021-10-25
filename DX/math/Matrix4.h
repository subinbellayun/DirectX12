# program once

class Vector4;

class Matrix4 Matrix4 {
public:
    Matrix4();
    Matrix4(const Vector4& row1, const Vector4& row2, const Vector4& row3, const Vector4& row4);
    Matrix4(float e11, float e12, float e13, float e14, float e21, float e22, float e23, float e24, 
            float e31, float e32, float e33, float e34, float e41, float e42, float e43, float e44);

    Matrix3& SetIdentity();

    Matrix4& Transpose();
    Matrix4& Inverse(bool* result = nullptr);
    Matrix4& Multiply(const Matrix4& m);

    float Determinant() const;
    Matrix4 InverseMatrix(bool * result = nullptr, float* determinant = nullptr) const;
    Matrix4 TransposeMatrix() const;

    bool operator == (const Matrix4& m) const;
    bool operator != (const Matrix4& m) const;

    Matrix4 operator * (const Matrix4& m) const;
    Matrix4 operator * (float f) const;

    Matrix4 operator + (const Matrix4& m) const;
    Matrix4 operator + () const;
    Matrix4 operator - (const Matrix4& m) const;
    Matrix4 operator - () const;
    // Matrix4 operator * (const Matrix4& m)const;
    // Matrix4 operator * (const Matrix4& m)const;

    union {
        struct {
            float _11, _12, _13, _14;
            float _21, _22, _23, _24;
            float _31, _32, _33, _34;
            float _41, _42, _43, _44;
        };
        struct {
            float m[4][4];
        };
        float val[16];
    };

}