#pragma once
class Circle
{
    int radius;
public:
    Circle(int _radius) : radius(_radius) { }
    int getRadius()
    {
        return radius;
    }
    void setRadius(int _radius)
    {
        radius = _radius;
    }
};

