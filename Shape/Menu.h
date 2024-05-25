#pragma once
#ifndef MENU_H
#define MENU_H

#include "Shape.h"
#include "Factory.h"

typedef enum class MenuItems {
	AddShape,
	RemoveShape,
	DisplayShapeData,
	CompareAreas,
	MoveShape,
	IntersectShape,
	IncludeShape,
	Exit,
} JobMode;

class Menu
{
public:
	Menu();
	JobMode SelectJob() const;
	Shape* SelectShape(const Factory &factory) const;
	static int SelectItem(int max);
};

#endif MENU_H

