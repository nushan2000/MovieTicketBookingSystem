#include <iostream>
#include <vector>
#include "Theater.h"


using namespace std;

int movieNo, timeNo, tickets, total;
vector<int> selectedSeats;
string movie, timeSlot, CustomerName, CustomerCN;

void TakeCustomerDetails(Theater theater) {
	cout << "\n\tEnter your name\t\t\t : ";
	cin >> CustomerName;
	cin;
	cout << "\tEnter your contact number\t : ";
	cin >> CustomerCN;
	cout << endl;
}

void DisplayTicket(Theater theater) {
	switch (movieNo)
	{
	case 1:
		movie = "Spider man";
		break;

	case 2:
		movie = "Super man";
		break;

	case 3:
		movie = "Iron man";
		break;

	case 4:
		movie = "Doctor strange";
		break;

	case 5:
		movie = "Venom";
		break;

	case 6:
		movie = "Avatar";
		break;

	default:
		movie = "No movie Selected";
		break;
	}

	switch (timeNo)
	{
	case 1:
		timeSlot = "10.00AM";
		break;

	case 2:
		timeSlot = "04.00PM";
		break;

	default:
		timeSlot = "No Time Slot Selected";
		break;
	}

	cout << endl;
	cout << "\n\t----------------Tickets---------------" << endl;
	cout << "\tName \t\t\t : " << CustomerName << endl;
	cout << "\tContact Number \t\t : " << CustomerCN << endl;
	cout << "\tMovie \t\t\t : " << movie << endl;
	cout << "\tTime \t\t\t : " << timeSlot << endl;
	cout << "\tSeats \t\t\t : ";
	for (int i = 0; i < selectedSeats.size(); i++) {
		cout << selectedSeats[i] << " ";
	}
	cout << "\n\tTotal \t\t\t : " << total << endl;
	cout << "\t---------------------------------------" << endl;
}

void takeDetails(Theater theater) {
	cout << "\nChoose the movie : " << endl;
	cin >> movieNo;

	cout << "\nChoose the time : " << endl;
	cout << "1.10.00Am\n2.04.00PM" << endl;
	cin >> timeNo;

	cout << endl;
	cout << "Ticket price : Rs.450.00" << endl;
	cout << "How many tickets do you want ? " << endl;
	cin >> tickets;

	total = tickets * 450;
	cout << endl;
	theater.DisplaySeats();
	cout << "\n\nSelect your seats : ";

	int temp;
	for (int i = 0; i < tickets; i++) {
		cin >> temp;

		if (temp > 88 || temp < 11) {
			cout << "Invalid seat number !" << endl;
			return;
			break;
		}
		else {
			int x = temp / 10;
			int y = temp % 10;
			if (theater.isBooked[x - 1][y - 1] == true) {
				cout << "seat is already booked." << endl;
				return;
				break;
			}
			else {
				selectedSeats.push_back(temp);
				theater.isBooked[x - 1][y - 1] = true;
			}
		}
	}
	cout << endl;
	DisplayTicket(theater);
}


int main()
{
	Theater theater;

	TakeCustomerDetails(theater);
	theater.DisplayMovies();
	takeDetails(theater);
}