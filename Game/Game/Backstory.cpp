#include "Precompile.hpp"
#include "Backstory.hpp"

void backstoryTypewriteEffect(int& miliseconds, string& text)
{
	for (int i = 0; i < text.size(); i++)
	{
		const char* textChar = text.c_str();
		DrawText(textChar, 0, 0, 24 ,BROWN);
		cout << text[i];
		this_thread::sleep_for(chrono::milliseconds(miliseconds));
	}
}