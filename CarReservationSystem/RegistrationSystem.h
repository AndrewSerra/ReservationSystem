/*
 * RegistrationSystem.h
 *
 *  Created on: Nov 13, 2019
 *      Author: andrew
 */

#ifndef REGISTRATIONSYSTEM_H_
#define REGISTRATIONSYSTEM_H_

#include <iostream>

using namespace std;

class RegistrationSystem {
private:
	string file_name;
	int menu_response;

public:
	// Constructor
	RegistrationSystem(string f_name);

	// Displays the Layouts
	void RegistrationSystem::display(void);


	friend ostream& operator<<(ostream&, const RegistrationSystem&);
	friend istream& operator>>(istream&, RegistrationSystem&);
};


#endif /* REGISTRATIONSYSTEM_H_ */
