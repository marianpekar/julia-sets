#pragma once

#include <SDL.h>

class Renderer {
private:
	int windowWidth, windowHeight;

	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	Renderer() = default;
	~Renderer();
	
	int GetWindowWidth() const;
	int GetWindowHeight() const;

	bool Setup(int windowWidth, int windowHeigth);

	void ClearScreen(Uint8 r, Uint8 g, Uint8 b) const;
	void Render() const;

	void DrawPoint(int x, int y, Uint8 r, Uint8 g, Uint8 b) const;
};