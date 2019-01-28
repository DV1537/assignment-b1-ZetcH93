#pragma once
#include "pch.h"
#include "shape.h"



class Figure
{
	Shape **shapePtr = new Shape*[2];
	static int nrOfShapes;

public:

	void addShape(Shape &shape);
	void getBoundingBox();

};