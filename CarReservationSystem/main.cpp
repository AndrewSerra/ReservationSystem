

#include <iostream>
#include "RegistrationSystem.h"

using namespace std;


int main(void) {

	RegistrationSystem sys = RegistrationSystem();

	int userChoice;

	while(true) {
		// Display the menu
		cout << sys;
		// Get user input
		cin >> sys;

		sys.chooseOperation();
	}

	return 0;
}
