#pragma once

#include "SDL.h"

static class ColorUtils
{
public:
	static void HSVtoRGB(Uint8 H, Uint8 S, Uint8 V, Uint8& R, Uint8& G, Uint8& B);
};