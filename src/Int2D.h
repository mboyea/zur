#ifndef INT2D_H
#define INT2D_H
#pragma once

#include <Windows.h>

class Int2D {
public:
	int x, y;

	Int2D(int x = 0, int y = 0)
		: x(x), y(y) {};

	Int2D& operator+(Int2D const& rhs);
	Int2D& operator-(Int2D const& rhs);
	Int2D& operator-=(Int2D const& rhs);
	Int2D& operator+=(Int2D const& rhs);

	operator COORD();
};

#endif // INT2D_H
