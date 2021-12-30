#include <iostream>
#include "Application.h"

void Application::Setup()
{
	renderer = new Renderer();
	mouse = new Mouse();
	
	isRunning = renderer->Setup(1280, 720);

	julia = new Julia(-0.7, 0.27015, renderer->GetWindowWidth(), renderer->GetWindowHeight());
}

void Application::Input()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) 
		{
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)   mouse->PressButton(MouseButton::Left);
			if (event.button.button == SDL_BUTTON_RIGHT)  mouse->PressButton(MouseButton::Right);
			if (event.button.button == SDL_BUTTON_MIDDLE) mouse->PressButton(MouseButton::Middle);
			break;
		case SDL_MOUSEBUTTONUP: 
			if (event.button.button == SDL_BUTTON_LEFT)	  mouse->ReleaseButton(MouseButton::Left);
			if (event.button.button == SDL_BUTTON_RIGHT)  mouse->ReleaseButton(MouseButton::Right);
			if (event.button.button == SDL_BUTTON_MIDDLE) mouse->ReleaseButton(MouseButton::Middle);
			break;

		case SDL_MOUSEWHEEL:
			if (event.wheel.y > 0)
			{
				if		(mouse->IsLeftButtonDown())    julia->MoveReal(calcStep);
				else if (mouse->IsRightButtonDown())   julia->MoveImag(calcStep); 
				else if (mouse->IsMiddleButtonDown())  julia->AddHueShift(hueShiftStep); 
				else								   julia->Zoom(zoomStep);
			}
			else if (event.wheel.y < 0)
			{
				if		(mouse->IsLeftButtonDown())	   julia->MoveReal(-calcStep);
				else if (mouse->IsRightButtonDown())   julia->MoveImag(-calcStep);
				else if (mouse->IsMiddleButtonDown())  julia->AddHueShift(-hueShiftStep);
				else								   julia->Zoom(-zoomStep); 
			}
			break;

		case SDL_QUIT:
			isRunning = false;
			break;

		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;

			if		(event.key.keysym.sym == SDLK_UP)	 julia->MoveCenterY(-moveStep); 
			else if (event.key.keysym.sym == SDLK_DOWN)	 julia->MoveCenterY(moveStep);

			if		(event.key.keysym.sym == SDLK_LEFT)	 julia->MoveCenterX(-moveStep); 
			else if (event.key.keysym.sym == SDLK_RIGHT) julia->MoveCenterX(moveStep);

			break;
		}
	}
}

void Application::Update() 
{
	//julia->Zoom(0.1f);
	//julia->AddHueShift(-1);
	julia->Calculate();
}

void Application::Render()
{
	julia->Draw(renderer);
	renderer->Render();
}

bool Application::IsRunning() const
{
	return isRunning;
}

void Application::Destroy()
{
	delete mouse;
	delete renderer;
	delete julia;
}
