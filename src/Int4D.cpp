#include "Int4D.h"

Int4D& Int4D::operator+(Int4D const& rhs) {
	r += rhs.r;
	g += rhs.g;
	b += rhs.b;
	a += rhs.a;
	return *this;
}

Int4D& Int4D::operator-(Int4D const& rhs) {
	r -= rhs.r;
	g -= rhs.g;
	b -= rhs.b;
	a -= rhs.a;
	return *this;
}

Int4D& Int4D::operator+=(Int4D const& rhs) {
	r += rhs.r;
	g += rhs.g;
	b += rhs.b;
	a += rhs.a;
	return *this;
}

Int4D& Int4D::operator-=(Int4D const& rhs) {
	r -= rhs.r;
	g -= rhs.g;
	b -= rhs.b;
	a -= rhs.a;
	return *this;
}