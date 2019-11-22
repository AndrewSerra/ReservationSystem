/*
 * RegistrationSystem.h
 *
 *  Created on: Nov 13, 2019
 *      Author: andrew
 */

#ifndef REGISTRATIONSYSTEM_H_
#define REGISTRATIONSYSTEM_H_

#include <iostream>
#include "Passenger.h"

using namespace std;

class RegistrationSystem {

private:

	string file_name;
	int menu_response;

	Passenger *rowers[24];

	// Displays the Layouts
	void display(void);

	// Saves the information in the file
	void saveToFile(void);

	// Used in constructor
	void setPassengerToArray(int index, Passenger* p) { rowers[index] = p; };


public:

	// Constructor
	RegistrationSystem(string f_name);

	void chooseOperation(void);


	friend ostream& operator<<(ostream&, const RegistrationSystem&);
	friend istream& operator>>(istream&, RegistrationSystem&);
};


#endif /* REGISTRATIONSYSTEM_H_ */
