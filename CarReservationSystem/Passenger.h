/*
 * Passenger.h
 *
 *  Created on: Nov 20, 2019
 *      Author: andrew
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <iostream>
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

	int getCredits(void) { return credit; }

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

	friend ostream& operator<<(ostream& menu_out, const Passenger& p) {

		cout << "Name: " << setw(20) << p.name
			 << " Credit: " << setw(5) << p.credit;

		return menu_out;
	}

//	void save();
//	void read();
};

#endif /* PASSENGER_H_ */
