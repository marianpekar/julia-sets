#pragma once

enum class MouseButton : unsigned char {
	Left = 1,
	Right = 2,
	Middle = 4,
};

class Mouse
{
private:
	unsigned char buttons; 

public:
	Mouse() = default;
	~Mouse() = default;

	bool IsLeftButtonDown() const;
	bool IsRightButtonDown() const;
	bool IsMiddleButtonDown() const;

	void PressButton(MouseButton button);
	void ReleaseButton(MouseButton button);

	void UpdatePosition(int x, int y);
};
