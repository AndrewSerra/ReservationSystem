/*
 * Seat.h
 *
 *  Created on: Nov 20, 2019
 *      Author: andrew
 */

#ifndef SEAT_H_
#define SEAT_H_

#include "Passenger.h"

//class Seat {
//private:
//	int credit;
//	bool front;
//	bool backM;
//	bool backSL;
//	bool backSR;
//
//public:
//	int amount();
//	bool seatOpen();
//};


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
};

#endif /* SEAT_H_ */
