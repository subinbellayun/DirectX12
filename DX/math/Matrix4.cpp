#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"

const Matrix4 Matrix4::identity = Matrix4().SetIdentity();

Matrix4::Matrix4() : 
_11(1), _12(0), _13(0), _14(0),
_21(0), _22(1), _23(0), _23(0),
_31(0), _32(0), _33(1), _34(0),
_41(0), _43(0), _43(0), _44(1) {

}

Matrix4:: Matrix4(const Vector4& row1, const Vector4& row2, const Vector4& row3, const Vector4& row4): 
_11(row1.x), _12(row1.y), _13(row1.z), _14(row1.w),
_21(row2.x), _22(row2.y), _23(row2.z), _24(row2.w),
_31(row3.x), _32(row3.y), _33(row3.z), _34(row3.w),
_41(row4.x), _42(row4.y), _43(row4.z), _44(row4.w) {

}

Matrix4:: Matrix4(float e11, float e12, float e13, float e14, float e21, float e22, float e23, float e24, 
            float e31, float e32, float e33, float e34, float e41, float e42, float e43, float e44): 
_11(e11), _12(e12), _13(e13), _14(e14),
_21(e23), _22(e22), _23(e23), _24(e24),
_31(e31), _32(e32), _33(e33), _34(e34),
_41(e41), _42(e42), _43(e43), _44(e44) {

}

Matrix4& Matrix4::SetIdentity() {
    m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0f;
    m[0][1] = m[0][2] = m[0][3] = m[1][0] = 0.0f;
    m[1][2] = m[1][3] = m[2][0] = m[2][1] = 0.0f;
    m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
    return *this;
}

Matrix4& Matrix4::Inverse(bool* r) {
    bool b;
    Matrix4 mat = this->InverseMatrix(&b, nullptr);
    if (b)
        *this = mat;
    if (r)
        *r = b;
    else {

    }
    return *this;
}

Matrix4& Matrix4::Transpose() {
    
    Matrix4 mat(*this);

    this->m[0][1] = mat.m[1][0];
    this->m[0][2] = mat.m[2][0];
    this->m[0][3] = mat.m[3][0];

    this->m[1][0] = mat.m[0][1];
    this->m[1][2] = mat.m[2][1];
    this->m[1][3] = mat.m[3][1];

    this->m[2][0] = mat.m[0][2];
    this->m[2][1] = mat.m[1][2];
    this->m[2][3] = mat.m[3][2];

    this->m[3][0] = mat.m[0][3];
    this->m[3][1] = mat.m[1][3];
    this->m[3][2] = mat.m[2][3];

    return *this;
}

Matrix4& Matrix4::Multiply(const Matrix4& m) {

    Matrix4 mat(*this);

    mat.m[0][0] = (mat.m[0][0] * m.m[0][0]) + (mat.m[0][1] * m.m[1][0]) + (mat.m[0][2] * m.m[2][0]) + (mat.m[0][3] * m.m[3][0]);
    mat.m[0][1] = (mat.m[0][0] * m.m[0][1]) + (mat.m[0][1] * m.m[1][1]) + (mat.m[0][2] * m.m[2][1]) + (mat.m[0][3] * m.m[3][1]);
    mat.m[0][2] = (mat.m[0][0] * m.m[0][2]) + (mat.m[0][1] * m.m[1][2]) + (mat.m[0][2] * m.m[2][2]) + (mat.m[0][3] * m.m[3][2]);
    mat.m[0][3] = (mat.m[0][0] * m.m[0][3]) + (mat.m[0][1] * m.m[1][3]) + (mat.m[0][2] * m.m[2][3]) + (mat.m[0][3] * m.m[3][3]);

    mat.m[1][0] = (mat.m[1][0] * m.m[0][0]) + (mat.m[1][1] * m.m[1][0]) + (mat.m[1][2] * m.m[2][0]) + (mat.m[1][3] * m.m[3][0]);
    mat.m[1][1] = (mat.m[1][0] * m.m[0][1]) + (mat.m[1][1] * m.m[1][1]) + (mat.m[1][2] * m.m[2][1]) + (mat.m[1][3] * m.m[3][1]);
    mat.m[1][2] = (mat.m[1][0] * m.m[0][2]) + (mat.m[1][1] * m.m[1][2]) + (mat.m[1][2] * m.m[2][2]) + (mat.m[1][3] * m.m[3][2]);
    mat.m[1][3] = (mat.m[0][0] * m.m[0][3]) + (mat.m[1][1] * m.m[1][3]) + (mat.m[1][2] * m.m[2][3]) + (mat.m[1][3] * m.m[3][3]);

    mat.m[2][0] = (mat.m[2][0] * m.m[0][0]) + (mat.m[2][1] * m.m[1][0]) + (mat.m[2][2] * m.m[2][0]) + (mat.m[2][3] * m.m[3][0]);
    mat.m[2][1] = (mat.m[2][0] * m.m[0][1]) + (mat.m[2][1] * m.m[1][1]) + (mat.m[2][2] * m.m[2][1]) + (mat.m[2][3] * m.m[3][1]);
    mat.m[2][2] = (mat.m[2][0] * m.m[0][2]) + (mat.m[2][1] * m.m[1][2]) + (mat.m[2][2] * m.m[2][2]) + (mat.m[2][3] * m.m[3][2]);
    mat.m[2][3] = (mat.m[0][0] * m.m[0][3]) + (mat.m[2][1] * m.m[1][3]) + (mat.m[2][2] * m.m[2][3]) + (mat.m[2][3] * m.m[3][3]);

    mat.m[3][0] = (mat.m[3][0] * m.m[0][0]) + (mat.m[3][1] * m.m[1][0]) + (mat.m[3][2] * m.m[2][0]) + (mat.m[3][3] * m.m[3][0]);
    mat.m[3][1] = (mat.m[3][0] * m.m[0][1]) + (mat.m[3][1] * m.m[1][1]) + (mat.m[3][2] * m.m[2][1]) + (mat.m[3][3] * m.m[3][1]);
    mat.m[3][2] = (mat.m[3][0] * m.m[0][2]) + (mat.m[3][1] * m.m[1][2]) + (mat.m[3][2] * m.m[2][2]) + (mat.m[3][3] * m.m[3][2]);
    mat.m[3][3] = (mat.m[3][0] * m.m[0][3]) + (mat.m[3][1] * m.m[1][3]) + (mat.m[3][2] * m.m[2][3]) + (mat.m[3][3] * m.m[3][3]);

    return *this;
}

float Matrix4::Determinant() const {
    return 
    m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] - m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
    m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0] - m[0][3] * m[1][2] * m[2][0] * m[3][1] + m[0][2] * m[1][3] * m[2][0] * m[3][1] +
    m[0][3] * m[1][0] * m[2][2] * m[3][1] - m[0][0] * m[1][3] * m[2][2] * m[3][1] - m[0][2] * m[1][0] * m[2][3] * m[3][1] + m[0][0] * m[1][2] * m[2][3] * m[3][1] +
    m[0][3] * m[1][1] * m[2][0] * m[3][2] - m[0][1] * m[1][3] * m[2][0] * m[3][2] - m[0][3] * m[1][0] * m[2][1] * m[3][2] + m[0][0] * m[1][3] * m[2][1] * m[3][2] +
    m[0][1] * m[1][0] * m[2][3] * m[3][2] - m[0][0] * m[1][1] * m[2][3] * m[3][2] - m[0][2] * m[1][1] * m[2][0] * m[3][3] + m[0][1] * m[1][2] * m[2][0] * m[3][3] +
    m[0][2] * m[1][0] * m[2][1] * m[3][3] - m[0][0] * m[1][2] * m[2][1] * m[3][3] - m[0][1] * m[1][0] * m[2][2] * m[3][3] + m[0][0] * m[1][1] * m[2][2] * m[3][3];
}

Matrix4 InverseMatrix(bool * r, float* d) const {
    Matrix4 mat;
    float det = Determinant();
    bool result = false;

    if (det != 0.0f) {

        mat.m[0][0] = (mat.m[1][2] * m.m[2][3] * m.m[3][1]) - (mat.m[1][3] * m.m[2][2] * m.m[3][1]) + (mat.m[1][3] * m.m[2][2] * m.m[3][1]) - (mat.m[1][1] * m.m[2][3] * m.m[3][2]) - (mat.m[1][2] * m.m[2][1] * m.m[3][3]) + (mat.m[1][1] * m.m[2][2] * m.m[3][3]) / det;
        mat.m[0][1] = (mat.m[0][3] * m.m[2][2] * m.m[3][1]) - (mat.m[0][2] * m.m[2][3] * m.m[3][1]) - (mat.m[0][3] * m.m[2][3] * m.m[3][1]) + (mat.m[0][1] * m.m[2][3] * m.m[3][2]) + (mat.m[0][2] * m.m[2][1] * m.m[3][3]) - (mat.m[0][1] * m.m[2][2] * m.m[3][3]) / det;
        mat.m[0][2] = (mat.m[0][2] * m.m[1][3] * m.m[3][1]) - (mat.m[0][3] * m.m[1][2] * m.m[3][1]) + (mat.m[0][3] * m.m[1][2] * m.m[3][1]) - (mat.m[0][1] * m.m[1][3] * m.m[3][2]) - (mat.m[0][2] * m.m[1][1] * m.m[3][3]) + (mat.m[0][1] * m.m[1][2] * m.m[3][3]) / det;
        mat.m[0][3] = (mat.m[0][3] * m.m[1][2] * m.m[2][1]) - (mat.m[0][2] * m.m[1][3] * m.m[2][1]) - (mat.m[0][3] * m.m[1][3] * m.m[2][1]) + (mat.m[0][1] * m.m[1][3] * m.m[2][2]) + (mat.m[0][2] * m.m[1][1] * m.m[2][3]) - (mat.m[0][1] * m.m[1][2] * m.m[2][3]) / det;

        mat.m[1][0] = (mat.m[1][3] * m.m[2][2] * m.m[3][0]) - (mat.m[1][2] * m.m[2][3] * m.m[3][0]) - (mat.m[1][3] * m.m[2][3] * m.m[3][0]) + (mat.m[1][0] * m.m[2][3] * m.m[3][2]) + (mat.m[1][2] * m.m[2][0] * m.m[3][3]) - (mat.m[1][0] * m.m[2][2] * m.m[3][3]) / det;
        mat.m[1][1] = (mat.m[0][2] * m.m[2][3] * m.m[3][0]) - (mat.m[0][3] * m.m[2][2] * m.m[3][0]) + (mat.m[0][3] * m.m[2][2] * m.m[3][0]) - (mat.m[0][0] * m.m[2][3] * m.m[3][2]) - (mat.m[0][2] * m.m[2][0] * m.m[3][3]) + (mat.m[0][0] * m.m[2][2] * m.m[3][3]) / det;
        mat.m[1][2] = (mat.m[0][3] * m.m[1][2] * m.m[3][0]) - (mat.m[0][2] * m.m[1][3] * m.m[3][0]) - (mat.m[0][3] * m.m[1][3] * m.m[3][0]) + (mat.m[0][0] * m.m[1][3] * m.m[3][2]) + (mat.m[0][2] * m.m[1][0] * m.m[3][3]) - (mat.m[0][0] * m.m[1][2] * m.m[3][3]) / det;
        mat.m[1][3] = (mat.m[0][2] * m.m[1][3] * m.m[2][0]) - (mat.m[0][3] * m.m[1][2] * m.m[2][0]) + (mat.m[0][3] * m.m[1][2] * m.m[2][0]) - (mat.m[0][0] * m.m[1][3] * m.m[2][2]) - (mat.m[0][2] * m.m[1][0] * m.m[2][3]) + (mat.m[0][0] * m.m[1][2] * m.m[2][3]) / det;

        mat.m[2][0] = (mat.m[1][1] * m.m[2][3] * m.m[3][0]) - (mat.m[1][3] * m.m[2][1] * m.m[3][0]) + (mat.m[1][3] * m.m[2][1] * m.m[3][0]) - (mat.m[1][0] * m.m[2][3] * m.m[3][1]) - (mat.m[1][1] * m.m[2][0] * m.m[3][3]) + (mat.m[1][0] * m.m[2][1] * m.m[3][3]) / det;
        mat.m[2][1] = (mat.m[0][3] * m.m[2][1] * m.m[3][0]) - (mat.m[0][1] * m.m[2][3] * m.m[3][0]) - (mat.m[0][3] * m.m[2][3] * m.m[3][0]) + (mat.m[0][0] * m.m[2][3] * m.m[3][1]) + (mat.m[0][1] * m.m[2][0] * m.m[3][3]) - (mat.m[0][0] * m.m[2][1] * m.m[3][3]) / det;
        mat.m[2][2] = (mat.m[0][1] * m.m[1][3] * m.m[3][0]) - (mat.m[0][3] * m.m[1][1] * m.m[3][0]) + (mat.m[0][3] * m.m[1][1] * m.m[3][0]) - (mat.m[0][0] * m.m[1][3] * m.m[3][1]) - (mat.m[0][1] * m.m[1][0] * m.m[3][3]) + (mat.m[0][0] * m.m[1][1] * m.m[3][3]) / det;
        mat.m[2][3] = (mat.m[0][3] * m.m[1][1] * m.m[2][0]) - (mat.m[0][1] * m.m[1][3] * m.m[2][0]) - (mat.m[0][3] * m.m[1][3] * m.m[2][0]) + (mat.m[0][0] * m.m[1][3] * m.m[2][1]) + (mat.m[0][1] * m.m[1][0] * m.m[2][3]) - (mat.m[0][0] * m.m[1][1] * m.m[2][3]) / det;

        mat.m[3][0] = (mat.m[1][2] * m.m[2][1] * m.m[3][0]) - (mat.m[1][1] * m.m[2][2] * m.m[3][0]) - (mat.m[1][2] * m.m[2][2] * m.m[3][0]) + (mat.m[1][0] * m.m[2][2] * m.m[3][1]) + (mat.m[1][1] * m.m[2][0] * m.m[3][2]) - (mat.m[1][0] * m.m[2][1] * m.m[3][2]) / det;
        mat.m[3][1] = (mat.m[0][1] * m.m[2][2] * m.m[3][0]) - (mat.m[0][2] * m.m[2][1] * m.m[3][0]) + (mat.m[0][2] * m.m[2][1] * m.m[3][0]) - (mat.m[0][0] * m.m[2][2] * m.m[3][1]) - (mat.m[0][1] * m.m[2][0] * m.m[3][2]) + (mat.m[0][0] * m.m[2][1] * m.m[3][2]) / det;
        mat.m[3][2] = (mat.m[0][2] * m.m[1][1] * m.m[3][0]) - (mat.m[0][1] * m.m[1][2] * m.m[3][0]) - (mat.m[0][2] * m.m[1][2] * m.m[3][0]) + (mat.m[0][0] * m.m[1][2] * m.m[3][1]) + (mat.m[0][1] * m.m[1][0] * m.m[3][2]) - (mat.m[0][0] * m.m[1][1] * m.m[3][2]) / det;
        mat.m[3][3] = (mat.m[0][1] * m.m[1][2] * m.m[2][0]) - (mat.m[0][2] * m.m[1][1] * m.m[2][0]) + (mat.m[0][2] * m.m[1][1] * m.m[2][0]) - (mat.m[0][0] * m.m[1][2] * m.m[2][1]) - (mat.m[0][1] * m.m[1][0] * m.m[2][2]) + (mat.m[0][0] * m.m[1][1] * m.m[2][2]) / det;

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

Matrix4 TransposeMatrix() const {
    Matrix4 mat(*this);
    return mat.Transpose();
}

bool Matrix4::operator == (const Matrix4& m) const {
    return this->val[0x0] == m.val[0x0] && this->val[0x1] == m.val[0x1] &&
            this->val[0x2] == m.val[0x2] && this->val[0x3] == m.val[0x3] &&
            this->val[0x4] == m.val[0x4] && this->val[0x5] == m.val[0x5] &&
            this->val[0x6] == m.val[0x6] && this->val[0x7] == m.val[0x7] &&
            this->val[0x8] == m.val[0x8] && this->val[0x9] == m.val[0x9] &&
            this->val[0xa] == m.val[0xa] && this->val[0xb] == m.val[0xb] &&
            this->val[0xc] == m.val[0xc] && this->val[0xd] == m.val[0xd] &&
            this->val[0xe] == m.val[0xe] && this->val[0xf] == m.val[0xf];
}

bool Matrix4::operator != (const Matrix4& m) const {
    return this->val[0x0] != m.val[0x0] || this->val[0x1] != m.val[0x1] ||
            this->val[0x2] != m.val[0x2] || this->val[0x3] != m.val[0x3] ||
            this->val[0x4] != m.val[0x4] || this->val[0x5] != m.val[0x5] ||
            this->val[0x6] != m.val[0x6] || this->val[0x7] != m.val[0x7] ||
            this->val[0x8] != m.val[0x8] || this->val[0x9] != m.val[0x9] ||
            this->val[0xa] != m.val[0xa] || this->val[0xb] != m.val[0xb] ||
            this->val[0xc] != m.val[0xc] || this->val[0xd] != m.val[0xd] ||
            this->val[0xe] != m.val[0xe] || this->val[0xf] != m.val[0xf];
}

Matrix4 Matrix4::operator * (const Matrix4& m) const {
    Matrix4 mat;
    mat.m[0][0] = (this->m[0][0] * m.m[0][0]) + (this->m[0][1] * m.m[1][0]) + (this->m[0][2] * m.m[2][0]) + (this->m[0][3] * m.m[3][0]);
    mat.m[0][1] = (this->m[0][0] * m.m[0][1]) + (this->m[0][1] * m.m[1][1]) + (this->m[0][2] * m.m[2][1]) + (this->m[0][3] * m.m[3][1]);
    mat.m[0][2] = (this->m[0][0] * m.m[0][2]) + (this->m[0][1] * m.m[1][2]) + (this->m[0][2] * m.m[2][2]) + (this->m[0][3] * m.m[3][2]);
    mat.m[0][3] = (this->m[0][0] * m.m[0][3]) + (this->m[0][1] * m.m[1][3]) + (this->m[0][2] * m.m[2][3]) + (this->m[0][3] * m.m[3][3]);

    mat.m[1][0] = (this->m[1][0] * m.m[0][0]) + (this->m[1][1] * m.m[1][0]) + (this->m[1][2] * m.m[2][0]) + (this->m[1][3] * m.m[3][0]);
    mat.m[1][1] = (this->m[1][0] * m.m[0][1]) + (this->m[1][1] * m.m[1][1]) + (this->m[1][2] * m.m[2][1]) + (this->m[1][3] * m.m[3][1]);
    mat.m[1][2] = (this->m[1][0] * m.m[0][2]) + (this->m[1][1] * m.m[1][2]) + (this->m[1][2] * m.m[2][2]) + (this->m[1][3] * m.m[3][2]);
    mat.m[1][3] = (this->m[0][0] * m.m[0][3]) + (this->m[1][1] * m.m[1][3]) + (this->m[1][2] * m.m[2][3]) + (this->m[1][3] * m.m[3][3]);

    mat.m[2][0] = (this->m[2][0] * m.m[0][0]) + (this->m[2][1] * m.m[1][0]) + (this->m[2][2] * m.m[2][0]) + (this->m[2][3] * m.m[3][0]);
    mat.m[2][1] = (this->m[2][0] * m.m[0][1]) + (this->m[2][1] * m.m[1][1]) + (this->m[2][2] * m.m[2][1]) + (this->m[2][3] * m.m[3][1]);
    mat.m[2][2] = (this->m[2][0] * m.m[0][2]) + (this->m[2][1] * m.m[1][2]) + (this->m[2][2] * m.m[2][2]) + (this->m[2][3] * m.m[3][2]);
    mat.m[2][3] = (this->m[0][0] * m.m[0][3]) + (this->m[2][1] * m.m[1][3]) + (this->m[2][2] * m.m[2][3]) + (this->m[2][3] * m.m[3][3]);

    mat.m[3][0] = (this->m[3][0] * m.m[0][0]) + (this->m[3][1] * m.m[1][0]) + (this->m[3][2] * m.m[2][0]) + (this->m[3][3] * m.m[3][0]);
    mat.m[3][1] = (this->m[3][0] * m.m[0][1]) + (this->m[3][1] * m.m[1][1]) + (this->m[3][2] * m.m[2][1]) + (this->m[3][3] * m.m[3][1]);
    mat.m[3][2] = (this->m[3][0] * m.m[0][2]) + (this->m[3][1] * m.m[1][2]) + (this->m[3][2] * m.m[2][2]) + (this->m[3][3] * m.m[3][2]);
    mat.m[3][3] = (this->m[3][0] * m.m[0][3]) + (this->m[3][1] * m.m[1][3]) + (this->m[3][2] * m.m[2][3]) + (this->m[3][3] * m.m[3][3]);

    return mat;
}
Matrix4 Matrix4::operator * (float f) const {
    Matrix3 mat;
    mat.val[0x0] = this->val[0x0] * f;
    mat.val[0x1] = this->val[0x1] * f;
    mat.val[0x2] = this->val[0x2] * f;
    mat.val[0x3] = this->val[0x3] * f;
    mat.val[0x4] = this->val[0x4] * f;
    mat.val[0x5] = this->val[0x5] * f;
    mat.val[0x6] = this->val[0x6] * f;
    mat.val[0x7] = this->val[0x7] * f;
    mat.val[0x8] = this->val[0x8] * f;
    mat.val[0x9] = this->val[0x9] * f;
    mat.val[0xa] = this->val[0xa] * f;
    mat.val[0xb] = this->val[0xb] * f;
    mat.val[0xc] = this->val[0xc] * f;
    mat.val[0xd] = this->val[0xd] * f;
    mat.val[0xf] = this->val[0xf] * f;
    return mat;
}

Matrix4 Matrix4::operator + (const Matrix4& m) const {
    Matrix4 mat;
    mat.val[0x0] = this->val[0x0] + m.val[0x0];
    mat.val[0x1] = this->val[0x1] + m.val[0x1];
    mat.val[0x2] = this->val[0x2] + m.val[0x2];
    mat.val[0x3] = this->val[0x3] + m.val[0x3];
    mat.val[0x4] = this->val[0x4] + m.val[0x4];
    mat.val[0x5] = this->val[0x5] + m.val[0x5];
    mat.val[0x6] = this->val[0x6] + m.val[0x6];
    mat.val[0x7] = this->val[0x7] + m.val[0x7];
    mat.val[0x8] = this->val[0x8] + m.val[0x8];
    mat.val[0x9] = this->val[0x9] + m.val[0x9];
    mat.val[0xa] = this->val[0xa] + m.val[0xa];
    mat.val[0xb] = this->val[0xb] + m.val[0xb];
    mat.val[0xc] = this->val[0xc] + m.val[0xc];
    mat.val[0xd] = this->val[0xd] + m.val[0xd];
    mat.val[0xf] = this->val[0xf] + m.val[0xe];
    return mat;
}


Matrix4 operator - (const Matrix4& m) const {
    Matrix4 mat;
    mat.val[0x0] = this->val[0x0] - m.val[0x0];
    mat.val[0x1] = this->val[0x1] - m.val[0x1];
    mat.val[0x2] = this->val[0x2] - m.val[0x2];
    mat.val[0x3] = this->val[0x3] - m.val[0x3];
    mat.val[0x4] = this->val[0x4] - m.val[0x4];
    mat.val[0x5] = this->val[0x5] - m.val[0x5];
    mat.val[0x6] = this->val[0x6] - m.val[0x6];
    mat.val[0x7] = this->val[0x7] - m.val[0x7];
    mat.val[0x8] = this->val[0x8] - m.val[0x8];
    mat.val[0x9] = this->val[0x9] - m.val[0x9];
    mat.val[0xa] = this->val[0xa] - m.val[0xa];
    mat.val[0xb] = this->val[0xb] - m.val[0xb];
    mat.val[0xc] = this->val[0xc] - m.val[0xc];
    mat.val[0xd] = this->val[0xd] - m.val[0xd];
    mat.val[0xf] = this->val[0xf] - m.val[0xe];
    return mat;
}

Matrix4& operator += (const Matrix4& m) {
    this->val[0x0] += m.val[0x0];
    this->val[0x1] += m.val[0x1];
    this->val[0x2] += m.val[0x2];
    this->val[0x3] += m.val[0x3];
    this->val[0x4] += m.val[0x4];
    this->val[0x5] += m.val[0x5];
    this->val[0x6] += m.val[0x6];
    this->val[0x7] += m.val[0x7];
    this->val[0x8] += m.val[0x8];
    this->val[0x9] += m.val[0x9];
    this->val[0xa] += m.val[0xa];
    this->val[0xb] += m.val[0xb];
    this->val[0xc] += m.val[0xc];
    this->val[0xd] += m.val[0xd];
    this->val[0xe] += m.val[0xe];
    this->val[0xf] += m.val[0xf];
    return *this;

}

Matrix4& operator -= (const Matrix4& m) {
    this->val[0x0] -= m.val[0x0];
    this->val[0x1] -= m.val[0x1];
    this->val[0x2] -= m.val[0x2];
    this->val[0x3] -= m.val[0x3];
    this->val[0x4] -= m.val[0x4];
    this->val[0x5] -= m.val[0x5];
    this->val[0x6] -= m.val[0x6];
    this->val[0x7] -= m.val[0x7];
    this->val[0x8] -= m.val[0x8];
    this->val[0x9] -= m.val[0x9];
    this->val[0xa] -= m.val[0xa];
    this->val[0xb] -= m.val[0xb];
    this->val[0xc] -= m.val[0xc];
    this->val[0xd] -= m.val[0xd];
    this->val[0xe] -= m.val[0xe];
    this->val[0xf] -= m.val[0xf];
    return *this;
}

Matrix4& operator *= (const Matrix4& m) {
    Matrix4 mat(*this);
    mat.m[0][0] = (mat.m[0][0] * m.m[0][0]) + (mat.m[0][1] * m.m[1][0]) + (mat.m[0][2] * m.m[2][0]) + (mat.m[0][3] * m.m[3][0]);
    mat.m[0][1] = (mat.m[0][0] * m.m[0][1]) + (mat.m[0][1] * m.m[1][1]) + (mat.m[0][2] * m.m[2][1]) + (mat.m[0][3] * m.m[3][1]);
    mat.m[0][2] = (mat.m[0][0] * m.m[0][2]) + (mat.m[0][1] * m.m[1][2]) + (mat.m[0][2] * m.m[2][2]) + (mat.m[0][3] * m.m[3][2]);
    mat.m[0][3] = (mat.m[0][0] * m.m[0][3]) + (mat.m[0][1] * m.m[1][3]) + (mat.m[0][2] * m.m[2][3]) + (mat.m[0][3] * m.m[3][3]);

    mat.m[1][0] = (mat.m[1][0] * m.m[0][0]) + (mat.m[1][1] * m.m[1][0]) + (mat.m[1][2] * m.m[2][0]) + (mat.m[1][3] * m.m[3][0]);
    mat.m[1][1] = (mat.m[1][0] * m.m[0][1]) + (mat.m[1][1] * m.m[1][1]) + (mat.m[1][2] * m.m[2][1]) + (mat.m[1][3] * m.m[3][1]);
    mat.m[1][2] = (mat.m[1][0] * m.m[0][2]) + (mat.m[1][1] * m.m[1][2]) + (mat.m[1][2] * m.m[2][2]) + (mat.m[1][3] * m.m[3][2]);
    mat.m[1][3] = (mat.m[0][0] * m.m[0][3]) + (mat.m[1][1] * m.m[1][3]) + (mat.m[1][2] * m.m[2][3]) + (mat.m[1][3] * m.m[3][3]);

    mat.m[2][0] = (mat.m[2][0] * m.m[0][0]) + (mat.m[2][1] * m.m[1][0]) + (mat.m[2][2] * m.m[2][0]) + (mat.m[2][3] * m.m[3][0]);
    mat.m[2][1] = (mat.m[2][0] * m.m[0][1]) + (mat.m[2][1] * m.m[1][1]) + (mat.m[2][2] * m.m[2][1]) + (mat.m[2][3] * m.m[3][1]);
    mat.m[2][2] = (mat.m[2][0] * m.m[0][2]) + (mat.m[2][1] * m.m[1][2]) + (mat.m[2][2] * m.m[2][2]) + (mat.m[2][3] * m.m[3][2]);
    mat.m[2][3] = (mat.m[0][0] * m.m[0][3]) + (mat.m[2][1] * m.m[1][3]) + (mat.m[2][2] * m.m[2][3]) + (mat.m[2][3] * m.m[3][3]);

    mat.m[3][0] = (mat.m[3][0] * m.m[0][0]) + (mat.m[3][1] * m.m[1][0]) + (mat.m[3][2] * m.m[2][0]) + (mat.m[3][3] * m.m[3][0]);
    mat.m[3][1] = (mat.m[3][0] * m.m[0][1]) + (mat.m[3][1] * m.m[1][1]) + (mat.m[3][2] * m.m[2][1]) + (mat.m[3][3] * m.m[3][1]);
    mat.m[3][2] = (mat.m[3][0] * m.m[0][2]) + (mat.m[3][1] * m.m[1][2]) + (mat.m[3][2] * m.m[2][2]) + (mat.m[3][3] * m.m[3][2]);
    mat.m[3][3] = (mat.m[3][0] * m.m[0][3]) + (mat.m[3][1] * m.m[1][3]) + (mat.m[3][2] * m.m[2][3]) + (mat.m[3][3] * m.m[3][3]);

    return *this;
}

Matrix4& operator *= (float f) {
    this->val[0x0] *= f;
    this->val[0x1] *= f;
    this->val[0x2] *= f;
    this->val[0x3] *= f;
    this->val[0x4] *= f;
    this->val[0x5] *= f;
    this->val[0x6] *= f;
    this->val[0x7] *= f;
    this->val[0x8] *= f;
    this->val[0x9] *= f;
    this->val[0xa] *= f;
    this->val[0xb] *= f;
    this->val[0xc] *= f;
    this->val[0xd] *= f;
    this->val[0xe] *= f;
    this->val[0xf] *= f;
    return *this;
}

