#pragma once
#include "Shape.h"
#include <vector>

using namespace std;

class Tetragon :
    public Shape
{
public:
	Tetragon(string name, vector<Position> vertices);
};

