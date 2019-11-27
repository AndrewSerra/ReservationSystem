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
	int credit;
	Passenger* passenger;

public:
	Seat(int c) {
		credit = c;
		passenger = NULL;
	};

	void setPassenger(Passenger p) {
		passenger = &p;
	}

	Passenger* getPassenger(void) {
		return passenger;
	}

	int getCreditNeeded(void) {
		return credit;
	}

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
