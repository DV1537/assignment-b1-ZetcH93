#include "pch.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#include "shape.h"
#include "line.h"
#include "point.h"
#include "polygon.h"
#include "triangel.h"
#include "getShape.h"
#include "operators.h"
#include "figure.h"



using namespace std;


int main(int argc, const char * argv[])
{

	double input = 0;
	int nrOfcords1 = 0;
	int nrOfcords2 = 0;
	double *shapeNr1 = new double[nrOfcords1];
	double *shapeNr2 = new double[nrOfcords2];


	std::ifstream myReadFile;

	myReadFile.open("vertices.txt");

	if (myReadFile.is_open())
	{

		string firstL;
		getline(myReadFile, firstL);

		stringstream stream(firstL);

		while (stream >> input)
		{
			nrOfcords1++;

			double* tempArr = new double[nrOfcords1];
			for (int i = 0; i < nrOfcords1; i++)
				tempArr[i] = shapeNr1[i];
			delete[] shapeNr1;
			shapeNr1 = nullptr;
			shapeNr1 = new double[nrOfcords1];

			for (int i = 0; i < nrOfcords1; i++)
				shapeNr1[i] = tempArr[i];
			delete[] tempArr;
			tempArr = nullptr;


			shapeNr1[nrOfcords1 - 1] = input;

		}



		string secondL;
		getline(myReadFile, secondL);

		stringstream stream2(secondL);

		while (stream2 >> input)
		{
			nrOfcords2++;

			double* tempArr = new double[nrOfcords2];
			for (int i = 0; i < nrOfcords2; i++)
				tempArr[i] = shapeNr2[i];
			delete[] shapeNr2;
			shapeNr2 = nullptr;
			shapeNr2 = new double[nrOfcords2];

			for (int i = 0; i < nrOfcords2; i++)
				shapeNr2[i] = tempArr[i];
			delete[] tempArr;
			tempArr = nullptr;


			shapeNr2[nrOfcords2 - 1] = input;

		}


		myReadFile.close();

	}
	else
	{
		cout << "Could not open file. \n";
		exit(EXIT_FAILURE);
	}



	double *xCord1 = new double[nrOfcords1 / 2];
	double *yCord1 = new double[nrOfcords1 / 2];


	for (int i = 0; i < nrOfcords1; i++)
	{
		int cordIndex = (i / 2);
		if (i % 2 == 0)
			xCord1[cordIndex] = shapeNr1[i];
		else
			yCord1[cordIndex] = shapeNr1[i];
	}


	double *xCord2 = new double[nrOfcords2 / 2];
	double *yCord2 = new double[nrOfcords2 / 2];

	for (int i = 0; i < nrOfcords2; i++)
	{
		int cordIndex = (i / 2);
		if (i % 2 == 0)
			xCord2[cordIndex] = shapeNr2[i];
		else
			yCord2[cordIndex] = shapeNr2[i];
	}


	if (nrOfcords1 == 0 || nrOfcords1 % 2 == 1)
	{
		cout << "That is not a shape.." << endl;
		exit(EXIT_FAILURE);
	}

	if (nrOfcords2 == 0 || nrOfcords2 % 2 == 1)
	{
		cout << "That is not a shape.." << endl;
		exit(EXIT_FAILURE);
	}


	Shape &shape1 = getShape(nrOfcords1, xCord1, yCord1);
	Shape &shape2 = getShape(nrOfcords2, xCord2, yCord2);
	

	Figure figure;
	figure.addShape(shape1);
	figure.addShape(shape2);
	figure.getBoundingBox();
	



	return 0;
}