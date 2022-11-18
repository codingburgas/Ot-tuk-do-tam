#include "Precompile.hpp"
#include "Backstory.hpp"

// define a timer
namespace variables {
	int Lifetime = 4;
}

using namespace variables;

void typewriteEffect(string& text, int posX, int posY, int fontSize, Color color, int& counter)
{
	Lifetime++;//increment for timer

	if (Lifetime == 5 && text[counter] != text[text.length()]) {
		counter++;
		Lifetime = 0;
	}

	DrawText(text.substr(0, counter).c_str(), posX, posY, fontSize, color);
}