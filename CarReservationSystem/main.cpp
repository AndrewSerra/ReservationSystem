

#include <iostream>
#include "RegistrationSystem.h"

using namespace std;


int main(void) {

	RegistrationSystem sys = RegistrationSystem();

	while(true) {
		// Display the menu
		cout << sys;
		// Get user input for menu
		cin >> sys;

		// Complete operation in RegistrationSystem
		sys.chooseOperation();
	}

	return 0;
}
