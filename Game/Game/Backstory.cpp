#include "Precompile.hpp"
#include "Backstory.hpp"

// define a timer
namespace variables {
	int Lifetime = 9;
	string my;
	int i = 0;
}

using namespace variables;

void backstoryTypewriteEffect(int& miliseconds, string& text)
{
	Lifetime++;//increment for timer
	
	if (IsKeyPressed(KEY_ENTER)){
		i = text.length();
		my = text;
		Lifetime = 11;
	}
	if (Lifetime == 10 && !IsKeyPressed(KEY_ENTER)){	
			my += text[i++];
			Lifetime = 0;
	}

	DrawText(my.c_str(), 130, 300, 32, BROWN);
}