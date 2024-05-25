#include "Tetragon.h"
#include "Circle.h"
#include <vector>
#include <iostream>

using namespace std;

Tetragon::Tetragon(string name, vector<Position> vertices) {
	double width = abs(vertices[3].x - vertices[0].x);
	double height = abs(vertices[1].y - vertices[0].y);
	this->area = width * height;
	this->name = name;

	this->SetVertices(vertices);
}