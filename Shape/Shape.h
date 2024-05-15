#pragma once

#include "Position.h"
#include <vector>

#ifndef SHAPE_H
#define SHAPE_H

using namespace std;

class Shape {
public:
	void Move(Position p);
	void Compare(double _area);
	virtual bool Intersect(Shape* shape) = 0;
	virtual bool Include(Shape* shape) = 0;

public:
	bool GetArea() const;
	void SetVertices(Position vertices[4]);  
	vector<pair<char, Position>> GetVertices();

private:
	double area;
	vector<pair<char, Position>> vertices;

protected:
	Position centerPosition;

};

#endif // !SHAPE_H