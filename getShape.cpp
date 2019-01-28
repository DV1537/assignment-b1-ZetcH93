#include "pch.h"
#include "getShape.h"


Shape& getShape(int nrOfCords, double *xCord, double *yCord)
{
	Shape* shape = nullptr;
	int vertices = (nrOfCords / 2);

	if (nrOfCords > 6)
	{
		shape = new Polygon(xCord, yCord, nrOfCords);

	}
	else if (nrOfCords == 6)
	{
		shape = new Triangel(xCord, yCord, nrOfCords);

	}
	else if (nrOfCords == 4)
	{
		shape = new Line(xCord, yCord, nrOfCords);

	}
	else if (nrOfCords == 2)
	{
		shape = new Point(xCord, yCord, nrOfCords);
	}
	return *shape;
}