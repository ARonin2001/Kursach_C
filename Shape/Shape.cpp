#include "Shape.h"
#include <iostream>
#include <vector>

using namespace std;

double Shape::GetArea() const {
	return this->area;
}

void Shape::SetVertices(vector<Position> ver)
{
	this->vertices = ver;
}

vector<Position> Shape::GetVertices() const {
	return this->vertices;
}

void Shape::Move(Position p) {
	for (auto& ver : vertices) {
		ver.x += p.x;
		ver.y += p.y;
	}
}

int Shape::Compare(Shape* obj) const {
	const double objOne = GetArea();
	const double objTwo = obj->GetArea();

	if (objOne == objTwo)
		return 0;
	if (objOne > objTwo)
		return 1;

	return -1;
}

string Shape::GetName() const {
	return name;
}

void Shape::ShowData() const {
	cout << "Name: " << GetName() << endl;
	cout << "Verticies: " << endl;

	for (const auto& v : GetVertices()) {
		cout << "X: " << v.x << " Y: " << v.y << endl;
	}

	cout << "Area: " << GetArea() << endl << endl;
}