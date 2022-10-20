#include "Precompile.hpp"
#include "Backstory.hpp"

void backstoryTypewriteEffect(int& miliseconds, string& text)
{
	for (int i = 0; i < text.size(); i++)
	{
		DrawText(text.c_str(), 0, 0, 24, BROWN);
		this_thread::sleep_for(chrono::milliseconds(miliseconds));
	}
}