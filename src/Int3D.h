#ifndef INT3D_H
#define INT3D_H
#pragma once

class Int3D {
public:
	int r, g, b;

	Int3D(int r = 0, int g = 0, int b = 0)
		: r(r), g(g), b(b) {};

	Int3D& operator+(Int3D const& rhs);
	Int3D& operator-(Int3D const& rhs);
	Int3D& operator-=(Int3D const& rhs);
	Int3D& operator+=(Int3D const& rhs);
};

#endif // INT3D_H