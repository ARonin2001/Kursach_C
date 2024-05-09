#pragma once
#include "Position.h"

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
	virtual void Move(Position p) = 0;
	virtual void Compare(double area) = 0;
	virtual bool Intersect(double areaShape, Position p) = 0;
	virtual bool Include() = 0;

public:
	bool GetArea() const;

private:
	double area;
};

#endif // !SHAPE_H