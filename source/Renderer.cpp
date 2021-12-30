#include <iostream>
#include "Renderer.h"

int Renderer::GetWindowWidth() const
{
	return windowWidth;
}

int Renderer::GetWindowHeight() const
{
	return windowHeight;
}

bool Renderer::Setup(int windowWidth, int windowHeight)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
	{
		std::cerr << "Error initializing SDL" << std::endl;
		return false;
	}

	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode(0, &displayMode);
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	
	window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_BORDERLESS);
	if (!window) 
	{
		std::cerr << "Error initializing SDL window" << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer) 
	{
		std::cerr << "Error initializing SDL renderer" << std::endl;
		return false;
	}

	return true;
}

void Renderer::ClearScreen(Uint8 r, Uint8 g, Uint8 b) const
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderClear(renderer);
}

void Renderer::Render() const
{
	SDL_RenderPresent(renderer);
}

void Renderer::DrawPoint(int x, int y, Uint8 r, Uint8 g, Uint8 b) const
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderDrawPoint(renderer, x, y);
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}