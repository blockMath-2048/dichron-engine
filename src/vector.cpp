#include "vector.h"

float signedsqrt(float x) {
	return (x < 0)?(-sqrtf(-x)):(sqrtf(x));
}

Vector::Vector(float _x, float _y, float _u, float _t) {
	x = _x;
	y = _y;
	u = _u;
	t = _t;
}
	
Vector Vector::operator+ (Vector o) {
	return Vector(x + o.x, y + o.y, u + o.u, t + o.t);
}

Vector Vector::operator* (float f) {
	return Vector(x * f, y * f, u * f, t * f);
}

Vector Vector::operator- (Vector o) {
	return Vector(x - o.x, y - o.y, u - o.u, t - o.t);
}

Vector Vector::operator/ (float f) {
	return Vector(x / f, y / f, u / f, t / f);
}


Vector Vector::cross(Vector a, Vector b) {
	return Vector (a.y * b.u - a.u * b.y, a.u * b.x - a.x * b.u, -(a.x * b.y - a.y * b.x), a.t * b.t);
}

Vector Vector::ecross(Vector a, Vector b) {
	return Vector (a.y * b.u - a.u * b.y, a.u * b.x - a.x * b.u, a.x * b.y - a.y * b.x, a.t * b.t);
}

float Vector::dot(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y - a.u * b.u - a.t * b.t;
}

float Vector::edot(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y + a.u * b.u + a.t * b.t;
}

float Vector::magnitude() {
	return signedsqrt(Vector::dot(*this, *this));
}

float Vector::emagnitude() {
	return signedsqrt(Vector::edot(*this, *this));
}

Vector Vector::normalized() {
	return (*this) / magnitude();
}

Vector Vector::enormalized() {
	return (*this) / emagnitude();
}

#if HAVE_FMT
std::string Vector::toString(bool show_t = false) {
	if (show_t) {
		return fmt::format("[{}, {}, {}, {}]", x, y, u, t);
	} else {
		return fmt::format("[{}, {}, {}]", x, y, u);
	}
}
#endif
