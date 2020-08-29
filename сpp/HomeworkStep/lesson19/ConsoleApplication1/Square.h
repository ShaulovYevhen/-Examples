#pragma once
class Square
{
	int side;
public:
	Square(int _side) : side(_side) { }
    int getSide()
    {
        return side;
    }
    void setDiameter(int _side)
    {
        side = _side;
    }
};

