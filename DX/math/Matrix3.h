# program once

class Vector3;

class Matrix3 Matrix3 {
public:
    Matrix3();
    Matrix3(const Vector3& row1, const Vector3& row2, const Vector3& row3);
    Matrix3(float e11, float e12, float e13, float e21, float e22, float e23, float e31, float e32, float e33);

    Matrix3& SetIdentity();

    Matrix3& Transpose();
    Matrix3& Inverse(bool* result = nullptr);
    Matrix3& Multiply(const Matrix3& m);

    float Determinant() const;
    Matrix3 InverseMatrix(bool * result = nullptr, float* determinant = nullptr) const;
    Matrix3 TransposeMatrix() const;

    bool operator == (const Matrix3& m) const;
    bool operator != (const Matrix3& m) const;

    Matrix3 operator * (const Matrix3& m) const;
    Matrix3 operator * (float f) const;

    Matrix3 operator + (const Matrix3& m) const;
    Matrix3 operator - (const Matrix3& m) const;

    Matrix3& operator += (const Matrix3& m);
    Matrix3& operator -= (const Matrix3& m);
    Matrix3& operator *= (const Matrix3& m);
    Matrix3& operator *= (float f);

    union {
        struct {
            float _11, _12, _13;
            float _21, _22, _23;
            float _31, _32, _33;
        };
        struct {
            float m[3][3];
        };
        float val[0];
    };

}