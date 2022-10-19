#include "Precompile.hpp"
#include "Backstory.hpp"

void backstory(int& miliseconds, string& text)
{
	for (int i = 0; i < text.size(); i++)
	{
		cout << text[i];
		this_thread::sleep_for(chrono::milliseconds(miliseconds));
	}
}