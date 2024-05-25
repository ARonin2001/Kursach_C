#include "InputCin.h"
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void InputCin::InputValueFromConsole(T* value) {
	bool isValidInput = false;
	while (!isValidInput) {
		cin >> *value;

		if (cin)
			isValidInput = true;
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	cout << endl;

	//if (!cin) {
	//	cin.clear();
	//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//	cin >> *value;
	//}
}