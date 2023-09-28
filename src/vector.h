#pragma once

#include <string>
#include <cmath>

#if HAVE_FMT
#include <format.h>
#endif

float signedsqrt(float x);

class Vector {
public:
	float x, y, u, t;

	Vector(float _x = 0.0f, float _y = 0.0f, float _u = 0.0f, float _t = 1.0f);
	
	Vector operator+ (Vector o);

	Vector operator* (float f);

	Vector operator- (Vector o);

	Vector operator/ (float f);


	static Vector cross(Vector a, Vector b);

	static Vector ecross(Vector a, Vector b);

	static float dot(Vector a, Vector b);
	
	static float edot(Vector a, Vector b);

	float magnitude();

	float emagnitude();

	Vector normalized();

	Vector enormalized();

#if HAVE_FMT
	std::string toString(bool show_t = false);
#endif

};
