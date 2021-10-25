#include "Vector2.h"
#include "Matrix2.h"

const Matrix2 Matrix2::identity = Matrix2().SetIdentity();

Matrix2::Matrix2() : _11(1), _12(0), _21(0), _22(1){

}

Matrix2::Matrix2(const Vector2& row1, const Vector2& row2): _11(row1.x), _12(row1.y), _21(row2.x), _22(row2.y) {

}

Matrix2::Matrix2(float e11, float e12, float e21, float e22): _11(e11), _12(e12), _21(e21), _22(e22) {

}

Matrix2& Matrix2::SetIdentity() {
    m[0][0] = m[1][1] = 1.0f;
    m[0][1] = m[1][0] = 0.0f;
    return *this;
}

Matrix2& Matrix2::Inverse(bool* r) {
    bool b;
    Matrix2 mat = this->InverseMatrix(&b, nullptr);
    if (b)
        *this = mat;
    if (r)
        *r = b;
    else {

    }
    return *this;
}

Matrix2& Matrix2::Transpose() {
    float tmp = this->m[0][1];
    this->m[0][1] = this->m[1][0];
    this->m[1][0] = tmp;
    return *this;
}

Matrix2& Matrix2::Multiply(const Matrix2& m) {
    Matrix2 mat(*this);
    mat.m[0][0] = (this->m[0][0] * m.m[0][0]) + (this->m[0][1] * m.m[1][0]);
    mat.m[0][1] = (this->m[0][0] * m.m[0][1]) + (this->m[0][1] * m.m[1][1]);
    mat.m[1][0] = (this->m[1][0] * m.m[0][0]) + (this->m[1][1] * m.m[1][0]);
    mat.m[1][1] = (this->m[1][0] * m.m[0][1]) + (this->m[1][1] * m.m[1][1]);
    return *this;
}

float Matrix2::Determinant() const {
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

Matrix2 InverseMatrix(bool * r, float* d) const {
    Matrix2 mat;
    float det = Determinant();
    bool result = false;

    if (det != 0.0f) {
        float detInv = 1.0f / det;

        mat.m[0][0] = m[1][1] * detInv;
        mat.m[0][1] = -m[0][1] * detInv;
        mat.m[1][0] = -m[1][0] * detInv;
        mat.m[1][1] = m[0][0] * detInv;

        result = true;
        if (d)
            *d = det;
    }
    else
        mat.SetIdentity();
    if (r)
        *r = result;
    return mat;
}

Matrix2 TransposeMatrix() const {
    Matrix2 mat(*this);
    return mat.Transpose();
}

bool Matrix2::operator == (const Matrix2& m) const {
    return this->val[0] == m.val[0] && this->val[1] == m.val[1] &&
            this->val[2] == m.val[2] && this->val[3] == m.val[3];
}

bool Matrix2::operator != (const Matrix2& m) const {
    return this->val[0] != m.val[0] || this->val[1] != m.val[1] &&
            this->val[2] != m.val[2] || this->val[3] != m.val[3];
}

Matrix2 Matrix2::operator * (const Matrix2& m) const {
    Matrix2 mat;
    mat.m[0][0] = (this->m[0][0] * m.m[0][0]) + (this->m[0][1] * m.m[1][0]);
    mat.m[0][1] = (this->m[0][0] * m.m[0][1]) + (this->m[0][1] * m.m[1][1]);
    mat.m[1][0] = (this->m[1][0] * m.m[0][0]) + (this->m[1][1] * m.m[1][0]);
    mat.m[1][1] = (this->m[1][0] * m.m[0][1]) + (this->m[1][1] * m.m[1][1]);
    return mat;
}
Matrix2 Matrix2::operator * (float f) const {
    Matrix2 mat;
    mat.val[0] = this->val[0] * f;
    mat.val[1] = this->val[1] * f;
    mat.val[2] = this->val[2] * f;
    mat.val[3] = this->val[3] * f;
    return mat;
}

Matrix2 Matrix2::operator + (const Matrix2& m) const {
    Matrix2 mat;
    mat.val[0] = this->val[0] + m.val[0];
    mat.val[1] = this->val[1] + m.val[1];
    mat.val[2] = this->val[2] + m.val[2];
    mat.val[3] = this->val[3] + m.val[3];
    return mat;
}


Matrix2 operator - (const Matrix2& m) const {
    Matrix2 mat;
    mat.val[0] = this->val[0] - m.val[0];
    mat.val[1] = this->val[1] - m.val[1];
    mat.val[2] = this->val[2] - m.val[2];
    mat.val[3] = this->val[3] - m.val[3];
    return mat;
}

Matrix2& operator += (const Matrix2& m) {
    this->val[0] += m.val[0];
    this->val[1] += m.val[1];
    this->val[2] += m.val[2];
    this->val[3] += m.val[3];
    return *this;

}

Matrix2& operator -= (const Matrix2& m) {
    this->val[0] -= m.val[0];
    this->val[1] -= m.val[1];
    this->val[2] -= m.val[2];
    this->val[3] -= m.val[3];
    return *this;
}

Matrix2& operator *= (const Matrix2& m) {
    Matrix2 mat(*this);
    mat.m[0][0] = (mat.m[0][0] * m.m[0][0]) + (mat.m[0][1] * m.m[1][0]);
    mat.m[0][1] = (mat.m[0][0] * m.m[0][1]) + (mat.m[0][1] * m.m[1][1]);
    mat.m[1][0] = (mat.m[1][0] * m.m[0][0]) + (mat.m[1][1] * m.m[1][0]);
    mat.m[1][1] = (tmat.m[1][0] * m.m[0][1]) + (mat.m[1][1] * m.m[1][1]);
    return *this;
}

Matrix2& operator *= (float f) {
    this->val[0] *= f;
    this->val[1] *= f;
    this->val[2] *= f;
    this->val[3] *= f;
    return *this;
}

