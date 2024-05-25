#include "Factory.h"
#include "Menu.h"
#include "InputCin.h"
#include "InputCin.cpp"
#include <iostream>

using namespace std;

vector<Position> GetPointsLinePositions(Position from, Position to) {
	vector<Position> linePoints{ {from.x, from.y} };
	double fX = from.x,
		fY = from.y,
		tX = to.x,
		tY = to.y;

	while (fX != tX || fY != tY) {
		if (fX < tX)
			fX++;
		if (fY < tY)
			fY++;
		if (fX > tX)
			fX--;
		if (fY > tY)
			fY--;

		linePoints.push_back(Position{ fX, fY });
	}

	return linePoints;
}

bool Factory::Intersect(Circle* circle, Tetragon* tetragon) {
	vector<Position> verticesTetr = tetragon->GetVertices();
	const auto circleCenterPosition = circle->GetCenterPosition();
	const auto circleRadius = circle->GetRadius();

	const auto& positionA = verticesTetr[0];
	const auto& positionB = verticesTetr[1];
	const auto& positionC = verticesTetr[2];
	const auto& positionD = verticesTetr[3];

	vector<Position> pointsFromAToB = GetPointsLinePositions(positionA, positionB);
	vector<Position> pointsFromBToC = GetPointsLinePositions(positionB, positionC);
	vector<Position> pointsFromCToD = GetPointsLinePositions(positionC, positionD);
	vector<Position> pointsFromDToA = GetPointsLinePositions(positionD, positionA);

	vector<vector<Position>> allPoints = {
		pointsFromAToB,
		pointsFromBToC,
		pointsFromCToD,
		pointsFromDToA
	};

	for (const auto& points : allPoints) {
		for (auto& point : points) {
			double distanceBetweenToPointsX {};
			double distanceBetweenToPointsY {};

			double catheterY = abs(point.y - circleCenterPosition.y);
			double catheterX = abs(point.x - circleCenterPosition.x);
			double hypotenuse = sqrt(pow(catheterY, 2) + pow(catheterX, 2));

			if (hypotenuse <= circleRadius) {
				return true;
			}
		}
	}

	return false;
}
bool Factory::Include(Circle* circle, Tetragon* tetragon) {
	vector<Position> vertices = tetragon->GetVertices();

	unsigned short distanceToCenterCircle = 0;
	double circleRaduis = circle->GetRadius();
	Position circleCenter = circle->GetCenterPosition();

	for (const auto& ver : vertices) {
		if (ver.x == circleCenter.x && ver.y == circleCenter.y)
			return false;

		const double distanceCenterCircleByX = abs(ver.x - circleCenter.x);
		const double distanceCenterCircleByY = abs(ver.y - circleCenter.y);

		if (distanceCenterCircleByX >= circleRaduis && distanceCenterCircleByY >= circleRaduis)
			distanceToCenterCircle++;
	}

	if (distanceToCenterCircle == tetragon->GetVertices().size())
		return true;

	return false;
}

void Factory::AddShape() {
	cout << "Select a shape: " << endl;
	cout << " - 1) Circle" << endl;
	cout << " - 2) Tetragon" << endl;

	int item = Menu::SelectItem(2);
	cout << "Enter the title of shape" << endl;
	string name;
	cin >> name;
	cin.get();

	double x, y;
	x = y = 0;
	double radius = 0;
	double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
	Ax = Ay = Bx = By = Cx = Cy = Dx = Dy = 0;

	if (item == 1) {
		cout << "Enter the center position of circle" << endl;

		cout << "X: ";
		InputCin::InputValueFromConsole<double>(&x);

		cout << "Y: ";
		InputCin::InputValueFromConsole<double>(&y);

		cout << "Radius: ";
		InputCin::InputValueFromConsole<double>(&radius);
	}

	if (item == 2) {
		cout << "Enter the coordinates" << endl;

		cout << "A(x)";
		InputCin::InputValueFromConsole<double>(&Ax);

		cout << "A(y)";
		InputCin::InputValueFromConsole<double>(&Ay);

		cout << "B(x)";
		InputCin::InputValueFromConsole<double>(&Bx);

		cout << "B(y)";
		InputCin::InputValueFromConsole<double>(&By);

		cout << "C(x)";
		InputCin::InputValueFromConsole<double>(&Cx);

		cout << "C(y)";
		InputCin::InputValueFromConsole<double>(&Cy);

		cout << "D(x)";
		InputCin::InputValueFromConsole<double>(&Dx);

		cout << "D(y)";
		InputCin::InputValueFromConsole<double>(&Dy);
	}

	Shape* shape;
	
	switch (item) {
	case 1:
		shape = new Circle(name, radius, { x, y });
		break;
	case 2:
	{
		vector<Position> vertices = {
				{Ax, Ay},
				{Bx, By},
				{Cx, Cy},
				{Dx, Dy}
		};
		shape = new Tetragon(name, vertices);
		
		break;
	}
	default:
		cout << "Some Error" << endl;
		break;
	}

	shapes.push_back(shape);
}

const vector<Shape*> Factory::GetShapes() const {
	return shapes;
}

void Factory::DeleteShape() {
	int shapesSize = shapes.size();
	if (!shapesSize) {
		cout << "Shapes is empty" << endl;
		return;
	}
	else {
		cout << "All shapes" << endl;
		auto it = shapes.begin();
		for (const auto& sh : shapes) {
			int index = distance(shapes.begin(), it) + 1;
			cout << "(" << index << ") " << "- Name: " << sh->GetName() << endl;
			++it;
		}
		cout << ">>> Select the serial number of the shpae to delete it" << endl;

		int item = Menu::SelectItem(shapesSize);
		string name = shapes[item - 1]->GetName();

		delete shapes[item - 1];
		shapes.erase(shapes.begin() + (item - 1));

		cout << "Shape called " << name << " removed" << endl;
	}
}