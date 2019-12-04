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
	// Only property that is common to all cars
	string color;

public:
	// Constructor
	Car(string c) {
		color = c;
	};

	// Returns the color of the car
	string getColor(void) { return color; }

	// Outputs the car color
	friend ostream& operator<<(ostream& outStream, const Car& car) {

		cout << car.color;

		return outStream;
	}
};

class Pickup : public Car {

public:
	// Front Seat Object pointer
	Seat *frontSeat;

	// Constructor
	Pickup(string c) : Car(c) {
        frontSeat = new Seat(FRONT_SEAT_CREDIT);
	}

	// Used to write a file when print function called
    friend ofstream& operator<<(ofstream& outFile, Pickup& pickup) {

        Passenger *frontSeatPassenger = pickup.frontSeat->getPassenger();

        outFile << pickup.getColor() << " PICKUP" << endl
                  << "Front Seat: " << (frontSeatPassenger != NULL ? frontSeatPassenger->getName() : "UNASSIGNED") << endl;

        return outFile;
    }
};

class Compact : public Car {

public:
	// Seat Object pointers
	Seat *frontSeat;
	Seat *sideBackLeftSeat;
	Seat *sideBackRightSeat;

	// Constructor
	Compact(string c) : Car(c) {
        frontSeat = new Seat(FRONT_SEAT_CREDIT);
        sideBackLeftSeat = new Seat(BACK_SEAT_COMPACT_CREDIT);
        sideBackRightSeat = new Seat(BACK_SEAT_COMPACT_CREDIT);
	}

	// Used to write a file when print function called
    friend ofstream& operator<<(ofstream& outFile, Compact& compact) {

        Passenger *frontSeatPassenger = compact.frontSeat->getPassenger();
        Passenger *backLeftSeatPassenger = compact.sideBackLeftSeat->getPassenger();
        Passenger *backRightSeatPassenger = compact.sideBackRightSeat->getPassenger();

        outFile << compact.getColor() << " COMPACT" << endl
                << "Front Seat: " << (frontSeatPassenger != NULL ? frontSeatPassenger->getName() : "UNASSIGNED") << endl
                << "Back Left Seat: " << (backLeftSeatPassenger != NULL ? backLeftSeatPassenger->getName() : "UNASSIGNED") << endl
                << "Back Right Seat: " << (backRightSeatPassenger != NULL ? backRightSeatPassenger->getName() : "UNASSIGNED") << endl;
        return outFile;
    }
};

class Sedan : public Car {

public:
	// Seat Object pointers
	Seat *frontSeat;
	Seat *sideBackLeftSeat;
	Seat *sideBackRightSeat;
	Seat *middleBackSeat;

	// Constructor
	Sedan(string c) : Car(c) {
        frontSeat = new Seat(FRONT_SEAT_CREDIT);
        sideBackLeftSeat = new Seat(SIDE_BACK_SEDAN_CREDIT);
        sideBackRightSeat = new Seat(SIDE_BACK_SEDAN_CREDIT);
        middleBackSeat = new Seat(MID_BACK_SEDAN_CREDIT);
	}

	// Used to write a file when print function called
    friend ofstream& operator<<(ofstream& outFile, Sedan& sedan) {

        Passenger *frontSeatPassenger = sedan.frontSeat->getPassenger();
        Passenger *backLeftSeatPassenger = sedan.sideBackLeftSeat->getPassenger();
        Passenger *backRightSeatPassenger = sedan.sideBackRightSeat->getPassenger();
        Passenger *backMidSeatPassenger = sedan.middleBackSeat->getPassenger();

        outFile << sedan.getColor() << " SEDAN" << endl
                << "Front Seat: " << (frontSeatPassenger != NULL ? frontSeatPassenger->getName() : "UNASSIGNED") << endl
                << "Back Left Seat: " << (backLeftSeatPassenger != NULL ? backLeftSeatPassenger->getName() : "UNASSIGNED") << endl
                << "Back Right Seat: " << (backRightSeatPassenger != NULL ? backRightSeatPassenger->getName() : "UNASSIGNED") << endl
                << "Back Middle Seat: " << (backMidSeatPassenger != NULL ? backMidSeatPassenger->getName() : "UNASSIGNED") << endl;

        return outFile;
    }
};


#endif /* CAR_H_ */
