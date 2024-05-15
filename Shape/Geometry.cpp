#include <iostream>
#include "Position.h"
#include "Circle.h"
#include "Tetragon.h"
#include <vector>

using namespace std;

int main()
{
    Position circleCenterPosition { 0, 1 };
    Circle circle {4, circleCenterPosition};

    Position tetragonVertices[4];
    tetragonVertices[0] = Position{ 2, 1 };
    tetragonVertices[1] = Position{ 2, 5 };
    tetragonVertices[2] = Position{ 9, 5 };
    tetragonVertices[3] = Position{ 9, 1 };

    double width = 7,
        height = 4;
    
    Shape* tetragon = new Tetragon { tetragonVertices, Position {4, 1}, width, height };

    cout << circle.Intersect(tetragon);
    cout << "Include: " << circle.Include(tetragon);
} 
