#include "Precompile.hpp"
#include "Engine.hpp"

namespace variables {
	Image icon = LoadImage("../src/sprites/icon.png");
}

using namespace variables;

void setIcon()
{
	SetWindowIcon(icon);
}