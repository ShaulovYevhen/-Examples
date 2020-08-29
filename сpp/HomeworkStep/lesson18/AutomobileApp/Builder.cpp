#include "Builder.h"

Builder::Builder(const char* n, int number): Special (n , number)
{
}

void Builder::work()
{
	cout << "Working\n";
}
