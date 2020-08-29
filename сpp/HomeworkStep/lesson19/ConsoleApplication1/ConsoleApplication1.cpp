#include "CircleInSquare.h"

#include <iostream>

int main()
{
    float a = 2;
    float r = 1;
    Square mySquare = Square(a);
    CircleInSquare myCircle = CircleInSquare(r);
    std::cout << myCircle.getRadius() << std::endl;
    std::cin.get();
    return 0;
}
