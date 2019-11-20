

#include <iostream>
#include "RegistrationSystem.h"

using namespace std;

int main(void) {

	RegistrationSystem sys = RegistrationSystem("seat_credits.txt");

	int userChoice;
	bool isChoiceValid = false;

	do {
		// Reset variable
		userChoice = 0;
		// Display the menu
		cout << sys;

		// Decide if the choice is valid
		if(userChoice <= 6 || userChoice >= 1) {
			cin >> sys;
			isChoiceValid = true;
		}
		else {
			cout << "Value entered is not valid.\n\n";
			isChoiceValid = false;
		}
	} while(!isChoiceValid);

	return 0;
}
