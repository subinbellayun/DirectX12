# program once

class Vector2;

class Matrix2 Matrix2 {
public:
    Matrix2();
    Matrix2(const Vector2& row1, const Vector2& row2);
    Matrix2(float e11, float e12, float e21, float e22);

    Matrix2& SetIdentity();

    Matrix2& Transpose();
    Matrix2& Inverse(bool* result = nullptr);
    Matrix2& Multiply(const Matrix2& m);

    float Determinant() const;
    Matrix2 InverseMatrix(bool * result = nullptr, float* determinant = nullptr) const;
    Matrix2 TransposeMatrix() const;

    bool operator == (const Matrix2& m) const;
    bool operator != (const Matrix2& m) const;

    Matrix2 operator * (const Matrix2& m) const;
    Matrix2 operator * (float f) const;

    Matrix2 operator + (const Matrix2& m) const;
    Matrix2 operator - (const Matrix2& m) const;

    Matrix2& operator += (const Matrix2& m);
    Matrix2& operator -= (const Matrix2& m);
    Matrix2& operator *= (const Matrix2& m);
    Matrix2& operator *= (float f);

    union {
        struct {
            float _11, _12;
            float _21, _22;
        };
        struct {
            float m[2][2];
        };
        float val[4];
    };

}