#include "pch.h"
#include "figure.h"
#include <iostream>


void Figure::addShape(Shape &shape)
{
	shapePtr[nrOfShapes] = &shape;
	nrOfShapes++;
}

void Figure::getBoundingBox()
{
	double bigX = shapePtr[0]->getXCord()[0], bigY = shapePtr[0]->getYCord()[0], smallX = shapePtr[0]->getXCord()[0], smallY = shapePtr[0]->getXCord()[0];
	for (int j = 0; j < nrOfShapes; j++)
	{
		for (int i = 0; i < (shapePtr[j]->getPoints())/2; i++)
		{
			if (shapePtr[j]->getXCord()[i] > bigX)
			{
				bigX = shapePtr[j]->getXCord()[i];
			}
			if (shapePtr[j]->getYCord()[i] > bigY)
			{
				bigY = shapePtr[j]->getYCord()[i];
			}
			if (shapePtr[j]->getXCord()[i] < smallX)
			{
				smallX = shapePtr[j]->getXCord()[i];
			}
			if (shapePtr[j]->getYCord()[i] < smallY)
			{
				smallY = shapePtr[j]->getYCord()[i];
			}
		}
	}

	smallX= ((smallX * 1000) / 1000.0);
	bigY = ((bigY * 1000) / 1000.0);
	bigX = ((bigX * 1000) / 1000.0);
	smallY = ((smallY * 1000) / 1000.0);


	cout << "Top-Left coords: (" << smallX << "," << bigY << ") , Bottom-Right coords: (" << bigX << "," << smallY << ")" << endl;
}

int Figure::nrOfShapes = 0;


