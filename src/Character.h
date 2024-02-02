#ifndef CHARACTER_H
#define CHARACTER_H
#pragma once

#define NOMINMAX
#include <Windows.h>
#include "Color.h"

struct Character {
	WCHAR textChar;
	Color color;

	Character(WCHAR textChar = L'☒', Color color = TEXT_WHITE | BACK_BLACK)
		: textChar(textChar), color(color) {}

	operator CHAR_INFO() {
		CHAR_INFO c;
		c.Char.UnicodeChar = textChar;
		c.Attributes = color;
		return c;
	}
};

#endif // CHARACTER_H