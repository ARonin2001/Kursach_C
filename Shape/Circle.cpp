#include "Circle.h"
#include "Tetragon.h"
#include "Shape.h"
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

Circle::Circle(string name, double r, Position p) : radius(r) {
	vector<Position> center{ p };
	SetVertices(center);

	diameter = r * 2;
	centerPosition = p;
	this->area = (radius * radius) * PI;
	this->name = name;
}

double Circle::GetRadius() const {
	return radius;
}

Position Circle::GetCenterPosition() const {
	return centerPosition;
}