#include <stdlib.h>
#include <string.h>
#include <cmath>
#include "vector.h"


class Matrix {
private:
	float *mat;
public:
	Matrix(float *_mat = NULL);
	Matrix(Vector _vo, Vector _vi = Vector());
	~Matrix();

	Matrix operator+ (Matrix o);
	Matrix operator+ (Vector o);

	Vector operator* (Vector o);
	Matrix operator* (Matrix o);
	
	static Matrix euler(Vector v);
	static Matrix inverse(Matrix m);
};
