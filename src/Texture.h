#ifndef TEXTURE_H
#define TEXTURE_H
#pragma once

#include <vector>
#include <string>
#include "Character.h"
#include "Int2D.h"
#include "RenderType.h"

class Texture {
private:
	std::vector<Character> characters;
	Int2D dimensions;
public:

	Texture(Character fillChar = Character(L'☒'), Int2D dimensions = Int2D(1, 1));
	Texture(std::wstring newCharacters, int width, Color color = TEXT_WHITE | BACK_BLACK);

	std::vector<Character> GetCharacters() { return characters; }
	Int2D GetDimensions() { return dimensions; }
	Int2D GetBottomLeft() { return Int2D(dimensions.x, dimensions.y - 1); }

	void SetColor(Color color);
	void SetCharacters(Character fillChar = Character(' '));
	void SetTexture(std::wstring newCharacters, int width, Color color = TEXT_WHITE | BACK_BLACK);

	void DrawColor(Color color, Int2D pos);
	void DrawColorForeground(Color color, Int2D pos);
	void DrawCharacter(Character character, Int2D pos);
	void DrawCharacterForeground(Character character, Int2D pos);
	void DrawTexture(Texture texture, Int2D pos, RenderType renderType = RenderType::Opaque);
	void DrawTextureForeground(Texture texture, Int2D pos, RenderType renderType = RenderType::Opaque);
	
	std::vector<CHAR_INFO> ToCHAR_INFO();
	void reserve(const size_t _Newcapacity) { characters.reserve(_Newcapacity); }
	const Character* data() { return characters.data(); }

	Character& operator[](int i);
};

#endif // TEXTURE_H