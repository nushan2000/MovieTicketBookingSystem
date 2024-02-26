#pragma once
#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

class Theater
{
public:
	Theater() {

	}

	SinglyLinkedList<string> movies;

	int seats[8][8];
	bool isBooked[8][8];

	void DisplaySeats() {
		isBooked[4][5] = true;
		isBooked[4][6] = true;
		isBooked[6][5] = true;
		isBooked[0][1] = true;
		isBooked[0][2] = true;
		cout << "\n\t\t\tBooked seats marked as [\"XX\"] \n" << endl;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cout << "\t";
				if (isBooked[i][j] == false) {
					cout << "[ " << (i + 1) << (j + 1) << " ] ";
				}
				else {
					cout << "[ XX ] ";
				}
			}
			cout << endl;
		}
	}

	void DisplayMovies() {
		movies.insert("1.Spider man \n\t10.00AM 4.00PM");
		movies.insert("2.Super man \n\t10.00AM 4.00PM");
		movies.insert("3.Iron man \n\t10.00AM 4.00PM");
		movies.insert("4.Doctor strange \n\t10.00AM 4.00PM");
		movies.insert("5.Venom \n\t10.00AM 4.00PM");
		movies.insert("6.Avatar \n\t10.00AM 4.00PM");

		movies.printList();
	}
};