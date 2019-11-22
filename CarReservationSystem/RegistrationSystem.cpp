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

	ifstream inFile(file_name);

	if(!inFile.is_open()) {
		cout << "Error opening file. Terminating...";
		exit(1);
	}

	int count = 0;

	while(!inFile.eof()) {


		string first, last;
		int credits;

		inFile >> first >> last >> credits;

		string fullName = first + ' ' + last;

		setPassengerToArray(count, new Passenger(fullName, credits));

		count++;
	}
}

void RegistrationSystem::chooseOperation(void) {

	switch(menu_response) {
	case 1:
		// Create
		break;
	case 2:
		// Display
		break;
	case 3:
		// Modify
		break;
	case 4:
		// Delete
		break;
	case 5:
		// Print
		break;
	case 6:
		// Reservation
		break;
	case 7:
		// Save and Quit


		exit(1);
	}
}

void RegistrationSystem::display(void) {

}

void RegistrationSystem::saveToFile(void) {

	// INCOMPLETE

	ifstream inFile(file_name);

	if(!inFile.is_open()) {
		cout << "Error opening file. Terminating...";
		exit(1);
	}


}

ostream& operator<<(ostream& menu_out, const RegistrationSystem& sys) {

	cout << "Menu:\n"
		 << setw(5) << "1) " << "Create\n"
		 << setw(5) << "2) " << "Display\n"
		 << setw(5) << "3) " << "Modify\n"
		 << setw(5) << "4) " << "Delete\n"
		 << setw(5) << "5) " << "Print\n"
		 << setw(5) << "6) " << "Reservation\n"
		 << setw(5) << "7) " << "Save and Quit\n";

	return menu_out;
}

istream& operator>>(istream& menu_in, RegistrationSystem& sys) {

	cout << "\nYour choice: ";
	cin >> sys.menu_response;

	return menu_in;
}
