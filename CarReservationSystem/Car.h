/*
 * Car.h
 *
 *  Created on: Nov 20, 2019
 *      Author: andrew
 */

#ifndef CAR_H_
#define CAR_H_

#include <iostream>
#include "Seat.h"

using namespace std;

const int FRONT_SEAT_CREDIT 	   = 5;
const int BACK_SEAT_COMPACT_CREDIT = 3;
const int SIDE_BACK_SEDAN_CREDIT   = 2;
const int MID_BACK_SEDAN_CREDIT    = 1;

class Car {

protected:

	string type;
	string color;

	//string front;

public:

//	Car(string t, string c, string f) {
//		type = t;
//		color = c;
//		front = f;
//	};
	Car(string t, string c) {
		type = t;
		color = c;
	};

	int max();
	int seatCredit();
};

class Pickup : public Car {

	Seat *frontSeat = new Seat(FRONT_SEAT_CREDIT);

public:
	Pickup(string t, string c) : Car(t, c) {};
};

class Compact : public Car {
private:
//	string backL;
//	string backR;

	Seat *frontSeat = new Seat(FRONT_SEAT_CREDIT);
	Seat *sideBackLeftSeat = new Seat(BACK_SEAT_COMPACT_CREDIT);
	Seat *sideBackRightSeat = new Seat(BACK_SEAT_COMPACT_CREDIT);

public:
//	Compact(string bL, string bR) {
//		backL = bL;
//		backR = bR;
//	}
	Compact(string t, string c) : Car(t, c) {}
};

class Sedan : public Car {
private:
//	string backL;
//	string backR;
//	string middle;

	Seat *frontSeat = new Seat(FRONT_SEAT_CREDIT);
	Seat *sideBackLeftSeat = new Seat(SIDE_BACK_SEDAN_CREDIT);
	Seat *sideBackRightSeat = new Seat(SIDE_BACK_SEDAN_CREDIT);
	Seat *middleBackSeat = new Seat(MID_BACK_SEDAN_CREDIT);

public:
//	Sedan(string bL, string bR, string m) {
//		backL = bL;
//		backR = bR;
//		middle = m;
//	}

	Sedan(string t, string c) : Car(t, c) {}
};


#endif /* CAR_H_ */
