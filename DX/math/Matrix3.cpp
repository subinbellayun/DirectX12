#include "Vector3.h"
#include "Matrix3.h"

const Matrix3 Matrix3::identity = Matrix3().SetIdentity();

Matrix3::Matrix3() : 
_11(1), _12(0), _13(0), 
_21(0), _22(1), _23(0), 
_31(0), _32(0), _33(1){

}

Matrix3::Matrix3(const Vector2& row1, const Vector2& row2, const Vector3& row3): 
_11(row1.x), _12(row1.y), _13(row1.z),
_21(row2.x), _22(row2.y), _23(row2.z), 
_31(row3.x), _32(row3.y), _33(row3.z) {

}

Matrix3::Matrix3(float e11, float e12, float e13, float e21, float e22, float e23, float e31, float e32, float e33): 
_11(e11), _12(e12), _13(e13),
_21(e23), _22(e22), _23(e23), 
_31(e31), _32(e32), _33(e33) {

}

Matrix3& Matrix3::SetIdentity() {
    m[0][0] = m[1][1] = m[2][2] = 1.0f;
    m[0][1] = m[0][2] = 0.0f;
    m[1][0] = m[1][2] = 0.0f;
    m[2][0] = m[2][1] = 0.0f;
    return *this;
}

Matrix3& Matrix3::Inverse(bool* r) {
    bool b;
    Matrix3 mat = this->InverseMatrix(&b, nullptr);
    if (b)
        *this = mat;
    if (r)
        *r = b;
    else {

    }
    return *this;
}

Matrix3& Matrix3::Transpose() {
    Matrix3 mat(*this);
    this->m[0][1] = mat.m[1][0];
    this->m[0][2] = mat.m[2][0];
    this->m[1][0] = mat.m[0][1];
    this->m[1][2] = mat.m[2][1];
    this->m[2][0] = mat.m[0][2];
    this->m[2][1] = mat.m[1][2];
    return *this;
}

Matrix3& Matrix3::Multiply(const Matrix3& m) {
    Matrix3 mat(*this);
    mat.m[0][0] = (mat.m[0][0] * m.m[0][0]) + (mat.m[0][1] * m.m[1][0]) + (mat.m[0][2] * m.m[2][0]);
    mat.m[0][1] = (mat.m[0][0] * m.m[0][1]) + (mat.m[0][1] * m.m[1][1]) + (mat.m[0][2] * m.m[2][1]);
    mat.m[0][2] = (mat.m[0][0] * m.m[0][2]) + (mat.m[0][1] * m.m[1][2]) + (mat.m[0][2] * m.m[2][2]);
    mat.m[1][0] = (mat.m[1][0] * m.m[0][0]) + (mat.m[1][1] * m.m[1][0]) + (mat.m[1][2] * m.m[2][0]);
    mat.m[1][1] = (mat.m[1][0] * m.m[0][1]) + (mat.m[1][1] * m.m[1][1]) + (mat.m[1][2] * m.m[2][1]);
    mat.m[1][2] = (mat.m[1][0] * m.m[0][2]) + (mat.m[1][1] * m.m[1][2]) + (mat.m[1][2] * m.m[2][2]);
    mat.m[2][0] = (mat.m[2][0] * m.m[0][0]) + (mat.m[2][1] * m.m[1][0]) + (mat.m[2][2] * m.m[2][0]);
    mat.m[2][1] = (mat.m[2][0] * m.m[0][1]) + (mat.m[2][1] * m.m[1][1]) + (mat.m[2][2] * m.m[2][1]);
    mat.m[2][2] = (mat.m[2][0] * m.m[0][2]) + (mat.m[2][1] * m.m[1][2]) + (mat.m[2][2] * m.m[2][2]);
    return *this;
}

float Matrix3::Determinant() const {
    return 
    m[0][0] * m[1][1] * m[2][2] +
    m[0][1] * m[1][2] * m[2][0] +
    m[0][2] * m[1][0] * m[2][1] - 
    m[0][0] * m[1][2] * m[2][1] -
    m[0][1] * m[1][0] * m[2][2] - 
    m[0][2] * m[1][1] * m[2][0];
}

Matrix3 InverseMatrix(bool * r, float* d) const {
    Matrix3 mat;
    float det = Determinant();
    bool result = false;

    if (det != 0.0f) {

        float detInv = 1.0f / det;

        mat.m[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) * detInv;
        mat.m[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) * detInv;
        mat.m[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * detInv;
        mat.m[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) * detInv;
        mat.m[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * detInv;
        mat.m[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) * detInv;
        mat.m[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) * detInv;
        mat.m[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) * detInv;
        mat.m[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) * detInv;

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

Matrix3 TransposeMatrix() const {
    Matrix3 mat(*this);
    return mat.Transpose();
}

bool Matrix3::operator == (const Matrix3& m) const {
    return this->val[0] == m.val[0] && this->val[1] == m.val[1] &&
            this->val[2] == m.val[2] && this->val[3] == m.val[3] &&
            this->val[4] == m.val[4] && this->val[5] == m.val[5] &&
            this->val[6] == m.val[6] && this->val[7] == m.val[7] &&
            this->val[8] == m.val[8];
}

bool Matrix3::operator != (const Matrix3& m) const {
    return this->val[0] != m.val[0] || this->val[1] != m.val[1] ||
            this->val[2] != m.val[2] || this->val[3] != m.val[3] ||
            this->val[4] != m.val[4] || this->val[5] != m.val[5] ||
            this->val[6] != m.val[6] || this->val[7] != m.val[7] ||
            this->val[8] != m.val[8];
}

Matrix3 Matrix3::operator * (const Matrix3& m) const {
    Matrix3 mat;
    mat.m[0][0] = (this->m[0][0] * m.m[0][0]) + (this->m[0][1] * m.m[1][0]) + (this->m[0][2] * m.m[2][0]);
    mat.m[0][1] = (this->m[0][0] * m.m[0][1]) + (this->m[0][1] * m.m[1][1]) + (this->m[0][2] * m.m[2][1]);
    mat.m[0][2] = (this->m[0][0] * m.m[0][2]) + (this->m[0][1] * m.m[1][2]) + (this->m[0][2] * m.m[2][2]);
    mat.m[1][0] = (this->m[1][0] * m.m[0][0]) + (this->m[1][1] * m.m[1][0]) + (this->m[1][2] * m.m[2][0]);
    mat.m[1][1] = (this->m[1][0] * m.m[0][1]) + (this->m[0][1] * m.m[1][1]) + (this->m[1][2] * m.m[2][1]);
    mat.m[1][2] = (this->m[1][0] * m.m[0][2]) + (this->m[1][1] * m.m[1][2]) + (this->m[1][2] * m.m[2][2]);
    mat.m[2][0] = (this->m[2][0] * m.m[0][0]) + (this->m[2][1] * m.m[1][0]) + (this->m[2][2] * m.m[2][0]);
    mat.m[2][1] = (this->m[2][0] * m.m[0][1]) + (this->m[2][1] * m.m[1][1]) + (this->m[2][2] * m.m[2][1]);
    mat.m[2][2] = (this->m[2][0] * m.m[0][2]) + (this->m[2][1] * m.m[1][2]) + (this->m[2][2] * m.m[2][2]);
    return mat;
}
Matrix3 Matrix3::operator * (float f) const {
    Matrix3 mat;
    mat.val[0] = this->val[0] * f;
    mat.val[1] = this->val[1] * f;
    mat.val[2] = this->val[2] * f;
    mat.val[3] = this->val[3] * f;
    mat.val[4] = this->val[4] * f;
    mat.val[5] = this->val[5] * f;
    mat.val[6] = this->val[6] * f;
    mat.val[7] = this->val[7] * f;
    mat.val[8] = this->val[8] * f;
    return mat;
}

Matrix3 Matrix3::operator + (const Matrix3& m) const {
    Matrix3 mat;
    mat.val[0] = this->val[0] + m.val[0];
    mat.val[1] = this->val[1] + m.val[1];
    mat.val[2] = this->val[2] + m.val[2];
    mat.val[3] = this->val[3] + m.val[3];
    mat.val[4] = this->val[4] + m.val[4];
    mat.val[5] = this->val[5] + m.val[5];
    mat.val[6] = this->val[6] + m.val[6];
    mat.val[7] = this->val[7] + m.val[7];
    mat.val[8] = this->val[8] + m.val[8];
    return mat;
}


Matrix3 operator - (const Matrix3& m) const {
    Matrix3 mat;
    mat.val[0] = this->val[0] - m.val[0];
    mat.val[1] = this->val[1] - m.val[1];
    mat.val[2] = this->val[2] - m.val[2];
    mat.val[3] = this->val[3] - m.val[3];
    mat.val[4] = this->val[4] - m.val[4];
    mat.val[5] = this->val[5] - m.val[5];
    mat.val[6] = this->val[6] - m.val[6];
    mat.val[7] = this->val[7] - m.val[7];
    mat.val[8] = this->val[8] - m.val[8];
    return mat;
}

Matrix3& operator += (const Matrix3& m) {
    this->val[0] += m.val[0];
    this->val[1] += m.val[1];
    this->val[2] += m.val[2];
    this->val[3] += m.val[3];
    this->val[4] += m.val[4];
    this->val[5] += m.val[5];
    this->val[6] += m.val[6];
    this->val[7] += m.val[7];
    this->val[8] += m.val[8];
    return *this;

}

Matrix3& operator -= (const Matrix3& m) {
    this->val[0] -= m.val[0];
    this->val[1] -= m.val[1];
    this->val[2] -= m.val[2];
    this->val[3] -= m.val[3];
    this->val[4] -= m.val[4];
    this->val[5] -= m.val[5];
    this->val[6] -= m.val[6];
    this->val[7] -= m.val[7];
    this->val[8] -= m.val[8];
    return *this;
}

Matrix3& operator *= (const Matrix3& m) {
    Matrix3 mat(*this);
    mat.m[0][0] = (this->m[0][0] * m.m[0][0]) + (this->m[0][1] * m.m[1][0]) + (this->m[0][2] * m.m[2][0]);
    mat.m[0][1] = (this->m[0][0] * m.m[0][1]) + (this->m[0][1] * m.m[1][1]) + (this->m[0][2] * m.m[2][1]);
    mat.m[0][2] = (this->m[0][0] * m.m[0][2]) + (this->m[0][1] * m.m[1][2]) + (this->m[0][2] * m.m[2][2]);
    mat.m[1][0] = (this->m[1][0] * m.m[0][0]) + (this->m[1][1] * m.m[1][0]) + (this->m[1][2] * m.m[2][0]);
    mat.m[1][1] = (this->m[1][0] * m.m[0][1]) + (this->m[0][1] * m.m[1][1]) + (this->m[1][2] * m.m[2][1]);
    mat.m[1][2] = (this->m[1][0] * m.m[0][2]) + (this->m[1][1] * m.m[1][2]) + (this->m[1][2] * m.m[2][2]);
    mat.m[2][0] = (this->m[2][0] * m.m[0][0]) + (this->m[2][1] * m.m[1][0]) + (this->m[2][2] * m.m[2][0]);
    mat.m[2][1] = (this->m[2][0] * m.m[0][1]) + (this->m[2][1] * m.m[1][1]) + (this->m[2][2] * m.m[2][1]);
    mat.m[2][2] = (this->m[2][0] * m.m[0][2]) + (this->m[2][1] * m.m[1][2]) + (this->m[2][2] * m.m[2][2]);
    return *this;
}

Matrix3& operator *= (float f) {
    this->val[0] *= f;
    this->val[1] *= f;
    this->val[2] *= f;
    this->val[3] *= f;
    this->val[4] *= f;
    this->val[5] *= f;
    this->val[6] *= f;
    this->val[7] *= f;
    this->val[8] *= f;
    return *this;
}

