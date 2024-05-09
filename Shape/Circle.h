#include "Shape.h"
#include "Position.h"
#include <vector>

#pragma once

using namespace std;

class Circle : public Shape
{
public:
	Circle(double r, Position p);

public:
	void Move(Position p) override;
	void Compare(double areaShape) override;
	bool Intersect(double areaShape, Position p) override;
	bool Include() override;
	vector<pair<double, double>> circle_to_point_array();

private:
	double radius,
		diameter,
		area;
	const double PI = 3.14;

	Position position;
};

