#ifndef INT4D_H
#define INT4D_H
#pragma once

class Int4D {
public:
	int r, g, b, a;

	Int4D(int r = 0, int g = 0, int b = 0, int a = 0)
		: r(r), g(g), b(b), a(a) {};

	Int4D& operator+(Int4D const& rhs);
	Int4D& operator-(Int4D const& rhs);
	Int4D& operator-=(Int4D const& rhs);
	Int4D& operator+=(Int4D const& rhs);
};

#endif // INT4D_H
