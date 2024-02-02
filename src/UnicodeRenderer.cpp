#include "UnicodeRenderer.h"

UnicodeRenderer::UnicodeRenderer(Int2D windowDimensions, LPCWSTR windowName, Character defaultChar)
	: screenBuffer(defaultChar, windowDimensions) {

	// Initialize Handles
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	consoleInput = GetStdHandle(STD_INPUT_HANDLE);
	consoleWindow = GetConsoleWindow();

	// Set Window Size
	windowSize = { 0, 0, (SHORT)screenBuffer.GetDimensions().x - 1, (SHORT)screenBuffer.GetDimensions().y - 1 };
	SetConsoleWindowInfo(consoleOutput, TRUE, &windowSize);
	
	// TODO: FIX SCROLL BARS APPEARING ON SCREEN SIZE CHANGE UNTIL PROPERTY REFRESH ON RIGHT CLICK
	/* current attempts... none working
	RECT r;
	GetWindowRect(consoleWindow, &r);
	CONSOLE_FONT_INFO font;
	GetCurrentConsoleFont(consoleOutput, FALSE, &font);
	COORD fontSize = GetConsoleFontSize(consoleOutput, font.nFont);

	MoveWindow(consoleWindow, r.left, r.top, screenBuffer.GetDimensions().x * fontSize.X, screenBuffer.GetDimensions().y * fontSize.Y, TRUE);
	*/
	
	// Set Window Style (not resizeable)
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	// Set Window Title
	SetTitle(windowName);

	// Set Screen Buffer Size
	SetConsoleScreenBufferSize(consoleOutput, screenBuffer.GetDimensions());
	// Enable Mouse Input
	SetConsoleMode(consoleInput, ENABLE_MOUSE_INPUT | ENABLE_WINDOW_INPUT | ENABLE_EXTENDED_FLAGS & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
}

void UnicodeRenderer::SetTitle(LPCWSTR title) {
	this->title = title;
	SetConsoleTitle(title);
}

void UnicodeRenderer::Render() {
	// TODO: integrate sprite system to URE
	// TODO: delete test cases
	screenBuffer.DrawCharacter(Character(L'☒', TEXT_RED), Int2D(3, 3));
	screenBuffer.DrawTexture(Texture(L"Asdfgbreath0123456789A", 11, TEXT_LIGHT_BLUE | BACK_DARK_GREEN), Int2D(20, 6), RenderType::Opaque);
	screenBuffer.DrawTexture(Texture(L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", 36, TEXT_LIGHT_BLUE), Int2D(1, 1), RenderType::Opaque);
	screenBuffer.DrawTextureForeground(Texture(Character(L'☒'), Int2D(8, 4)), Int2D(24, 5), RenderType::Opaque);

	// Write the screen buffer
	WriteConsoleOutput(consoleOutput, screenBuffer.ToCHAR_INFO().data(), screenBuffer.GetDimensions(), { 0, 0 }, &windowSize);
}

Window UnicodeRenderer::CreateChildWindow() {
	return Window();
}