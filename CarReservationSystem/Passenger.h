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
	string name;
	int credit;

public:

	Passenger(string n, int c) {
		name = n;
		credit = c;
	};

	int getCredit(void) { return credit; }

	string getName(void) { return name; }

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
	void addCredits(int creditInc) { credit += creditInc; }

	friend ofstream& operator<<(ofstream& fileStream, const Passenger& p) {

		fileStream << p.name << " " << p.credit << endl;

		return fileStream;
	}
};

#endif /* PASSENGER_H_ */
