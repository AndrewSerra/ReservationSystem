/*
 * RegistrationSystem.h
 *
 *  Created on: Nov 13, 2019
 *      Author: andrew
 */

#ifndef REGISTRATIONSYSTEM_H_
#define REGISTRATIONSYSTEM_H_

#include <iostream>
#include "Passenger.h"
#include "Car.h"

using namespace std;

struct Reservation {
	Passenger *passenger;
	int reservationNumber;
	string vehicle;
	string vehicleColor;
	int seatNumber;
};

class RegistrationSystem {

private:

	string file_name;
	int menu_response;

	// Saved reservations array
	Reservation *reservations[24] = { NULL };

	// All the passengers from the text file
	Passenger *rowers[24];

	// The cars stored in separate arrays by type
	Pickup *pickup_cars[3] = { NULL };
	Compact *compact_cars[3] = { NULL };
	Sedan *sedan_cars[3] = { NULL };

	// Displays the Layouts
	void displaySeatArrangements(void);

	// Modify reservation
    void modifyReservation(int);

	// Saves the information in the file
	void saveToFile(void);

	// Find the rower in array rowers
	Passenger* findRower(string);

	// Displays the menu for the seat choice of a car type
	bool displayCarSeatingChoiceMenu(string);

	// Make a reservation in the system
	bool makeReservation(string, string, int, Passenger&);

	// Delete a reservation
	bool deleteReservation(int);

	// Writes reservation data of a car to a text file
    void printCarAssignments(string, string);

	// Print Reservations
	void saveReservationsToFile(void);

	// Sub functions for makeReservation()
	bool makePickupReservation(Pickup*, Passenger*, int&, string, string);
	bool makeCompactReservation(Compact*, Passenger*, int&, string, string);
	bool makeSedanReservation(Sedan*, Passenger*, int&, string, string);

public:

	// Constructor
	RegistrationSystem(void);

	void chooseOperation(void);

	friend ostream& operator<<(ostream&, const RegistrationSystem&);
	friend istream& operator>>(istream&, RegistrationSystem&);
};


#endif /* REGISTRATIONSYSTEM_H_ */
