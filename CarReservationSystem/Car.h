/*
 * Car.h
 *
 *  Created on: Nov 20, 2019
 *      Author: andrew
 */

#ifndef CAR_H_
#define CAR_H_

#include <iostream>
#include <string>
#include "Seat.h"

using namespace std;

const int FRONT_SEAT_CREDIT 	   = 5;
const int BACK_SEAT_COMPACT_CREDIT = 3;
const int SIDE_BACK_SEDAN_CREDIT   = 2;
const int MID_BACK_SEDAN_CREDIT    = 1;

class Car {

protected:

	string color;

public:

	Car(string c) {
		color = c;
		// Convert to uppercase
		//transform(color.begin(), color.end(), color.begin(), ::toupper);
	};

	string getColor(void) { return color; }

	friend ostream& operator<<(ostream& outStream, const Car& car) {

		cout << car.color;

		return outStream;
	}
};

class Pickup : public Car {

public:
	Seat *frontSeat;

	Pickup(string c) : Car(c) {
        frontSeat = new Seat(FRONT_SEAT_CREDIT);
	}
};

class Compact : public Car {

public:
	Seat *frontSeat;
	Seat *sideBackLeftSeat;
	Seat *sideBackRightSeat;

	Compact(string c) : Car(c) {
        frontSeat = new Seat(FRONT_SEAT_CREDIT);
        sideBackLeftSeat = new Seat(BACK_SEAT_COMPACT_CREDIT);
        sideBackRightSeat = new Seat(BACK_SEAT_COMPACT_CREDIT);
	}

};

class Sedan : public Car {

public:
	Seat *frontSeat;
	Seat *sideBackLeftSeat;
	Seat *sideBackRightSeat;
	Seat *middleBackSeat;

	Sedan(string c) : Car(c) {
        frontSeat = new Seat(FRONT_SEAT_CREDIT);
        sideBackLeftSeat = new Seat(SIDE_BACK_SEDAN_CREDIT);
        sideBackRightSeat = new Seat(SIDE_BACK_SEDAN_CREDIT);
        middleBackSeat = new Seat(MID_BACK_SEDAN_CREDIT);
	}
};


#endif /* CAR_H_ */
