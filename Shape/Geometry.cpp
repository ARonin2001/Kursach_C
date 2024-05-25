#include <iostream>
#include "Position.h"
#include "Circle.h"
#include "Tetragon.h"
#include "Factory.h"
#include "Menu.h"
#include "InputCin.h"
#include "InputCin.cpp"
#include <vector>

using namespace std;

void CompareShapes(Menu* menu, Factory* factory) {
    cout << "Choose two shapes to compare" << endl;
    Shape* shapeOne = menu->SelectShape(*factory);
    if (shapeOne == 0) return;

    Shape* shapeTwo = menu->SelectShape(*factory);
    const int result = shapeOne->Compare(shapeTwo);

    if (result == 0)
        cout << "The areas of the figures are equal" << endl;
    if (result == 1) {
        cout << "The area of shape " << shapeOne->GetName()
            << " is bigger than the area of shape "
            << shapeTwo->GetName() << endl;
    }

    if (result == -1)
    {
        cout << "The aera of shape " << shapeTwo->GetName()
            << " is bigger than the area of shape "
            << shapeOne->GetName() << endl;
    }
}

Circle* GetCircle(Shape* shape) {
    double r = sqrt(shape->GetArea() / 3.14);
    vector<Position> v = shape->GetVertices();
    return new Circle(shape->GetName(), r, { v[0].x, v[0].y });
}

Tetragon* GetTetragon(Shape* shape) {
    return new Tetragon(shape->GetName(), shape->GetVertices());
}


bool IntersectIncludeShapes(Menu* menu, Factory* factory, bool isIntersect = true) {
    cout << "Choose circle and tetragon" << endl;
    Shape* shapeOne = menu->SelectShape(*factory);
    if (shapeOne == 0) return false;

    Shape* shapeTwo = menu->SelectShape(*factory);

    const int lengthVerticiesShapeOne = shapeOne->GetVertices().size();
    const int lengthVerticiesShapeTwo = shapeTwo->GetVertices().size();

    Circle* circle;
    Tetragon* tetragon;

    if (lengthVerticiesShapeOne > 1 && lengthVerticiesShapeTwo > 1) {
        cout << "CHOICE CIRCLE AND TETRAGON" << endl;
        return false;
    }

    if (lengthVerticiesShapeOne == 1 && lengthVerticiesShapeTwo == 1) {
        cout << "CHOICE CIRCLE AND TETRAGON" << endl;
        return false;
    }

    if (lengthVerticiesShapeOne == 1) {
        circle = GetCircle(shapeOne);
        tetragon = GetTetragon(shapeTwo);
    }
    else {
        circle = GetCircle(shapeTwo);
        tetragon = GetTetragon(shapeOne);
    }

    if (isIntersect)
        return factory->Intersect(circle, tetragon);

    return factory->Include(circle, tetragon);
}

void Move(Menu* menu, Factory* factory) {
    Shape* shape = menu->SelectShape(*factory);
    if (shape != 0) {
        cout << "Enter the coordinates as far as you want to move the shape" << endl;
        Position p;
        cout << "X:" << endl;
        InputCin::InputValueFromConsole<double>(&p.x);
        cout << "Y:" << endl;
        InputCin::InputValueFromConsole<double>(&p.y);

        shape->Move(p);
        cout << "Now the shape is located at the coordinates: " << endl;
        for (const auto& v : shape->GetVertices()) {
            cout << "X: " << v.x << " Y: " << v.y << endl;
        }
    }
}

int main()
{
    Menu* menu = new Menu();
    Factory* factory = new Factory();
    JobMode menuItem {};

    while (menuItem != JobMode::Exit ) {
        menuItem = menu->SelectJob();

        switch (menuItem)
        {
        case JobMode::AddShape:
            factory->AddShape();
            break;
        case JobMode::RemoveShape:
            factory->DeleteShape();
            break;
        case JobMode::DisplayShapeData:
        {
            Shape* shape = menu->SelectShape(*factory);
            if (shape != 0) 
                shape->ShowData();
        }
            break;
        case JobMode::CompareAreas:
            CompareShapes(menu, factory);
            break;
        case JobMode::MoveShape:
            Move(menu, factory);
            break;
        case JobMode::IntersectShape:
        {
            bool result = IntersectIncludeShapes(menu, factory);
            if (result) {
                cout << "The shapes intersect" << endl;
            }
            else {
                cout << "The shapes do not intersect" << endl;
            }
        }
            break;
        case JobMode::IncludeShape:
        {
            bool result = IntersectIncludeShapes(menu, factory, false);
            if (result) {
                cout << "The shapes includes" << endl;
            }
            else {
                cout << "The shapes do not includes" << endl;
            }
        }
            break;
        case JobMode::Exit:
            cout << "The program is completed" << endl;
            exit(0);
        default:
            break;
        }
    }
} 
