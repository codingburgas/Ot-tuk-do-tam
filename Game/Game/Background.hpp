#pragma once
#include"Precompile.hpp"
class Bg
{
	protected:
		Texture2D background;
		Vector2 limits;
	public:
		unsigned int speedBg;
		int XBg, YBg;
		Bg();
};