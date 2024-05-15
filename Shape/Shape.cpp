#include "Shape.h"
#include <iostream>
#include <vector>

using namespace std;

bool Shape::GetArea() const {
	return area;
}

void Shape::SetVertices(Position vertices[4])
{
	vector<pair<char, Position>> ver(4);

	ver[0] = make_pair('A', vertices[0]);
	ver[1] = make_pair('B', vertices[1]);
	ver[2] = make_pair('C', vertices[2]);
	ver[3] = make_pair('D', vertices[3]);

	this->vertices = ver;
}

vector<pair<char, Position>> Shape::GetVertices() {
	return this->vertices;
}

void Shape::Move(Position p) {
	centerPosition.x += p.x;
	centerPosition.y += p.y;
}

void Shape::Compare(double _area) {
	if (_area == area)
		cout << "The areas of the figures are equal \n\n";
	if (_area > area)
		cout << "The area of the circle is smaller \n\n";
	if (_area < area)
		cout << "The area of the circle is larger \n\n";
}