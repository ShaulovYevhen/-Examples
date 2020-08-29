#pragma once
#include "Square.h"
#include "Circle.h"
class CircleInSquare :	public Square, public Circle
{
public:
	CircleInSquare(int radius) : Square(radius*2), Circle(radius) { }
};

