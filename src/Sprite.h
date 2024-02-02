#ifndef SPRITE_H
#define SPRITE_H
#pragma once

#include "Texture.h"
#include "Int2D.h"
#include "Pivot.h"

class Sprite {
private:
	Texture texture;
	bool overwriteBackground;
	Int2D position;
	Pivot pivot;
public:

	Sprite(Texture texture = Texture(), bool overwriteBackground = true, Int2D position = Int2D(), Pivot pivot = Pivot::BottomLeft);
};

#endif // SPRITE_H