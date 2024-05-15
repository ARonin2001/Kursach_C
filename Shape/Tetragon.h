#pragma once
#include "Shape.h"
#include <vector>

using namespace std;

class Tetragon :
    public Shape
{
public:
	Tetragon(Position vertices[4], Position p, double width, double height);

public:
	bool Intersect(Shape* shape) override;
	bool Include(Shape* shape) override;

private:
	double area;

};

