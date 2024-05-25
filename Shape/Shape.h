#pragma once

#ifndef SHAPE_H
#define SHAPE_H

#include "Position.h"
#include <vector>
#include <iostream>

using namespace std;

class Shape {
public:
	void Move(Position p);
	int Compare(Shape* obj) const;
	double GetArea() const;
	vector<Position> GetVertices() const;
	string GetName() const;
	void ShowData() const;

protected:
	void SetVertices(vector<Position>);
	string name;
	double area;

private:
	vector<Position> vertices;

};

#endif // !SHAPE_H