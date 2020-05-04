#include "Math.h"

// Initialize basic vector constants
const Vector2 Vector2::Zero(0.0f, 0.0f);

Vector2::Vector2(float x, float y)
:x(x)
,y(y)
{}

Vector2::Vector2() 
{}

Vector2 Vector2::operator+(const Vector2 &b)
{
  return Vector2(this->x + b.y, this->y + b.y);
}

