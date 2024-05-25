#include "Menu.h"
#include "Shape.h"
#include "InputCin.h"
#include "InputCin.cpp"
#include <iterator>
#include <iostream>

using namespace std;

Menu::Menu() = default;

JobMode Menu::SelectJob() const {
	cout << ">>>>>>>>>>> MENU <<<<<<<<<<<<" << endl << endl;;
	cout << " - 1) Create a new shape" << endl;
	cout << " - 2) Remove a shape" << endl;
	cout << " - 3) Show data of shape" << endl;
	cout << " - 4) Compare" << endl;
	cout << " - 5) Move" << endl;
	cout << " - 6) Intersect" << endl;
	cout << " - 7) Include" << endl;
	cout << " - 8) Exit" << endl << endl;;
	cout << ">>>>>>>>> END MENU <<<<<<<<<<" << endl;

	int item = SelectItem(8);
	return (JobMode)(item - 1);
}

Shape* Menu::SelectShape(const Factory &factory) const {
	vector<Shape*> shapes(factory.GetShapes());
	auto shapesSize = shapes.size();

	if (!shapesSize) {
		cout << "The shapes is empty" << endl;
		cin.get();
		return 0;
	}

	cout << "--------------------------------" << endl;
	cout << "Select a shape" << endl;
	auto it = shapes.begin();
	for (const auto& sh : shapes) {
		int index = distance(shapes.begin(), it) + 1;
		cout << "(" << index << ") " << "Shape Name: " << sh->GetName() << endl;
		++it;
	}
	cout << "--------------------------------" << endl;

	int item = int(SelectItem(shapesSize));
	return shapes[item - 1];
}

int Menu::SelectItem(int max) {
	bool goodInput = false;
	int item = 1;
	
	while (!goodInput) {
		InputCin::InputValueFromConsole<int>(&item);

		if (item > 0 && item <= max) {
			goodInput = true;
		}
		else {
			cout << "Error! Enter numbers from 1 to " << max << endl;
			cin.clear(); 
		}
	}
	return item;
}