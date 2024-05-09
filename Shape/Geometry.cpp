#include <iostream>
#include "Circle.h"
#include <vector>

using namespace std;

int main()
{
    auto circle = new Circle(217.53, {2.5, 5.3});
    vector<pair<double, double>> circlePoints = circle->circle_to_point_array();

    for (int i = 0; i < circlePoints.size(); i++) {
        cout << "Point X: " << circlePoints[i].first << " Point Y: " << circlePoints[i].second;
    }
}
