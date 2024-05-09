#include "Circle.h"
#include <iostream>
#include <math.h>
//#include <vector>

using namespace std;

Circle::Circle(double r, Position p) : radius(r) {
	diameter = r * 2;
	position = p;
	area = (radius * radius) * PI;
}

void Circle::Move(Position p) {
	position.x += p.x;
	position.y += p.y;

	cout << "The circle has moved to the coordinates" << endl;
	cout << "X: " << position.x << " Y: " << position.y << "\n\n";
}
void Circle::Compare(double areaShape) {
	if (areaShape == area)
		cout << "The areas of the figures are equal \n\n";
	if (areaShape > area)
		cout << "The area of the circle is smaller \n\n";
	if (areaShape < area)
		cout << "The area of the circle is larger \n\n";
}
bool Circle::Intersect(double distanceFromCenter, Position p) {
	int distanceCenterObjectsX = abs(position.x - p.x);
	int distanceCenterObjectsY = abs(position.y - p.y);
	
	double distanceFromCenterToEdge = radius;
	double sumDistances = distanceFromCenterToEdge + distanceFromCenter;

	if (sumDistances > distanceCenterObjectsX && sumDistances > distanceCenterObjectsY) {
		return true;
	}
	return false;
}
bool Circle::Include() {
	return false;
}

vector<pair<double, double>> Circle::circle_to_point_array()
{
	const unsigned short countPoints = 100;
	vector<pair<double, double>> points;
	
	for (int i = 0; i < countPoints; i++) {
		double angle = 2 * PI * i / countPoints;
		double x = position.x + radius * cos(angle);
		double y = position.y + radius * sin(angle);
		points.push_back(make_pair(x, y));
	}
	return points;
}

//vector<pair<double, double>> Circle::circleToPointArray() {
//	const unsigned short countPoints = 100;
//	vector<pair<double, double>> points;
//
//	for (int i = 0; i < countPoints; i++) {
//		double angle = 2 * PI * i / countPoints;
//		double x = position.x + radius * cos(angle);
//		double y = position.y + radius * sin(angle);
//		points.push_back(make_pair(x, y));
//	}
//	return points;
//}