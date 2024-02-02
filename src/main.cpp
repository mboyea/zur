/*********************************\

OBJECTIVE:
Test the Unicode Render Engine.

Author:			YZM
Creation:		Nov 23, 2020
Last Editor:	YZM
Last Edit:		Nov 23, 2020
Zombie Mop Studios | Unicode Render Engine

\*********************************/

#include "UnicodeRenderer.h"

int main() {
	UnicodeRenderer window(Int2D(120, 30));
	while (true) {
		window.Render();
	}
	return 0;
}
