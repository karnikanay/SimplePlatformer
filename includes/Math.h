#pragma once

class Vector2
{
public:

  float x;
  float y;
  
  // Constructors
  Vector2();
  Vector2(float x, float y);

  // Addition operator on two vectors
  Vector2 operator+(const Vector2 &b);

  // Declare basic Vector2 constants
  static const Vector2 Zero;
};

