#include "Circle.h"
#include "Tetragon.h"
#include "Shape.h"
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

Circle::Circle(double r, Position p) : radius(r) {
	diameter = r * 2;
	centerPosition = p;
	area = (radius * radius) * PI;
}

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

bool Circle::Intersect(Shape* shape) {
	vector<pair<char, Position>> ver = shape->GetVertices();
	const auto& positionA = ver[0];
	const auto& positionB = ver[1];
	const auto& positionC = ver[2];
	const auto& positionD = ver[3];

	vector<Position> pointsFromAToB = GetPointsLinePositions(positionA.second, positionB.second);
	vector<Position> pointsFromBToC = GetPointsLinePositions(positionB.second, positionC.second);
	vector<Position> pointsFromCToD = GetPointsLinePositions(positionC.second, positionD.second);
	vector<Position> pointsFromDToA = GetPointsLinePositions(positionD.second, positionA.second);

	vector<vector<Position>> allPoints;
	allPoints.push_back(pointsFromAToB);
	allPoints.push_back(pointsFromBToC);
	allPoints.push_back(pointsFromCToD);
	allPoints.push_back(pointsFromDToA);

	for (const auto& points : allPoints) {
		for (auto& pointsFrom : points) {
			if (pointsFrom.x == Circle::centerPosition.x) {
				double space = abs(pointsFrom.y - Circle::centerPosition.y);

				if (space <= Circle::radius) {
					cout << "x ==" << endl;
					cout << "Circle X: " << Circle::centerPosition.x << " Y: "
						<< Circle::centerPosition.y << endl;
					cout << "Point X: " << pointsFrom.x << " Y: " << pointsFrom.y << endl;
					return true;
				}
				continue;
			}

			if (pointsFrom.y == Circle::centerPosition.y) {
				double space = abs(pointsFrom.x - Circle::centerPosition.x);

				if (space <= Circle::radius) {
					cout << "y ==" << endl;

					cout << "Circle X: " << Circle::centerPosition.x << " Y: "
						<< Circle::centerPosition.y << endl;
					cout << "Point X: " << pointsFrom.x << " Y: " << pointsFrom.y << endl;
					return true;
				}
				continue;
			}

			double catheterY = abs(pointsFrom.y - Circle::centerPosition.y);
			double catheterX = abs(pointsFrom.x - Circle::centerPosition.x);
			double hypotenuse = sqrt(pow(catheterY, 2) + pow(catheterX, 2));

			if (hypotenuse <= Circle::radius) {
				cout << "hypotenuse" << endl;

				cout << "Circle X: " << Circle::centerPosition.x << " Y: " 
					<< Circle::centerPosition.y << endl;
				cout << "Point X: " << pointsFrom.x << " Y: " << pointsFrom.y << endl;
				return true;
			}
			
		}
	}

	return false;
}
bool Circle::Include(Shape* shape) {
	vector<pair<char, Position>> vertices = shape->GetVertices();
	unsigned short distanceToCenterCircle = 0;

	for (const auto& ver : vertices) {
		if (ver.second.x == this->centerPosition.x && ver.second.y == this->centerPosition.y)
			return false;

		const double distanceCenterCircleByX = abs(ver.second.x - this->centerPosition.x);
		const double distanceCenterCircleByY = abs(ver.second.y - this->centerPosition.y);

		if (distanceCenterCircleByX >= this->radius && distanceCenterCircleByY >= this->radius)
			distanceToCenterCircle++;
		
	}

	if (distanceToCenterCircle == 4)
		return true;

	return false;
}