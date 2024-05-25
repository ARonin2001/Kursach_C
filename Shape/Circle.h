#include "Shape.h"
#include "Position.h"
#include "Tetragon.h"
#include <vector>

#pragma once

using namespace std;

class Circle : public Shape
{
public:
	Circle(string name, double r, Position p);
	double GetRadius() const;
	Position GetCenterPosition() const;

private:
	double radius,
		diameter;

	const double PI = 3.14;
	Position centerPosition;
};

