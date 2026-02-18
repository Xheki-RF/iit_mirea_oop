#include "ClassA.h"

void ClassA::setY(int y)
{
	this->y = y;
}
int ClassA::getY()
{
	return y;
}
void ClassA::set_vars()
{
	if (x % 2 == 0)
	{
		x /= 2;
	}
	else
	{
		x *= 2;
	}
	
	if (y % 2 == 0)
	{
		y /= 2;
	}
	else
	{
		y *= 2;
	}
}