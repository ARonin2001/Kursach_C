#include "Shape.h"
#include "Position.h"
#include "Tetragon.h"
#include <vector>

#pragma once

using namespace std;

class Circle : public Shape
{
public:
	Circle(double r, Position p);

public:
	bool Intersect(Shape* shape) override;
	bool Include(Shape* shape) override;

private:
	double radius,
		diameter,
		area;
	const double PI = 3.14;
};

