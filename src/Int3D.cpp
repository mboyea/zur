#include "Int3D.h"

Int3D& Int3D::operator+(Int3D const& rhs) {
	r += rhs.r;
	g += rhs.g;
	b += rhs.b;
	return *this;
}

Int3D& Int3D::operator-(Int3D const& rhs) {
	r -= rhs.r;
	g -= rhs.g;
	b -= rhs.b;
	return *this;
}

Int3D& Int3D::operator+=(Int3D const& rhs) {
	r += rhs.r;
	g += rhs.g;
	b += rhs.b;
	return *this;
}

Int3D& Int3D::operator-=(Int3D const& rhs) {
	r -= rhs.r;
	g -= rhs.g;
	b -= rhs.b;
	return *this;
}