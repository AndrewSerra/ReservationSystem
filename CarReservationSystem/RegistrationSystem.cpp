/*
 * RegistrationSystem.cpp
 *
 *  Created on: Nov 13, 2019
 *      Author: andrew
 */

#include <iostream>
#include <fstream>
#include <iomanip>

#include "RegistrationSystem.h"
#include "Passenger.h"
#include "Car.h"

using namespace std;

RegistrationSystem::RegistrationSystem(string f_name) {
	file_name = f_name;
	menu_response = 0;

	ifstream inFile(file_name);

	if(!inFile.is_open()) {
		cout << "Error opening file. Terminating...";
		exit(1);
	}

	int count = 0;

	while(!inFile.eof()) {


		string first, last;
		int credits;

		inFile >> first >> last >> credits;

		string fullName = first + ' ' + last;

//		DEBUGGING LINE
//		cout << fullName << endl;

		rowers[count] = new Passenger(fullName, credits);

		count++;
	}

	inFile.close();
}

Passenger* RegistrationSystem::findRower(string name) {

	Passenger* p = NULL;

	// Find rower in stored array
	for(int i=0; i<(sizeof(rowers)/sizeof(rowers[0]));i++) {
		// If rower is in database
		if(rowers[i]->getName() == name) {
			p = rowers[i];	// Assign the passenger object to the rower with name entered.
			break;
		}
	}

	return p;
}

void RegistrationSystem::displayCarSeatingChoiceMenu(string type) {

	cout << endl << "Choose a seat: " << endl;
	if(type == "PICKUP") {
		cout << setw(4) << "1)" << " Front Seat (5 credits)" << endl;
	}
	else if(type == "COMPACT") {
		cout << setw(4) << "1)" << " Front Seat (5 credits)" << endl;
		cout << setw(4) << "2)" << " Back Seat (3 credits)" << endl;
	}
	else if(type == "SEDAN") {
		cout << setw(4) << "1)" << " Front Seat (5 credits)" << endl;
		cout << setw(4) << "2)" << " Window Back Seat (2 credits)" << endl;
		cout << setw(4) << "3)" << " Middle Back Seat (1 credits)" << endl;
	}
	else {
		cout << "No category called " << type << endl << endl;
	}
}

bool RegistrationSystem::makePickupReservation(Pickup *car, Passenger passenger, int& seat, string carType, string color) {

	bool seatCorrect = false;
	bool reservationMade = false;

	Reservation *res = new(Reservation);

	do {
		// Check if seat is not assigned and set passenger
		if(seat == 1 && car->frontSeat->getPassenger() == NULL) {

			int creditNeeded = car->frontSeat->getCreditNeeded(); // Credit required to reserve

			if(passenger.deductCredits(creditNeeded)) {
				car->frontSeat->setPassenger(passenger);
				reservationMade = true;
				seatCorrect = true;

				for(int i=0; i < 24; i++) {
					if(reservations[i] == NULL) {
						res->passenger = &passenger;
						res->reservationNumber = i;
						res->vehicle = carType;
						res->vehicleColor = color;
						res->seatNumber  = seat;

						reservations[i] = res;
						reservationMade = true;
						break;
					}
				}
			}
			else {
				cout << "Do not have enough credit.";
				reservationMade = false;
				seatCorrect = true;
			}
		}
		else if(seat != 1) {
			seatCorrect = false;
			cout << "Seat is invalid. Enter a new value: ";
			cin >> seat;
		}
		else {
			cout << "Seat already reserved. No other options.";
			reservationMade = false;
			break;
		}
	} while(!seatCorrect);

	return reservationMade;
}

bool RegistrationSystem::makeCompactReservation(Compact *car, Passenger passenger, int& seat, string carType, string color) {

	bool seatCorrect = false;
	bool reservationMade = false;

	Reservation *res = new(Reservation);

	do {
		switch(seat) {
		case 1:

			// Check if seat is not assigned and set passenger
			if(car->frontSeat->getPassenger() == NULL) {

				int creditNeeded = car->frontSeat->getCreditNeeded(); // Credit required to reserve

				if(passenger.deductCredits(creditNeeded)) {
					car->frontSeat->setPassenger(passenger);
					reservationMade = true;
					seatCorrect = true;

					for(int i=0; i < 24; i++) {
						if(reservations[i] == NULL) {
							res->passenger = &passenger;
							res->reservationNumber = i;
							res->vehicle = carType;
							res->vehicleColor = color;
							res->seatNumber  = seat;

							reservations[i] = res;
							reservationMade = true;
							break;
						}
					}
				}
				else {
					cout << "Do not have enough credit.";
					reservationMade = false;
					seatCorrect = true;
				}
			}
			else if(seat != 1) {
				seatCorrect = false;
				cout << "Seat is invalid. Enter a new value: ";
				cin >> seat;
			}
			else {
				cout << "Seat already reserved. No other options.";
				reservationMade = false;
				break;
			}
			break;
		case 2:
			// Check if seat is not assigned and set passenger
			if(car->sideBackLeftSeat->getPassenger() == NULL) {

				int creditNeeded = car->sideBackLeftSeat->getCreditNeeded(); // Credit required to reserve

				if(passenger.deductCredits(creditNeeded)) {
					car->sideBackLeftSeat->setPassenger(passenger);
					reservationMade = true;
					seatCorrect = true;

					for(int i=0; i < 24; i++) {
						if(reservations[i] == NULL) {
							Reservation *res = new(Reservation);
							res->passenger = &passenger;
							res->reservationNumber = i;
							res->vehicle = carType;
							res->vehicleColor = color;
							res->seatNumber  = seat;

							reservations[i] = res;
							reservationMade = true;
							break;
						}
					}
				}
				else {
					cout << "Do not have enough credit.";
					reservationMade = false;
					seatCorrect = true;
				}
			}
			if(car->sideBackRightSeat->getPassenger() == NULL) {

				int creditNeeded = car->sideBackRightSeat->getCreditNeeded(); // Credit required to reserve

				if(passenger.deductCredits(creditNeeded)) {
					car->sideBackRightSeat->setPassenger(passenger);
					reservationMade = true;
					seatCorrect = true;

					for(int i=0; i < 24; i++) {
						if(reservations[i] == NULL) {
							Reservation *res = new(Reservation);
							res->passenger = &passenger;
							res->reservationNumber = i;
							res->vehicle = carType;
							res->vehicleColor = color;
							res->seatNumber  = seat;

							reservations[i] = res;
							reservationMade = true;
							break;
						}
					}
				}
				else {
					cout << "Do not have enough credit.";
					reservationMade = false;
					seatCorrect = true;
				}
			}
			else if(seat != 1) {

			}
			else {
				cout << "Seat already reserved. No other options.";
				reservationMade = false;
				break;
			}
			break;
		default:
			seatCorrect = false;
			cout << "Seat is invalid. Enter a new value: ";
			cin >> seat;
			break;
		}
	} while(!seatCorrect);

	return reservationMade;
}

bool RegistrationSystem::makeSedanReservation(Sedan *car, Passenger passenger, int& seat, string carType, string color) {

	bool seatCorrect = false;
	bool reservationMade = false;

	Reservation *res = new(Reservation);

	do {
		switch(seat) {
		// Front Seat
		case 1:
			// Check if seat is not assigned and set passenger
			if(car->frontSeat->getPassenger() == NULL) {

				int creditNeeded = car->frontSeat->getCreditNeeded(); // Credit required to reserve

				if(passenger.deductCredits(creditNeeded)) {
					car->frontSeat->setPassenger(passenger);
					reservationMade = true;
					seatCorrect = true;

					for(int i=0; i < 24; i++) {
						if(reservations[i] == NULL) {
							res->passenger = &passenger;
							res->reservationNumber = i;
							res->vehicle = carType;
							res->vehicleColor = color;
							res->seatNumber  = seat;

							reservations[i] = res;
							reservationMade = true;
							break;
						}
					}
				}
				else {
					cout << "Do not have enough credit.";
					reservationMade = false;
					seatCorrect = true;
				}
			}
			else {
				cout << "Seat already reserved.";
				reservationMade = false;
				break;
			}
			break;
		case 2:
			// Check if seat is not assigned and set passenger
			if(car->sideBackLeftSeat->getPassenger() == NULL) {

				int creditNeeded = car->sideBackLeftSeat->getCreditNeeded(); // Credit required to reserve

				if(passenger.deductCredits(creditNeeded)) {
					car->sideBackLeftSeat->setPassenger(passenger);
					reservationMade = true;
					seatCorrect = true;

					for(int i=0; i < 24; i++) {
						if(reservations[i] == NULL) {
							res->passenger = &passenger;
							res->reservationNumber = i;
							res->vehicle = carType;
							res->vehicleColor = color;
							res->seatNumber  = seat;

							reservations[i] = res;
							reservationMade = true;
							break;
						}
					}
				}
				else {
					cout << "Do not have enough credit.";
					reservationMade = false;
					seatCorrect = true;
				}
			}
			if(car->sideBackRightSeat->getPassenger() == NULL) {

				int creditNeeded = car->sideBackRightSeat->getCreditNeeded(); // Credit required to reserve

				if(passenger.deductCredits(creditNeeded)) {
					car->sideBackRightSeat->setPassenger(passenger);
					reservationMade = true;
					seatCorrect = true;

					for(int i=0; i < 24; i++) {
						if(reservations[i] == NULL) {
							res->passenger = &passenger;
							res->reservationNumber = i;
							res->vehicle = carType;
							res->vehicleColor = color;
							res->seatNumber  = seat;

							reservations[i] = res;
							reservationMade = true;
							break;
						}
					}
				}
				else {
					cout << "Do not have enough credit.";
					reservationMade = false;
					seatCorrect = true;
				}
			}
			else {
				cout << "Seat already reserved. No other options.";
				reservationMade = false;
				break;
			}
			break;
		case 3:
			// Check if seat is not assigned and set passenger
			if(car->middleBackSeat->getPassenger() == NULL) {

				int creditNeeded = car->middleBackSeat->getCreditNeeded(); // Credit required to reserve

				if(passenger.deductCredits(creditNeeded)) {
					car->middleBackSeat->setPassenger(passenger);
					reservationMade = true;
					seatCorrect = true;

					for(int i=0; i < 24; i++) {
						if(reservations[i] == NULL) {
							res->passenger = &passenger;
							res->reservationNumber = i;
							res->vehicle = carType;
							res->vehicleColor = color;
							res->seatNumber  = seat;

							reservations[i] = res;
							reservationMade = true;
							break;
						}
					}
				}
				else {
					cout << "Do not have enough credit.";
					reservationMade = false;
					seatCorrect = true;
				}
			}
			break;
		default:
			seatCorrect = false;
			cout << "Seat is invalid. Enter a new value: ";
			cin >> seat;
			break;
		}
	} while(!seatCorrect);

	return reservationMade;
}

bool RegistrationSystem::makeReservation(string carType, string color, int seat, Passenger& p) {

	bool reservationMade = false;
	Passenger passenger = p;

	if(carType == "PICKUP") {
		Pickup *car = NULL;

		for(int i=0; i < (sizeof(pickup_cars)/sizeof(pickup_cars[0])); i++) {
			if(pickup_cars[i]->getColor() == color) {
				// Assign the car
				car = pickup_cars[i];
				break;
			}
		}

		if(car == NULL) {
			cout << "Entered car color \"" << color << "\" is not valid.";
			return false;
		}

		reservationMade = makePickupReservation(car, passenger, seat, carType, color) ? true : false;
	}
	else if(carType == "COMPACT") {
		Compact *car = NULL;

		// Find the car searched
		for(int i=0; i < (sizeof(compact_cars)/sizeof(compact_cars[0])); i++) {
			if(compact_cars[i]->getColor() == color) {
				// Assign the car
				car = compact_cars[i];
				break;
			}
		}

		// If the car color is not valid exit function
		if(car == NULL) {
			cout << "Entered car color \"" << color << "\" is not valid.";
			return false;
		}

		reservationMade = makeCompactReservation(car, passenger, seat, carType, color) ? true : false;

	}
	else if(carType == "SEDAN") {
		Sedan *car = NULL;

		for(int i=0; i < (sizeof(sedan_cars)/sizeof(sedan_cars[0])); i++) {
			if(sedan_cars[i]->getColor() == color) {
				// Assign the car
				car = sedan_cars[i];
				break;
			}
		}

		if(car == NULL) {
			cout << "Entered car color \"" << color << "\" is not valid.";
			return false;
		}

		reservationMade = makeSedanReservation(car, passenger, seat, carType, color) ? true : false;
	}
	else {
		cout << "\nCar type \" "<< carType << "\" is invalid.";
		reservationMade = false;
	}

	return reservationMade;
}

void RegistrationSystem::chooseOperation(void) {

	switch(menu_response) {
	case 1: {  // Create Option

		Passenger *passenger = NULL;
		string rowerFirstName, rowerLastName, rowerName;
		string carType, carColor;
		int seatNumber;

		// Request the rower name
		cout << "\n\nEnter name (first last): ";
		cin >> rowerFirstName >> rowerLastName;

		rowerName = rowerFirstName + ' ' + rowerLastName;
		passenger = findRower(rowerName);

		// If the user is found and has credit
		if(passenger != NULL && passenger->getCredit() != 0) {

			cout << "\n\nYou have " << passenger->getCredit() << " credits.";
			displaySeatArrangements();

			cout << "Which car type? ";
			cin >> carType;

			cout << "Which color car? ";
			cin >> carColor;

			// Convert to uppercase
			transform(carType.begin(), carType.end(), carType.begin(), ::toupper);
			transform(carColor.begin(), carColor.end(), carColor.begin(), ::toupper);

			displayCarSeatingChoiceMenu(carType);

			cout << "Which seat would you prefer? (choose number) ";
			cin >> seatNumber;

			if(makeReservation(carType, carColor, seatNumber, *passenger)) {
				cout << "\nSuccessful.\n\n";
			}
			else {
				cout << "\nReservation couldn't be made.\n\n";
			}

		}
		// If the user is found and does not have credit
		else if(passenger != NULL && passenger->getCredit() == 0) {
			cout << "You don't have enough credit. You will need to make your own arrangements.\n";
		}
		// If the user is not found
		else { cout << "Cannot find the name you entered!\n\n"; }

		break;
	}
	case 2: {
		// Display
		displaySeatArrangements();
		break;
	}
	case 3: {
		// Modify
		break;
	}
	case 4: {
		// Delete
		break;
	}
	case 5: {
		// Print
		break;
	}
	case 6: {
		// Reservation
		break;
	}
	case 7: {
		// Save and Quit
		saveToFile();
		exit(1);
	}
	}
}

void RegistrationSystem::displaySeatArrangements(void) {

	int index = 0;

	cout << endl << endl
		 << setw(8) << "Pickup" << setw(9) << "Compact" << setw(11) << "Sedan" << endl
		 << setw(8) << "------" << setw(9) << "-------" << setw(11) << "-----" << endl
		 // COLORS
		 << setw(8) << *(pickup_cars[index]) << setw(8) << *(compact_cars[index]) << setw(11) << *(sedan_cars[index]) << endl
		 // Front seats
		 << setw(5) << "(-)" << *(pickup_cars[index]->frontSeat) << setw(6) <<  "(-)" << *(compact_cars[index]->frontSeat) << setw(7) << "(-)" << setw(4) << *(sedan_cars[index]->frontSeat)
		 // Back seats compact
		 <<  endl << setw(12) << *(compact_cars[index]->sideBackLeftSeat) << *(compact_cars[index]->sideBackRightSeat)
		 // Back seats sedan
		 << setw(5) << *(sedan_cars[index]->sideBackLeftSeat) << *(sedan_cars[index]->middleBackSeat) << *(sedan_cars[index]->sideBackLeftSeat) << endl << endl;
	// Increment the array index
	index++;
		 // COLORS
	cout << setw(8) << *(pickup_cars[index]) << setw(8) << *(compact_cars[index]) << setw(11) << *(sedan_cars[index]) << endl
		 // Front seats
		 << setw(5) << "(-)" << *(pickup_cars[index]->frontSeat) << setw(6) <<  "(-)" << *(compact_cars[index]->frontSeat) << setw(7) << "(-)" << setw(4) << *(sedan_cars[index]->frontSeat)
		 // Back seats compact
		 <<  endl << setw(12) << *(compact_cars[index]->sideBackLeftSeat) << *(compact_cars[index]->sideBackRightSeat)
		 // Back seats sedan
		 << setw(5) << *(sedan_cars[index]->sideBackLeftSeat) << *(sedan_cars[index]->middleBackSeat) << *(sedan_cars[index]->sideBackLeftSeat) << endl << endl;
	// Increment the array index
	index++;
		 // COLORS
	cout << setw(8) << *(pickup_cars[index]) << setw(8) << *(compact_cars[index]) << setw(11) << *(sedan_cars[index]) << endl
		 // Front seats
		 << setw(5) << "(-)" << *(pickup_cars[index]->frontSeat) << setw(6) <<  "(-)" << *(compact_cars[index]->frontSeat) << setw(7) << "(-)" << setw(4) << *(sedan_cars[index]->frontSeat)
		 // Back seats compact
		 <<  endl << setw(12) << *(compact_cars[index]->sideBackLeftSeat) << *(compact_cars[index]->sideBackRightSeat)
		 // Back seats sedan
		 << setw(5) << *(sedan_cars[index]->sideBackLeftSeat) << *(sedan_cars[index]->middleBackSeat) << *(sedan_cars[index]->sideBackLeftSeat) << endl << endl;
}

void RegistrationSystem::saveToFile(void) {

	ofstream outFile(file_name);

	if(!outFile.is_open()) {
		cout << "Error opening file. Terminating...";
		exit(1);
	}

	for(int i=0; i < 24; i++) {
		outFile << rowers[i];
	}

	outFile.close();
}

ostream& operator<<(ostream& menu_out, const RegistrationSystem& sys) {

	cout << "Menu:\n"
		 << setw(5) << "1) " << "Create\n"
		 << setw(5) << "2) " << "Display\n"
		 << setw(5) << "3) " << "Modify\n"
		 << setw(5) << "4) " << "Delete\n"
		 << setw(5) << "5) " << "Print\n"
		 << setw(5) << "6) " << "Reservation\n"
		 << setw(5) << "7) " << "Save and Quit\n";

	return menu_out;
}

istream& operator>>(istream& menu_in, RegistrationSystem& sys) {

	cout << "\nYour choice: ";
	cin >> sys.menu_response;

	return menu_in;
}
