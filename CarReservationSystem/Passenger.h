/*
 * Passenger.h
 *
 *  Created on: Nov 20, 2019
 *      Author: andrew
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Passenger {

private:
	// The name of the passenger as "first last"
	string name;
	// Credits status of the passenger
	int credit;

public:
	// Constructor
	Passenger(string n, int c) {
		name = n;
		credit = c;
	};

	// Returns the credits left of the user
	int getCredit(void) { return credit; }

	// Returns the name of the passenger
	string getName(void) { return name; }

	// When credits are used, it decreases the credit left
	bool deductCredits(int creditDeduct) {
		//
		// Returns true if the credit is enough
		// Returns false if credit is not enough
		//
		if(credit >= creditDeduct) {
			credit -= creditDeduct;

			return true;
		}
		else {
			return false;
		}
	}

	// If a passenger deletes or modifies a
	// reservation, this function allows to correct the credit
	// by returning the credit used
	void addCredits(int creditInc) { credit += creditInc; }

	// Writes the name and credit in the file
	// when save and quit option is chosen in the menu
	friend ofstream& operator<<(ofstream& fileStream, const Passenger& p) {

		fileStream << p.name << " " << p.credit << endl;

		return fileStream;
	}
};

#endif /* PASSENGER_H_ */
