#include "Tetragon.h"
#include "Circle.h"
#include <vector>
#include <iostream>

using namespace std;

Tetragon::Tetragon(Position vertices[4], Position p, double width, double height) {
	centerPosition = p;
	area = width * height;
	this->SetVertices(vertices);
}

bool Tetragon::Intersect(Shape* shape) {
	return false;
}

bool Tetragon::Include(Shape* shape) {
	return false;
}
