#pragma once
#include"Precompile.hpp"
class Bg
{
	protected:
		Texture2D background;
		unsigned int speedBg;
		Vector2 limits;
	public:
		int XBg, YBg;
		Bg();
};