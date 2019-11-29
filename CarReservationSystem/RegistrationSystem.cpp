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

// Constructor
RegistrationSystem::RegistrationSystem(void) {
	file_name = "seat_credits.txt";
	menu_response = 0;

	ifstream inFile(file_name);

	if(!inFile.is_open()) {
		cout << "Error opening file. Terminating...";
		exit(1);
	}

	// Read file to set passengers and their credits in rowers array
	int count = 0;

	while(!inFile.eof() && count < 24) {
		string first, last;
		int credits;

		inFile >> first >> last >> credits;

		string fullName = first + ' ' + last;

		rowers[count] = new Passenger(fullName, credits);

		count++;
	}
	inFile.close();

	// Assign all the cars to the arrays
    pickup_cars[0] = new Pickup("PURPLE");
    pickup_cars[1] = new Pickup("YELLOW");
    pickup_cars[2] = new Pickup("RED");

    compact_cars[0] = new Compact("GREEN");
    compact_cars[1] = new Compact("BLUE");
    compact_cars[2] = new Compact("YELLOW");

    sedan_cars[0] = new Sedan("RED");
    sedan_cars[1] = new Sedan("GREEN");
    sedan_cars[2] = new Sedan("BLUE");
}

///////////////////////////
// Main Functions (Private)
// 1) Create
bool RegistrationSystem::makeReservation(string carType, string color, int seat, Passenger& p) {

    bool reservationMade = false;
    Passenger *passenger = &p;

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

// 2) Display
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

// 3) Modify


// 4) Delete
bool RegistrationSystem::deleteReservation(int reservationNum) {

    // Invalid number return false, operation incomplete
    if(reservationNum < 0 || reservationNum >= 24) {
        cout << "Invalid number. Has to be in range 0-23\n";
        return false;
    }

    if(reservations[reservationNum] == NULL) {
        // No reservation with index reservationNum
        cout << "No reservation saved with number " << reservationNum << " .\n";
        return false;
    }
    else {
        // Free the memory for the stored reservation structure
        delete(reservations[reservationNum]);
        // Assign null to get rid of the reservation
        reservations[reservationNum] = NULL;

        return true;
    }
}

// 5) Print


// 6) Reservation
void RegistrationSystem::saveReservationsToFile(void) {

    ofstream outputFile("all_reservations.txt");

    if(!outputFile.is_open()) {
        cout << "Cannot open file. Terminating...";
        exit(1);
    }

    // Start outputting to the file
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            switch(i) {			// Determine the type of car 0 is Pickup, 1 is Compact, 2 is Sedan
                case 0: {
                    Passenger *passenger = pickup_cars[j]->frontSeat->getPassenger();

                    outputFile << pickup_cars[j]->getColor() << ' '
                               << "PICKUP "
                               << (passenger != NULL ?  passenger->getName() : "UNASSIGNED") << ' '
                               << "FRONT SEAT\n";
                    break;
                }
                case 1: {
                    Passenger *passengerFront = compact_cars[j]->frontSeat->getPassenger();
                    Passenger *passengerBackLeft = compact_cars[j]-> sideBackLeftSeat->getPassenger();
                    Passenger *passengerBackRight = compact_cars[j]->sideBackRightSeat->getPassenger();

                    outputFile << compact_cars[j]->getColor() << ' '
                               << "COMPACT "
                               << (passengerFront != NULL ?  passengerFront->getName() : "UNASSIGNED") << ' '
                               << "FRONT SEAT\n"
                               << compact_cars[j]->getColor() << ' '
                               << "COMPACT "
                               << (passengerBackLeft != NULL ?  passengerBackLeft->getName() : "UNASSIGNED") << ' '
                               << "BACK LEFT SEAT\n"
                               << compact_cars[j]->getColor() << ' '
                               << "COMPACT "
                               << (passengerBackRight != NULL ?  passengerBackRight->getName() : "UNASSIGNED") << ' '
                               << "BACK RIGHT SEAT\n";
                    break;
                }
                case 2: {
                    Passenger *passengerFront = sedan_cars[j]->frontSeat->getPassenger();
                    Passenger *passengerBackLeft = sedan_cars[j]-> sideBackLeftSeat->getPassenger();
                    Passenger *passengerBackRight = sedan_cars[j]->sideBackRightSeat->getPassenger();
                    Passenger *passengerBackMiddle = sedan_cars[j]->middleBackSeat->getPassenger();

                    outputFile << sedan_cars[j]->getColor() << ' '
                               << "SEDAN "
                               << (passengerFront != NULL ?  passengerFront->getName() : "UNASSIGNED") << ' '
                               << "FRONT SEAT\n"
                               << sedan_cars[j]->getColor() << ' '
                               << "SEDAN "
                               << (passengerBackLeft != NULL ?  passengerBackLeft->getName() : "UNASSIGNED") << ' '
                               << "BACK LEFT SEAT\n"
                               << sedan_cars[j]->getColor() << ' '
                               << "SEDAN "
                               << (passengerBackRight != NULL ?  passengerBackRight->getName() : "UNASSIGNED") << ' '
                               << "BACK RIGHT SEAT\n"
                               << sedan_cars[j]->getColor() << ' '
                               << "SEDAN "
                               << (passengerBackMiddle != NULL ?  passengerBackMiddle->getName() : "UNASSIGNED") << ' '
                               << "BACK MIDDLE SEAT\n";
                    break;
                }
            }
        }
    }

    outputFile.close();
}

// 7) Save and Quit
void RegistrationSystem::saveToFile(void) {

    ofstream outFile(file_name);

    if(!outFile.is_open()) {
        cout << "Error opening file. Terminating...";
        exit(1);
    }

    for(int i=0; i < 24; i++) {
        outFile << rowers[i]->getName() << ' ' << rowers[i]->getCredit() << endl;
    }

    outFile.close();
}
///////////////////////////

///////////////////////////
// Main Function helpers
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

bool RegistrationSystem::displayCarSeatingChoiceMenu(string type) {

	cout << endl << "Choose a seat: " << endl;
	if(type == "PICKUP") {
		cout << setw(4) << "1)" << " Front Seat (5 credits)" << endl;
		cout << "Enter 99 to exit...\n\n";
	}
	else if(type == "COMPACT") {
		cout << setw(4) << "1)" << " Front Seat (5 credits)" << endl;
		cout << setw(4) << "2)" << " Back Seat (3 credits)" << endl;
		cout << "Enter 99 to exit...\n\n";
	}
	else if(type == "SEDAN") {
		cout << setw(4) << "1)" << " Front Seat (5 credits)" << endl;
		cout << setw(4) << "2)" << " Window Back Seat (2 credits)" << endl;
		cout << setw(4) << "3)" << " Middle Back Seat (1 credits)" << endl;
		cout << "Enter 99 to exit...\n\n";
	}
	else {
		cout << "No car category called " << type << endl << endl;
		return false;
	}

	return true;
}

// Supports makeReservation()
bool RegistrationSystem::makePickupReservation(Pickup *car, Passenger *passenger, int& seat, string carType, string color) {

	bool seatCorrect = false;
	bool reservationMade = false;

	Reservation *res = new(Reservation);

	do {
		// Check if seat is not assigned and set passenger
		if(seat == 1 && car->frontSeat->getPassenger() == NULL) {

			int creditNeeded = car->frontSeat->getCreditNeeded(); // Credit required to reserve

			if(passenger->deductCredits(creditNeeded)) {
				car->frontSeat->setPassenger(passenger);
				reservationMade = true;
				seatCorrect = true;

				for(int i=0; i < 24; i++) {
					if(reservations[i] == NULL) {
						res->passenger = passenger;
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

			seatCorrect = seat == 99 ? true : false;
			break;
		}
	} while(!seatCorrect);

	return reservationMade;
}

bool RegistrationSystem::makeCompactReservation(Compact *car, Passenger *passenger, int& seat, string carType, string color) {

	bool seatCorrect = false;
	bool reservationMade = false;

	Reservation *res = new(Reservation);

	do {
		switch(seat) {
		case 1:

			// Check if seat is not assigned and set passenger
			if(car->frontSeat->getPassenger() == NULL) {

				int creditNeeded = car->frontSeat->getCreditNeeded(); // Credit required to reserve

				if(passenger->deductCredits(creditNeeded)) {
					car->frontSeat->setPassenger(passenger);
					reservationMade = true;
					seatCorrect = true;

					for(int i=0; i < 24; i++) {
						if(reservations[i] == NULL) {
							res->passenger = passenger;
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
				seatCorrect = false;
			}
			break;
		case 2:
			// Check if seat is not assigned and set passenger
			if(car->sideBackLeftSeat->getPassenger() == NULL) {

				int creditNeeded = car->sideBackLeftSeat->getCreditNeeded(); // Credit required to reserve

				if(passenger->deductCredits(creditNeeded)) {
					car->sideBackLeftSeat->setPassenger(passenger);
					reservationMade = true;
					seatCorrect = true;

					for(int i=0; i < 24; i++) {
						if(reservations[i] == NULL) {
							Reservation *res = new(Reservation);
							res->passenger = passenger;
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
			else if(car->sideBackRightSeat->getPassenger() == NULL) {

				int creditNeeded = car->sideBackRightSeat->getCreditNeeded(); // Credit required to reserve

				if(passenger->deductCredits(creditNeeded)) {
					car->sideBackRightSeat->setPassenger(passenger);
					reservationMade = true;
					seatCorrect = true;

					for(int i=0; i < 24; i++) {
						if(reservations[i] == NULL) {
							Reservation *res = new(Reservation);
							res->passenger = passenger;
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
				seatCorrect = false;
			}
			break;
		default:
			seatCorrect = false;
			cout << "Seat is invalid. Enter a new value: ";
			cin >> seat;

			seatCorrect = seat == 99 ? true : false;
			break;
		}
	} while(!seatCorrect);

	return reservationMade;
}

bool RegistrationSystem::makeSedanReservation(Sedan *car, Passenger *passenger, int& seat, string carType, string color) {

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

				if(passenger->deductCredits(creditNeeded)) {
					car->frontSeat->setPassenger(passenger);
					reservationMade = true;
					seatCorrect = true;

					for(int i=0; i < 24; i++) {
						if(reservations[i] == NULL) {
							res->passenger = passenger;
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
				seatCorrect = false;
			}
			break;
		case 2:
			// Check if seat is not assigned and set passenger
			if(car->sideBackLeftSeat->getPassenger() == NULL) {

				int creditNeeded = car->sideBackLeftSeat->getCreditNeeded(); // Credit required to reserve

				if(passenger->deductCredits(creditNeeded)) {
					car->sideBackLeftSeat->setPassenger(passenger);
					reservationMade = true;
					seatCorrect = true;

					for(int i=0; i < 24; i++) {
						if(reservations[i] == NULL) {
							res->passenger = passenger;
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
			else if(car->sideBackRightSeat->getPassenger() == NULL) {

				int creditNeeded = car->sideBackRightSeat->getCreditNeeded(); // Credit required to reserve

				if(passenger->deductCredits(creditNeeded)) {
					car->sideBackRightSeat->setPassenger(passenger);
					reservationMade = true;
					seatCorrect = true;

					for(int i=0; i < 24; i++) {
						if(reservations[i] == NULL) {
							res->passenger = passenger;
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
				seatCorrect = false;
				break;
			}
			break;
		case 3:
			// Check if seat is not assigned and set passenger
			if(car->middleBackSeat->getPassenger() == NULL) {

				int creditNeeded = car->middleBackSeat->getCreditNeeded(); // Credit required to reserve

				if(passenger->deductCredits(creditNeeded)) {
					car->middleBackSeat->setPassenger(passenger);
					reservationMade = true;
					seatCorrect = true;

					for(int i=0; i < 24; i++) {
						if(reservations[i] == NULL) {
							res->passenger = passenger;
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
				seatCorrect = false;
				break;
			}
			break;
		default:
			seatCorrect = false;
			cout << "Seat is invalid. Enter a new value: ";
			cin >> seat;

			seatCorrect = seat == 99 ? true : false;
			break;
		}
	} while(!seatCorrect);

	return reservationMade;
}
///////////////////////////

// Public Functions
void RegistrationSystem::chooseOperation(void) {

	switch(menu_response) {
	case 1: {
		// Create
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

			// Displays the menu and if car type is valid, returns true
			if(displayCarSeatingChoiceMenu(carType)) {

				cout << "Which seat would you prefer? (choose number) ";
				cin >> seatNumber;

				if(seatNumber != 99) {
					if(makeReservation(carType, carColor, seatNumber, *passenger)) {
						cout << "\nSuccessful.\n\n";
					}
					else {
						cout << "\nReservation couldn't be made.\n\n";
					}
				}
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
		int reservationNumber;

		cout << "Enter a reservation number: ";
		cin >> reservationNumber;

		if(deleteReservation(reservationNumber)) {
			cout << "Successful.\n\n";
		}
		else {
			cout << "Request could not be completed.\n\n";
		}
		break;
	}
	case 5: {
		// Print
		break;
	}
	case 6: {
		// Reservation
		string username, password;

		cout << "Username: ";
		cin >> username;

		cout << "Password: ";
		cin >> password;

		if(username == "admin" && password == "helloworld") {
			saveReservationsToFile();
			cout << "\nSuccessful.\n\n";
		}
		else {
			cout << "\nYou do not have access.\n\n";
		}
		break;
	}
	case 7: {
		// Save and Quit
		saveToFile();
		cout << "\nSaving and quitting program...";
		exit(1);
	}
	default: {
		cout << "\nInvalid number. Enter again.\n\n";
	}
	}
}


// Friend Functions for class RegistrationSystem
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
