#pragma once

#include "Renderer.h"
#include "Mouse.h"
#include "Julia.h"

struct Application 
{
private:
	Renderer* renderer = nullptr;
	Mouse* mouse = nullptr;
	Julia* julia = nullptr;

	bool isRunning = false;

	double zoomStep = 0.1f, moveStep = 0.001f, calcStep = 0.0001f;
	int hueShiftStep = 3;

public:
	Application() = default;
	~Application() = default;
	
	bool IsRunning() const;

	void Setup();
	void Input();
	void Update();
	void Render();
	void Destroy();
};