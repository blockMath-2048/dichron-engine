#include "matrix.h"

Matrix::Matrix(float *_mat) {
	mat = (float *)calloc(16, sizeof(float));	
	if (_mat != NULL) {
		memcpy(mat, _mat, 16 * sizeof(float));
	} else {
		mat[0] = mat[5] = mat[10] = mat[15] = 1.0f;
	}
}

Matrix::Matrix(Vector _vo, Vector _vi) {
	mat = (float *)calloc(16, sizeof(float));
	mat[12] = _vo.x;
	mat[13] = _vo.y;
	mat[14] = _vo.u;
	mat[3] = _vi.x;
	mat[7] = _vi.y;
	mat[11] = _vi.u;
	mat[15] = _vo.t * _vi.t;
}

Matrix::~Matrix() {
	free(mat);
}

Matrix Matrix::operator+(Matrix o) {
	Matrix newMat = Matrix();
	for (int i = 0; i < 16; i++) newMat.mat[i] = mat[i] + o.mat[i];
	return newMat;
}

Matrix Matrix::operator+(Vector o) {
	return (*this) + Matrix(o);
}

Vector Matrix::operator*(Vector o) {
	return Vector(o.x * mat[0] + o.y * mat[4] + o.u * mat[8] + o.t * mat[12], o.x * mat[1] + o.y * mat[5] + o.u * mat[9] + o.t * mat[13], o.x * mat[2] + o.y * mat[6] + o.u * mat[10] + o.t * mat[14], o.x * mat[3] + o.y * mat[7] + o.u * mat[11] + o.t * mat[15]);
}

Matrix Matrix::operator*(Matrix o) {
	// todo: this
}

Matrix Matrix::euler(Vector v) {
	/*
	 * x, y, u
	 *
	 * rotation order: x, y, u
	 * 
	 * 
	 * x1 = x
	 * y1 = y * coshf(v.x) + u * sinhf(v.x)
	 * u1 = u * coshf(v.x) + y * sinhf(v.x)
	 *
	 * x2 = x1 * coshf(v.y) + u1 * sinhf(v.y)
	 * y2 = y1
	 * u2 = u1 * coshf(v.y) + x1 * sinhf(v.y)
	 *
	 * x3 = x2 * cosf(v.u) - y2 * sinf(v.u)
	 * y3 = y2 * cosf(v.u) + x2 * sinf(v.u)
	 * u3 = u2
	 *
	 *
	 * x3 = (x) * coshf(v.y)*cosf(v.u) + (u) * (coshf(v.x)*sinhf(v.y)*cosf(v.u)+sinhf(v.x)*sinf(v.u)) + (y) * (sinhf(v.x)*sinhf(v.y)*cosf(v.u)-coshf(v.x)*sinf(v.u))
	 * y3 = (x) * coshf(v.y)*sinf(v.u) + (u) * (coshf(v.x)*sinhf(v.y)*sinf(v.u)+sinhf(v.x)*cosf(v.u)) + (y) * (sinhf(v.x)*sinhf(v.y)*sinf(v.u)+coshf(v.x)*cosf(v.u))
	 * u3 = (x) * sinhf(v.y)	   + (u) * coshf(v.x)*coshf(v.y) 				  + (y) * sinhf(v.x)*coshf(v.y)
	 * 
	 */

	return Matrix(new float[]{
			coshf(v.y)*cosf(v.u),	sinhf(v.x)*sinhf(v.y)*cosf(v.u)-coshf(v.x)*sinf(v.u),	coshf(v.x)*sinhf(v.y)*cosf(v.u)+sinhf(v.x)*sinf(v.u),	0.0f,
			coshf(v.y)*sinf(v.u),	sinhf(v.x)*sinhf(v.y)*sinf(v.u)+coshf(v.x)*cosf(v.u),	coshf(v.x)*sinhf(v.y)*sinf(v.u)+sinhf(v.x)*cosf(v.u),	0.0f,
			sinhf(v.y),		sinhf(v.x)*coshf(v.y),					coshf(v.x)*coshf(v.y),					0.0f,
			0.0f,			0.0f,							0.0f,							1.0f
	});
}

Matrix Matrix::inverse(Matrix m) {
	// todo: this
}
