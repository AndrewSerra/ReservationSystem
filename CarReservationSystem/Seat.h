/*
 * Seat.h
 *
 *  Created on: Nov 20, 2019
 *      Author: andrew
 */

#ifndef SEAT_H_
#define SEAT_H_

#include "Passenger.h"


class Seat {
private:
	// Credit required to reserve the seat
	int credit;
	// Passenger that reserves the seat
	Passenger* passenger;

public:
	Seat(int c) {
		credit = c;
		passenger = NULL;
	};

	// Function to set the passenger value
	void setPassenger(Passenger *p) {
		passenger = p;
	}

	// Read the passenger by returning the pointer
	Passenger* getPassenger(void) {
		return passenger;
	}

	// Returns the credit required to reserve the seat
	int getCreditNeeded(void) {
		return credit;
	}

	// Returns either the credit required to reserve or
	// and 'X' to show it is already reserved.
	friend ostream& operator<<(ostream& outStream, const Seat& seat) {

		if(seat.passenger == NULL) {
			cout << '(' << seat.credit << ')';
		}
		else {
			cout << "(X)";
		}

		return outStream;
	}
};

#endif /* SEAT_H_ */
