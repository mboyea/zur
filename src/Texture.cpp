#include "Texture.h"
#include <cmath>

Texture::Texture(Character fillChar, Int2D dimensions)
	: dimensions(dimensions) {
	// Initialize characters
	while (characters.size() < (unsigned int)dimensions.x * (unsigned int)dimensions.y) {
		characters.push_back(fillChar);
	}
	characters.reserve(dimensions.x * dimensions.y);
}

Texture::Texture(std::wstring newCharacters, int width, Color color) {
	dimensions = Int2D(width, (newCharacters.size() / width));

	for (int i = 0; i < dimensions.x * dimensions.y; i++) {
		Character character;
		character.textChar = newCharacters[i];
		character.color = color;
		characters.push_back(character);
	}
}

void Texture::DrawColor(Color color, Int2D pos) {
	// if inside screen bounds
	if (pos.x > 0 && pos.x <= dimensions.x && pos.y > 0 && pos.y < dimensions.y + 1) {
		// draw to screen
		characters[pos.x - 1 + dimensions.x * (dimensions.y - pos.y)].color = color;
	}
}

void Texture::DrawColorForeground(Color color, Int2D pos) {
	// if inside screen bounds
	if (pos.x > 0 && pos.x <= dimensions.x && pos.y > 0 && pos.y < dimensions.y + 1) {
		// get a pointer to the target character
		Character* targetCharacter = &characters[pos.x - 1 + dimensions.x * (dimensions.y - pos.y)];

		// character.backColor = drawCharacter->backColor;
	    // mask the draw character to its TextColor and mask the target character to its background color, then combine them
		color = (color & TEXT_WHITE) | (targetCharacter->color & BACK_WHITE);

		// draw to screen
		targetCharacter->color = color;
	}
}

void Texture::DrawCharacter(Character character, Int2D pos) {
	// if inside screen bounds
	if (pos.x > 0 && pos.x <= dimensions.x && pos.y > 0 && pos.y < dimensions.y + 1) {
		// draw to screen
		characters[pos.x - 1 + dimensions.x * (dimensions.y - pos.y)] = character;
	}
}

void Texture::DrawCharacterForeground(Character character, Int2D pos) {
	// if inside screen bounds
	if (pos.x > 0 && pos.x <= dimensions.x && pos.y > 0 && pos.y < dimensions.y + 1) {
		// get a pointer to the target character
		Character* targetCharacter = &characters[pos.x - 1 + dimensions.x * (dimensions.y - pos.y)];

		  // character.backColor = drawCharacter->backColor;
		// mask the draw character to its TextColor and mask the target character to its background color, then combine them
		character.color = (character.color & TEXT_WHITE) | (targetCharacter->color & BACK_WHITE);

		// draw to screen
		*targetCharacter = character;
	}
}

void Texture::DrawTexture(Texture texture, Int2D pos, RenderType renderType) {
	const int width = texture.GetDimensions().x;
	const int height = texture.GetDimensions().y;
	const Int2D bottomLeft = pos - Int2D(0, height - 1);
	Int2D drawPos;

	switch (renderType) {
	case RenderType::Opaque:
		// for each character in the texture, find it's position on the window and draw it to the buffer
		for (unsigned int i = 0; i < texture.characters.size(); i++) {
			//	Formula: Row# = ceil(Element# / Width)
			//	posX = BottomLeftX + Element# - Width * Row#
			//	posY = BottomLeftY + Height - 1 - Row#
			drawPos.x = bottomLeft.x + i - width * (int)ceil(i / width);
			drawPos.y = bottomLeft.y + height - 1 - (int)ceil(i / width);

			DrawCharacter(texture.characters[i], drawPos);
		}
		break;
	case RenderType::Filled:
		for (unsigned int i = 0; i < texture.characters.size(); i++) {
			drawPos.x = bottomLeft.x + i - width * (int)ceil(i / width);
			drawPos.y = bottomLeft.y + height - 1 - (int)ceil(i / width);

			// '%' is transparent
			if (texture.characters[i].textChar != '%') {
				DrawCharacter(texture.characters[i], drawPos);
			}
		}
		break;
	case RenderType::Transparent:
		for (unsigned int i = 0; i < texture.characters.size(); i++) {
			drawPos.x = bottomLeft.x + i - width * (int)ceil(i / width);
			drawPos.y = bottomLeft.y + height - 1 - (int)ceil(i / width);

			// ' ' is transparent
			if (texture.characters[i].textChar != ' ') {
				DrawCharacter(texture.characters[i], drawPos);
			}
		}
		break;
	}
}

void Texture::DrawTextureForeground(Texture texture, Int2D pos, RenderType renderType) {
	const int width = texture.GetDimensions().x;
	const int height = texture.GetDimensions().y;
	const Int2D bottomLeft = pos - Int2D(0, height - 1);
	Int2D drawPos;

	switch (renderType) {
	case RenderType::Opaque:
		// for each character in the texture, find it's position on the window and draw it to the buffer
		for (unsigned int i = 0; i < texture.characters.size(); i++) {
			//	Formula: Row# = ceil(Element# / Width)
			//	posX = BottomLeftX + Element# - Width * Row#
			//	posY = BottomLeftY + Height - 1 - Row#
			drawPos.x = bottomLeft.x + i - width * (int)ceil(i / width);
			drawPos.y = bottomLeft.y + height - 1 - (int)ceil(i / width);

			DrawCharacterForeground(texture.characters[i], drawPos);
		}
		break;
	case RenderType::Filled:
		for (unsigned int i = 0; i < texture.characters.size(); i++) {
			drawPos.x = bottomLeft.x + i - width * (int)ceil(i / width);
			drawPos.y = bottomLeft.y + height - 1 - (int)ceil(i / width);

			// '%' is transparent
			if (texture.characters[i].textChar != '%') {
				DrawCharacterForeground(texture.characters[i], drawPos);
			}
		}
		break;
	case RenderType::Transparent:
		for (unsigned int i = 0; i < texture.characters.size(); i++) {
			drawPos.x = bottomLeft.x + i - width * (int)ceil(i / width);
			drawPos.y = bottomLeft.y + height - 1 - (int)ceil(i / width);

			// ' ' is transparent
			if (texture.characters[i].textChar != ' ') {
				DrawCharacterForeground(texture.characters[i], drawPos);
			}
		}
		break;
	}
}

std::vector<CHAR_INFO> Texture::ToCHAR_INFO() {
	// Create CHAR_INFO buffer
	std::vector<CHAR_INFO> charBuffer;

	// Convert Character to CHAR_INFO
	for (int y = 0; y < dimensions.y; y++) {
		for (int x = 0; x < dimensions.x; x++) {
			int arrayElement = x + dimensions.x * y;
			charBuffer.push_back(characters[arrayElement]);
		}
	}
	return charBuffer;
}

void Texture::SetColor(Color color) {
	for (int i = 0; i < dimensions.x * dimensions.y; i++) {
		characters[i].color = color;
	}
}

void Texture::SetCharacters(Character fillChar) {
	// Set all characters to the fill character
	for (int y = 0; y < dimensions.y; y++) {
		for (int x = 0; x < dimensions.x; x++) {
			characters[x + dimensions.x * y] = fillChar;
		}
	}
}

void Texture::SetTexture(std::wstring newCharacters, int width, Color color) {
	dimensions = Int2D(width, (newCharacters.size() / width));

	for (int i = 0; i < dimensions.x * dimensions.y; i++) {
		Character character;
		character.textChar = newCharacters[i];
		character.color = color;
		characters.push_back(character);
	}
}

Character& Texture::operator[](int i) {
	return characters[i];
}
