/*********************************\

OVERVIEW:
 On creation, takes control of the existing console window and
 provides extra functionality for it.

Author:			YZM
Creation:		Nov 23, 2020
Last Editor:	YZM
Last Edit:		Dec 01, 2020
Zombie Mop Studios | Unicode Render Engine

\*********************************/

#ifndef UNICODE_RENDERER_H
#define UNICODE_RENDERER_H
#pragma once

#include <memory>
#define UNICODE
#include "Window.h"
#include "Int2D.h"
#include "Texture.h"

class UnicodeRenderer {
private:
	Texture screenBuffer;
	LPCWSTR title;

	COORD screenBufferPosition;
	SMALL_RECT windowSize;
public:
	// Window Handles
	HANDLE consoleOutput;
	HANDLE consoleInput;
	HWND consoleWindow;

	UnicodeRenderer(Int2D windowDimensions = Int2D(120, 30), LPCWSTR windowName = L"Rendering Window", Character defaultChar = Character(' '));

	void SetTitle(LPCWSTR title);
	LPCWSTR GetTitle() { return title; }


	void Render();

	Window CreateChildWindow();
};

#endif // UNICODE_RENDERER_H
