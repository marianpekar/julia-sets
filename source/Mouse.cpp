#include "Mouse.h"

bool Mouse::IsLeftButtonDown() const
{
    return (buttons & (unsigned char)MouseButton::Left) == (unsigned char)MouseButton::Left;
}

bool Mouse::IsRightButtonDown() const
{
    return (buttons & (unsigned char)MouseButton::Right) == (unsigned char)MouseButton::Right;
}

bool Mouse::IsMiddleButtonDown() const
{
    return (buttons & (unsigned char)MouseButton::Middle) == (unsigned char)MouseButton::Middle;
}

void Mouse::PressButton(MouseButton button)
{
    buttons |= (unsigned char)button;
}

void Mouse::ReleaseButton(MouseButton button)
{
    buttons &= ~(unsigned char)button;
}

