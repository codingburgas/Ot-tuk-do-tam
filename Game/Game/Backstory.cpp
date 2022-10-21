#include "Precompile.hpp"
#include "Backstory.hpp"

// define a timer
namespace variables {
	unsigned int Lifetime = 0;
	unsigned int timeExtend = 10;
	string my;
	int i = 0;
}

using namespace variables;

void backstoryTypewriteEffect(int& miliseconds, string& text)
{
	Lifetime++;//increment for timer

	if (Lifetime == 10){
		if (IsKeyPressed(KEY_Q))
		{
			i = text.length();
			my = text;
			Lifetime = 11;
		}
		else {
			my += text[i++];
			Lifetime = 0;
		}	  
	}

	DrawText(my.c_str(), 130, 300, 32, BROWN);
}