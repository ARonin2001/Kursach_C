#pragma once

#ifndef FACTORY_H
#define FACTORY_H

#include "Shape.h"
#include "Circle.h"
#include "Tetragon.h"

using namespace std;

class Factory
{
public:
	bool Intersect(Circle* circle, Tetragon* tetragon);
	bool Include(Circle* circle, Tetragon* tetragon);
	void AddShape();
	void DeleteShape();

	const vector<Shape*> GetShapes() const;
private:
	vector<Shape*> shapes;
};

#endif