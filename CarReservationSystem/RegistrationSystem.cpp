/*
 * RegistrationSystem.cpp
 *
 *  Created on: Nov 13, 2019
 *      Author: andrew
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "RegistrationSystem.h"

using namespace std;

RegistrationSystem::RegistrationSystem(string f_name) {
	file_name = f_name;
	menu_response = 0;
}

void RegistrationSystem::display(void) {

}

ostream& operator<<(ostream& menu_out, const RegistrationSystem& sys) {

	cout << "Menu:\n"
		 << setw(5) << "1) " << "Create\n"
		 << setw(5) << "2) " << "Display\n"
		 << setw(5) << "3) " << "Modify\n"
		 << setw(5) << "4) " << "Delete\n"
		 << setw(5) << "5) " << "Print\n"
		 << setw(5) << "6) " << "Reservation\n";

	return menu_out;
}

istream& operator>>(istream& menu_in, RegistrationSystem& sys) {

	cout << "\nYour choice: ";
	cin >> sys.menu_response;

	return menu_in;
}
