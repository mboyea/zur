#include "Int2D.h"

Int2D& Int2D::operator+(Int2D const& rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Int2D& Int2D::operator-(Int2D const& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Int2D& Int2D::operator+=(Int2D const& rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Int2D& Int2D::operator-=(Int2D const& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Int2D::operator COORD() {
	return { (SHORT)x, (SHORT)y };
}