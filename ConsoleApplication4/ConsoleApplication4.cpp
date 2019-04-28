// Project 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<ctime>

using namespace std;

struct flightschdule
{
	int specialID;
	char flightNo[20];
	char Flightcode[20];
	char planeID[20];
	char fromCountry[20];
	char toCounty[20];
	char Dtime[20];
	char Atime[20];
	char flightday[20];
	char duration_hours[20];
	char freq_weekly[20];
}flights;

struct passergersinfo
{
	char UniqeID[20];
	char first_name[20];
	char middle_name[20];
	char last_name[20];
	char date_of_birth[20];
	char profession[20];
	char nationality[20];
	char passportNo[20];
	char passport_expiration_date[20];
}passengers;

struct bookinginfo
{
	char fromdestination[20];
	char todestination[20];
	char day[20];
	char D[5];
	char M[5];
	char Y[5];
	char passengerID[20];
	char flightID[20];
	char seatrow;
	char seatnum[2];
	char seatclass[20];

} booking;

// Global Variables
string PASSENGERid;
char FLIGHTid[20];
char passengerUniqeID[20];
const int busrow = 5;
const int busseats = 4;
char Busletters[] = { 'F','D',' ','C','A' };
const int ecorow = 7;
const int ecoseats = 25;
char Ecoletters[] = { 'F','E','D',' ','C','B','A' };
char modified_seat[20];
int EcoNo[25];
char BusSeats[busrow][busseats];
char EcoSeats[ecorow][ecoseats];
char flightID_ticket[20];

void the_menu();
void admin_menu();
void customer_menu();
void passenger_module();
void the_seats();
void cheacking_Plane();
void print_ticket();
void print_ticket_choice();

//task 1
void add_data()
{
	char choose = ' ';
	ofstream flight1("flights.dat", ios::binary | ios::app);

	cout << "enter the following .." << endl;
	cout << "Trip ID: ";
	cin >> flights.specialID;
	cout << "flight number: ";
	cin >> flights.flightNo;
	cout << "Flight code: ";
	cin >> flights.Flightcode;
	cout << "plan ID: ";
	cin >> flights.planeID;
	cout << "the (from) destination: ";
	cin >> flights.fromCountry;
	cout << "the (to) destination: ";
	cin >> flights.toCounty;
	cout << "Duration (hours: min): ";
	cin >> flights.duration_hours;
	cout << "Departure time: ";
	cin >> flights.Dtime;
	cout << "Arrival time: ";
	cin >> flights.Atime;
	cout << "flight day: ";
	cin >> flights.flightday;
	cout << "frquency (weekly): ";
	cin >> flights.freq_weekly;

	cout << endl;

	flight1.write((char*)&flights, sizeof(flights));
	flight1.close();

	cout << "Do you want to return to the main menu? (y/n)" << endl;
	cout << "enter your choice: ";
	cin >> choose;

	switch (choose)
	{
	case 'y':
	case'Y':
		the_menu();
		break;
	case 'n':
	case 'N':
		break;
	default:
		cout << "  ERROR!!  " << endl;
		cout << "please enter a valid choice" << endl;
		cout << endl << endl;
		the_menu();
		break;
	}
}
//task 1
void display_data()
{
	ifstream flight2("flights.dat", ios::binary);

	cout << "Trip ID  " << setw(4) << "  Flight Number  " << setw(4) << "  Flight Code  " << setw(4) << "  Plan ID  " << "    " << "  From  " << "     " << "  to  " << setw(4) << "  Duration(hours)  " << setw(4) << "  Departure time  " << setw(4) << "  Arrival time  " << setw(4) << "  Flight Day  " << setw(4) << "  Frecquency weekly" << endl << endl;

	flight2.read((char*)&flights, sizeof(flights));
	while (!flight2.eof())
	{
		cout << "  " << flights.specialID << " " << setw(5) << " " << flights.Flightcode << " " << setw(5) << "         " << flights.flightNo << " " << setw(5) << " " <<
			flights.planeID << "    " << flights.fromCountry << " " << setw(5) << " " << flights.toCounty << " " << setw(5) << " " <<
			flights.duration_hours << " " << setw(5) << " " << flights.Dtime << "           " << flights.Atime << "          " <<
			flights.flightday << "      " << flights.freq_weekly << endl;

		flight2.read((char*)&flights, sizeof(flights));
	}

	flight2.close();
}
//task 1
void display_data_customer()
{
	ifstream flight8("flights.dat", ios::binary);

	cout << "  Flight Number  " << setw(5) << "  Plan ID  " << setw(5) << "  From  " << setw(5) << "  to  " << setw(5) << "  Duration(hours)  " << setw(5) << "  Departure time  " << setw(5) << "  Arrival time  " << setw(5) << "  Flight Day  " << setw(5) << "  Frecquency weekly" << endl << endl;

	flight8.read((char*)&flights, sizeof(flights));
	while (!flight8.eof())
	{
		cout << flights.flightNo << " " << setw(5) << " " << flights.planeID << " " << setw(5) << " " <<
			flights.fromCountry << " " << setw(5) << " " << flights.toCounty << " " << setw(5) << " " <<
			flights.duration_hours << " " << setw(5) << " " << flights.Dtime << " " << setw(5) << " " <<
			flights.Atime << " " << setw(5) << " " << flights.flightday << " " << setw(5) << " " << flights.freq_weekly << endl;

		flight8.read((char*)&flights, sizeof(flights));
	}

	flight8.close();
}
//task 1
void delete_data()
{
	system("cls");
	display_data();

	int deletetrip;
	char choose = ' ';
	char choice = ' ';
	cout << "enter the Trip ID which you want to delete" << endl;
	cout << "Trip ID: ";
	cin >> deletetrip;

	ofstream flight5("newflights.dat", ios::binary | ios::app);
	ifstream flight6("flights.dat", ios::binary);

	flight6.read((char*)&flights, sizeof(flights));
	while (!flight6.eof())
	{
		if (deletetrip != flights.specialID)
		{

			flight5.write((char*)&flights, sizeof(flights));
		}
		flight6.read((char*)&flights, sizeof(flights));
	}
	flight5.close();
	flight6.close();
	remove("flights.dat");
	rename("newflights.dat", "flights.dat");

	system("cls");
	cout << "Data after deleting from it" << endl;
	display_data();

	cout << "Do you want to delete another flight or try again? (y/n)" << endl;
	cout << "your choice: ";
	cin >> choose;
	switch (choose)
	{
	case 'y':
	case 'Y':
		system("cls");
		delete_data();
	case 'n':
	case 'N':
		system("cls");
		cout << "Do you want to return to the Admin menu? (y/n)" << endl;
		cout << "your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 'y':
		case 'Y':
			system("cls");
			admin_menu();
		case 'n':
		case 'N':
			system("cls");
			break;
		default:
			cout << "  ERROR!!  " << endl;
			cout << "please enter a valid number" << endl;
			cout << endl << endl;
			admin_menu();
			break;
		}
		break;
	default:
		cout << "  ERROR!!  " << endl;
		cout << "please enter a valid number" << endl;
		cout << endl << endl;
		admin_menu();
		break;
	}
}
//task 1
void modify_data()
{
	system("cls");
	display_data();

	int modifyID;
	char choose = ' ';
	char choice = ' ';
	cout << "enter the trip ID you want to modify" << endl;
	cout << "Trip ID: ";
	cin >> modifyID;

	ofstream flight3("thenewflights.dat", ios::binary | ios::app);
	ifstream flight4("flights.dat", ios::binary);

	flight4.read((char*)&flights, sizeof(flights));
	while (!flight4.eof())
	{
		if (modifyID != flights.specialID)
		{

			flight3.write((char*)&flights, sizeof(flights));
		}

		if (modifyID == flights.specialID)
		{
			int thechoice;
			cout << "Please enter the data after modification" << endl << endl;
			cout << "to change flight code press (1)" << endl;
			cout << "to change flight number press (2)" << endl;
			cout << "to change plan ID press (3)" << endl;
			cout << "to change from destination press (4)" << endl;
			cout << "to change to destination press (5)" << endl;
			cout << "to change Duration press (6)" << endl;
			cout << "to change Departure time press (7)" << endl;
			cout << "to change Arrival time press (8)" << endl;
			cout << "to change flight day press (9)" << endl;
			cout << "to change frequency(weekly) press (10)" << endl;
			cout << "to change ALL press (11)" << endl;
			cin >> thechoice;
			switch (thechoice)
			{
			case 1:
				cout << "Flight code: ";
				cin >> flights.Flightcode;
				break;
			case 2:
				cout << "flight number: ";
				cin >> flights.flightNo;
				break;
			case 3:
				cout << "plan ID: ";
				cin >> flights.planeID;
				break;
			case 4:
				cout << "the (from) destination: ";
				cin >> flights.fromCountry;
				break;
			case 5:
				cout << "the (to) destination: ";
				cin >> flights.toCounty;
				break;
			case 6:
				cout << "Duration (hours: min): ";
				cin >> flights.duration_hours;
				break;
			case 7:
				cout << "Departure time: ";
				cin >> flights.Dtime;
				break;
			case 8:
				cout << "Arrival time: ";
				cin >> flights.Atime;
				break;
			case 9:
				cout << "flight day: ";
				cin >> flights.flightday;
				break;
			case 10:
				cout << "frquency (weekly): ";
				cin >> flights.freq_weekly;
				break;
			case 11:
				cout << "Trip ID: ";
				cin >> flights.specialID;
				cout << "flight number: ";
				cin >> flights.flightNo;
				cout << "Flight code: ";
				cin >> flights.Flightcode;
				cout << "plan ID: ";
				cin >> flights.planeID;
				cout << "the (from) destination: ";
				cin >> flights.fromCountry;
				cout << "the (to) destination: ";
				cin >> flights.toCounty;
				cout << "Duration (hours: min): ";
				cin >> flights.duration_hours;
				cout << "Departure time: ";
				cin >> flights.Dtime;
				cout << "Arrival time: ";
				cin >> flights.Atime;
				cout << "flight day: ";
				cin >> flights.flightday;
				cout << "frquency (weekly): ";
				cin >> flights.freq_weekly;
			default:
				cout << "  ERROR!!  " << endl;
				cout << "please enter a valid choice" << endl;
				cout << endl << endl;
				break;
			}

			cout << endl;

			flight3.write((char*)&flights, sizeof(flights));
		}
		flight4.read((char*)&flights, sizeof(flights));
	}
	flight3.close();
	flight4.close();
	remove("flights.dat");
	rename("thenewflights.dat", "flights.dat");

	system("cls");
	cout << "Your data was modified" << endl;
	cout << "Do you want to modify another flight? (y/n)" << endl;
	cout << "your choice: ";
	cin >> choose;
	switch (choose)
	{
	case 'y':
	case 'Y':
		system("cls");
		modify_data();
	case 'n':
	case 'N':
		system("cls");
		cout << "Do you want to return to the Admin menu? (y/n)" << endl;
		cout << "your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 'y':
		case 'Y':
			system("cls");
			admin_menu();
		case 'n':
		case 'N':
			system("cls");
			break;
		default:
			cout << "  ERROR!!  " << endl;
			cout << "please enter a valid choice" << endl;
			cout << endl << endl;
			admin_menu();
			break;
		}
		break;
	default:
		cout << "  ERROR!!  " << endl;
		cout << "please enter a valid choice" << endl;
		cout << endl << endl;
		admin_menu();
		break;
	}

}

void switchadminfunction()
{
	char choice = ' ';
	cout << endl << endl << "Do you want to return to the admin menu? (y/n)" << endl;
	cout << "your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 'y':
	case 'Y':
		system("cls");
		admin_menu();
	case 'n':
	case 'N':
		system("cls");
		break;
	default:
		system("cls");
		cout << "  ERROR!! (invalid input)  " << endl;
		exit(0);
		break;
	}
}
//task 1
void admin_menu()
{
	system("cls");
	char choice = ' ';

	cout << "------------------------------------------------" << endl;
	cout << "|         dis(P)lay the flight schdule         |" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "|              (A)dd a new flight              |" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "|              (D)elete a flight               |" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "|              (M)odify a flight               |" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "|                    (B)ACK                    |" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "|                    (E)XIT                    |" << endl;
	cout << "------------------------------------------------" << endl;

	cout << endl << "enter the letter of your choice" << endl;
	cout << "Your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 'p':
	case 'P':
		system("cls");
		display_data();
		switchadminfunction();
		break;
	case 'a':
	case 'A':
		system("cls");
		add_data();
		switchadminfunction();
		break;
	case 'd':
	case 'D':
		system("cls");
		delete_data();
		switchadminfunction();
		break;
	case 'm':
	case 'M':
		system("cls");
		modify_data();
		switchadminfunction();
		break;
	case 'b':
	case 'B':
		system("cls");
		the_menu();
		break;
	case 'e':
	case 'E':
		cout << "thank you for visiting our airline" << endl;
		exit(0);
		break;
	default:
		cout << "  ERROR!!  " << endl;
		cout << "please enter a valid choice" << endl;
		cout << endl << endl;
		admin_menu();
		break;
	}

}

void switchcustomerfunction()
{
	char choice = ' ';
	cout << endl << endl << "Do you want to return to the customer menu? (y/n)" << endl;
	cout << "your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 'y':
	case 'Y':
		system("cls");
		customer_menu();
	case 'n':
	case 'N':
		system("cls");
		break;
	default:
		system("cls");
		cout << "  ERROR!! (invalid input)  " << endl;
		exit(0);
		break;
	}
}
//task 2
void add_passenger()
{
	char choose = ' ';
	int count = 2;

	ofstream passengersFile("passengers.dat", ios::binary | ios::app);

	cout << "First Name: ";
	cin >> passengers.first_name;
	cout << "Middle Name: ";
	cin >> passengers.middle_name;
	cout << "Last Name: ";
	cin >> passengers.last_name;
	cout << "Date of Birth: ";
	cin >> passengers.date_of_birth;
	cout << "Profession: ";
	cin >> passengers.profession;
	cout << "Natinality: ";
	cin >> passengers.nationality;
	cout << "Passport Number: ";
	cin >> passengers.passportNo;
	cout << "passport Expiration Date: ";
	cin >> passengers.passport_expiration_date;

	// Forming a Uniqe Code
	passengerUniqeID[0] = toupper(passengers.first_name[0]);
	passengerUniqeID[1] = toupper(passengers.middle_name[0]);
	for (int i = 0; i < (sizeof(passengers.last_name) / sizeof(passengers.last_name[0])); i++)
	{
		if (passengers.last_name[i] == '\0')
		{
			break;
		}
		passengerUniqeID[i + 2] = toupper(passengers.last_name[i]);
		count++;
	}

	for (int x = 0; x < 3; x++)
	{
		passengerUniqeID[count] = passengers.passportNo[x];
		count++;
	}

	for (int i = 0; i < 20; i++)
	{
		if (passengerUniqeID[i] == '\0')
		{
			break;
		}
		passengers.UniqeID[i] = passengerUniqeID[i];
		PASSENGERid += passengers.UniqeID[i]; //used in booking later on
	}

	cout << endl;
	cout << "Your ID is:";
	cout << passengers.UniqeID << endl;
	//end of formating the uniqe code

	passengersFile.write((char*)&passengers, sizeof(passengers));
	passengersFile.close();
}
//task 2
void oneWay()
{
	int choice;
	int count_to_find = 0;
	string account_code;

	ofstream inbooking("booking.dat", ios::binary | ios::app);

	time_t current_time = time(0); // current date/time based on current system
	struct tm the_time_now;
	localtime_s(&the_time_now, &current_time);

	int nowday = the_time_now.tm_mday;
	int nowmonth = 1 + the_time_now.tm_mon;
	int nowyear = 1900 + the_time_now.tm_year;

	cout << "To open the flights schedule of a certain city, ";
	cout << "enter the name of your destination (from and to) " << endl;
	cout << "from: ";
	cin >> booking.fromdestination;
	cout << "to: ";
	cin >> booking.todestination;

	char firstfrom = toupper(booking.fromdestination[0]);
	char firstto = toupper(booking.todestination[0]);

	ifstream flight7("flights.dat", ios::binary);
	ifstream flight8("flights.dat", ios::binary);
	flight7.read((char*)&flights, sizeof(flights));

	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|\t| Flight code  " << "| Flight no.  " << "| Plane ID       " << "|   From    " << "|   To      " << "| Duration    " << "| Departure Time  " << "| Arrival Time " << "| Frequency  |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	while (!flight7.eof())
	{
		if (flights.Flightcode[0] == firstfrom && flights.Flightcode[1] == firstto)
		{
			cout << flights.flightday << ":     " << flights.Flightcode << "    | " << flights.flightNo << "      | " << flights.planeID << " |  " << flights.fromCountry << "    |  " << flights.toCounty << "    | " << flights.duration_hours
				<< " |      " << flights.Dtime << "      |     " << flights.Atime << "    | " << flights.freq_weekly << "         |" << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		}
		flight7.read((char*)&flights, sizeof(flights));
	}

	cout << "Enter the day of the flight you choice: ";
	cin >> booking.day;

	char firstLday = toupper(booking.day[0]);
	char lastLday = toupper(booking.day[1]);

	flight8.read((char*)&flights, sizeof(flights));
	while (!flight8.eof())
	{
		if (flights.Flightcode[0] == firstfrom && flights.Flightcode[1] == firstto && firstLday == flights.Flightcode[2] && lastLday == flights.Flightcode[3])
		{
			for (int i = 0; i < 20; i++)
			{
				flightID_ticket[i] = flights.Flightcode[i];
			}
			break;
		}
		flight8.read((char*)&flights, sizeof(flights));
	}

	cout << endl;
	cout << "Enter the date of that day (Day, Month then Year): " << endl;
	cout << "Your booking MUST be within a range of 3 months from TODAY " << endl;
	cout << "day: ";
	cin >> booking.D;
	cout << "month: ";
	cin >> booking.M;
	int yourMonth = atoi(booking.M);
	cout << "year: ";
	cin >> booking.Y;
	int yourYear = atoi(booking.Y);
	cout << endl;

	if ((yourMonth - nowmonth) <= 3 && (yourYear == nowyear))
	{
		FLIGHTid[0] = toupper(booking.fromdestination[0]);
		FLIGHTid[1] = toupper(booking.todestination[0]);
		FLIGHTid[2] = toupper(booking.day[0]);
		FLIGHTid[3] = toupper(booking.day[1]);
		FLIGHTid[4] = booking.D[0];
		FLIGHTid[5] = booking.D[1];
		FLIGHTid[6] = booking.M[0];
		FLIGHTid[7] = booking.M[1];
		FLIGHTid[8] = booking.Y[0];
		FLIGHTid[9] = booking.Y[1];
		FLIGHTid[10] = booking.Y[2];
		FLIGHTid[11] = booking.Y[3];

		cout << "Do you have an account code on our MiuAir or you would creat a new one" << endl;
		cout << "Press (1) if you have an account" << endl;
		cout << "Press (2) to creat a new account" << endl;
		cin >> choice;

		ifstream passengerfile5("passengers.dat", ios::binary);
		passengerfile5.read((char*)&passengers, sizeof(passengers));

		switch (choice)
		{
		case 1:
			cout << "enter your account code: ";
			cin >> account_code;
			while (!passengerfile5.eof())
			{
				if (account_code == passengers.UniqeID)
				{
					count_to_find++;
					break;
				}
				passengerfile5.read((char*)&passengers, sizeof(passengers));
			}

			if (count_to_find = 1)
			{
				while (!passengerfile5.eof())
				{
					if (account_code == passengers.UniqeID)
					{

						cout << "choose your seat" << endl << endl;
						cheacking_Plane();

						strncpy_s(booking.passengerID, passengers.UniqeID, 20);
						strncpy_s(booking.flightID, FLIGHTid, 20);

						inbooking.write((char*)&booking, sizeof(booking));
						inbooking.close();

						PASSENGERid = account_code;

						break;
					}
					passengerfile5.read((char*)&passengers, sizeof(passengers));
				}
			}

			if (count_to_find = 0)
			{
				system("cls");
				cout << "Error!! the account code you entered does not exist" << endl << endl;
				oneWay();
			}
			print_ticket();
			break;
		case 2:
			add_passenger();

			cout << "choose your seat" << endl << endl;
			cheacking_Plane();

			for (int j = 0; j < 20; j++)
			{
				if (PASSENGERid[j] == '\0')
				{
					break;
				}
				booking.passengerID[j] = PASSENGERid[j];
			}
			strncpy_s(booking.flightID, FLIGHTid, 20);


			inbooking.write((char*)&booking, sizeof(booking));
			inbooking.close();
			print_ticket();
			break;
		default:
			system("cls");
			cout << "  ERROR!! (invalid input)  " << endl;
			exit(0);
			break;
		}
		passengerfile5.close();
	}
	else
	{
		system("cls");
		cout << "Your booking MUST be within a range of 3 months from TODAY" << endl;
		oneWay();
	}
	flight7.close();
}
//task 2
void roundTrip()
{
	int choice;
	string account_code;
	int count_to_find = 0;

	ofstream inbooking("booking.dat", ios::binary | ios::app);

	int yourMonth, yourYear;

	time_t current_time = time(0); // current date/time based on current system
	struct tm the_time_now;
	localtime_s(&the_time_now, &current_time);

	int nowday = the_time_now.tm_mday;
	int nowmonth = 1 + the_time_now.tm_mon;
	int nowyear = 1900 + the_time_now.tm_year;

	cout << "To open the flights schedule of a certain city, ";
	cout << "enter the name of your destination (from and to) " << endl;
	cout << "from: ";
	cin >> booking.fromdestination;
	cout << "to: ";
	cin >> booking.todestination;

	char firstfrom = toupper(booking.fromdestination[0]);
	char firstto = toupper(booking.todestination[0]);

	ifstream flight7("flights.dat", ios::binary);
	ifstream flight8("flights.dat", ios::binary);

	flight7.read((char*)&flights, sizeof(flights));

	cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|\t| Flight code  " << "| Flight no.  " << "| Plane ID       " << "|   From    " << "|   To      " << "| Duration    " << "| Departure Time  " << "| Arrival Time " << "| Frequency  |" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	while (!flight7.eof())
	{
		if (flights.Flightcode[0] == firstfrom && flights.Flightcode[1] == firstto)
		{
			cout << flights.flightday << ":     " << flights.Flightcode << "    | " << flights.flightNo << "      | " << flights.planeID << " |  " << flights.fromCountry << "    |  " << flights.toCounty << "    | " << flights.duration_hours
				<< " |      " << flights.Dtime << "      |     " << flights.Atime << "    | " << flights.freq_weekly << "         |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		}
		flight7.read((char*)&flights, sizeof(flights));
	}

	cout << "Enter the day of the flight you chose: ";
	cin >> booking.day;

	char firstLday = toupper(booking.day[0]);
	char lastLday = toupper(booking.day[1]);

	flight8.read((char*)&flights, sizeof(flights));
	while (!flight8.eof())
	{
		if (flights.Flightcode[0] == firstfrom && flights.Flightcode[1] == firstto && firstLday == flights.Flightcode[2] && lastLday == flights.Flightcode[3])
		{
			for (int i = 0; i < 20; i++)
			{
				flightID_ticket[i] = flights.Flightcode[i];
			}
			break;
		}
		flight8.read((char*)&flights, sizeof(flights));
	}

	cout << endl;
	cout << "Enter the date of that day (Day, Month then Year): " << endl;
	cout << "Your booking MUST be within a range of 3 months from TODAY " << endl;
	cout << "Day: ";
	cin >> booking.D;
	cout << "month: ";
	cin >> booking.M;
	yourMonth = atoi(booking.M);
	cout << "year: ";
	cin >> booking.Y;
	yourYear = atoi(booking.Y);
	cout << endl;
	if ((yourMonth - nowmonth) <= 3 && (yourYear == nowyear))
	{
		FLIGHTid[0] = toupper(booking.fromdestination[0]);
		FLIGHTid[1] = toupper(booking.todestination[0]);
		FLIGHTid[2] = toupper(booking.day[0]);
		FLIGHTid[3] = toupper(booking.day[1]);
		FLIGHTid[4] = booking.D[0];
		FLIGHTid[5] = booking.D[1];
		FLIGHTid[6] = booking.M[0];
		FLIGHTid[7] = booking.M[1];
		FLIGHTid[8] = booking.Y[0];
		FLIGHTid[9] = booking.Y[1];
		FLIGHTid[10] = booking.Y[2];
		FLIGHTid[11] = booking.Y[3];

	}
	else
	{
		system("cls");
		cout << "Your booking MUST be within a range of 3 months from TODAY" << endl;
		roundTrip();
	}

	cout << "Do you have an account code on our MiuAir or you would creat a new one" << endl;
	cout << "Press (1) if you have an account" << endl;
	cout << "Press (2) to creat a new account" << endl;
	cin >> choice;

	ifstream passengerfile5("passengers.dat", ios::binary);
	passengerfile5.read((char*)&passengers, sizeof(passengers));

	switch (choice)
	{
	case 1:
		cout << "enter your account code: ";
		cin >> account_code;
		while (!passengerfile5.eof())
		{
			if (account_code == passengers.UniqeID)
			{
				count_to_find++;
				break;
			}
			passengerfile5.read((char*)&passengers, sizeof(passengers));
		}

		if (count_to_find = 1)
		{
			while (!passengerfile5.eof())
			{
				if (account_code == passengers.UniqeID)
				{

					cout << "choose your seat" << endl << endl;
					cheacking_Plane();

					strncpy_s(booking.passengerID, passengers.UniqeID, 20);
					strncpy_s(booking.flightID, FLIGHTid, 20);

					inbooking.write((char*)&booking, sizeof(booking));
					inbooking.close();

					PASSENGERid = account_code;

					break;
				}
				passengerfile5.read((char*)&passengers, sizeof(passengers));
			}
		}

		if (count_to_find = 0)
		{
			system("cls");
			cout << "Error!! the account code you entered does not exist" << endl << endl;
			roundTrip();
		}
		passengerfile5.close();
		print_ticket();
		break;
	case 2:
		add_passenger();

		cout << "choose your seat" << endl << endl;
		cheacking_Plane();

		for (int j = 0; j < 20; j++)
		{
			if (PASSENGERid[j] == '\0')
			{
				break;
			}
			booking.passengerID[j] = PASSENGERid[j];
		}
		strncpy_s(booking.flightID, FLIGHTid, 20);

		inbooking.write((char*)&booking, sizeof(booking));
		inbooking.close();
		print_ticket();
		break;
	default:
		system("cls");
		cout << "  ERROR!! (invalid input)  " << endl;
		exit(0);
		break;
	}

	ofstream inbooking1("booking.dat", ios::binary | ios::app);
	flight8.read((char*)&flights, sizeof(flights));

	cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|\t| Flight code  " << "| Flight no.  " << "| Plane ID       " << "|   From    " << "|   To      " << "| Duration    " << "| Departure Time  " << "| Arrival Time " << "| Frequency  |" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	while (!flight8.eof())
	{
		if (flights.Flightcode[0] == firstto && flights.Flightcode[1] == firstfrom)
		{
			cout << flights.flightday << ":     " << flights.Flightcode << "    | " << flights.flightNo << "      | " << flights.planeID << " |  " << flights.fromCountry << "    |  " << flights.toCounty << "    | " << flights.duration_hours
				<< " |      " << flights.Dtime << "      |     " << flights.Atime << "    | " << flights.freq_weekly << "         |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		}
		flight8.read((char*)&flights, sizeof(flights));
	}

	flight7.close();
	flight8.close();

	ifstream flight9("flights.dat", ios::binary);
	cout << "Enter the day of the flight you chose: ";
	cin >> booking.day;

	firstLday = toupper(booking.day[0]);
	lastLday = toupper(booking.day[1]);

	flight9.read((char*)&flights, sizeof(flights));
	while (!flight9.eof())
	{
		if (flights.Flightcode[0] == firstto && flights.Flightcode[1] == firstfrom && firstLday == flights.Flightcode[2] && lastLday == flights.Flightcode[3])
		{
			for (int i = 0; i < 20; i++)
			{
				flightID_ticket[i] = flights.Flightcode[i];
			}
			break;
		}
		flight9.read((char*)&flights, sizeof(flights));
	}
	flight9.close();

	cout << endl;
	cout << "Enter the date of that day (Day, Month then Year): " << endl;
	cout << "Your booking MUST be within a range of 3 months from TODAY " << endl;
	cout << "Day: ";
	cin >> booking.D;
	cout << "month: ";
	cin >> booking.M;
	yourMonth = atoi(booking.M);
	cout << "year: ";
	cin >> booking.Y;
	yourYear = atoi(booking.Y);
	cout << endl;

	if ((yourMonth - nowmonth) <= 3 && (yourYear == nowyear))
	{
		FLIGHTid[0] = toupper(booking.todestination[0]);
		FLIGHTid[1] = toupper(booking.fromdestination[0]);
		FLIGHTid[2] = toupper(booking.day[0]);
		FLIGHTid[3] = toupper(booking.day[1]);
		FLIGHTid[4] = booking.D[0];
		FLIGHTid[5] = booking.D[1];
		FLIGHTid[6] = booking.M[0];
		FLIGHTid[7] = booking.M[1];
		FLIGHTid[8] = booking.Y[0];
		FLIGHTid[9] = booking.Y[1];
		FLIGHTid[10] = booking.Y[2];
		FLIGHTid[11] = booking.Y[3];

		ifstream passengerfile6("passengers.dat", ios::binary);
		passengerfile6.read((char*)&passengers, sizeof(passengers));

		while (!passengerfile6.eof())
		{
			if (PASSENGERid == passengers.UniqeID)
			{
				cout << "choose your seat" << endl << endl;
				cheacking_Plane();

				strncpy_s(booking.passengerID, passengers.UniqeID, 20);
				strncpy_s(booking.flightID, FLIGHTid, 20);

				inbooking1.write((char*)&booking, sizeof(booking));
				inbooking1.close();

				break;
			}

			passengerfile6.read((char*)&passengers, sizeof(passengers));
		}
		passengerfile6.close();
	}
	else
	{
		system("cls");
		cout << "Your booking MUST be within a range of 3 months from TODAY" << endl;
		roundTrip();
	}
	print_ticket();
	flight7.close();
}
//task 2
void multiDestinations()
{
	int choice;
	string account_code;
	int count_to_find = 0;

	ofstream inbooking("booking.dat", ios::binary | ios::app);

	time_t current_time = time(0); // current date/time based on current system
	struct tm the_time_now;
	localtime_s(&the_time_now, &current_time);

	int nowday = the_time_now.tm_mday;
	int nowmonth = 1 + the_time_now.tm_mon;
	int nowyear = 1900 + the_time_now.tm_year;

	do
	{
		cout << "To open the flights schedule of a certain city, ";
		cout << "Enter the name of your destination (from and to) " << endl;
		cout << "From: ";
		cin >> booking.fromdestination;
		cout << "To: ";
		cin >> booking.todestination;

		char firstfrom = toupper(booking.fromdestination[0]);
		char firstto = toupper(booking.todestination[0]);

		ifstream flight7("flights.dat", ios::binary);
		ifstream flight8("flights.dat", ios::binary);
		flight7.read((char*)&flights, sizeof(flights));

		cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|\t| Flight code  " << "| Flight no.  " << "| Plane ID       " << "|   From    " << "|   To      " << "| Duration    " << "| Departure Time  " << "| Arrival Time " << "| Frequency  |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		while (!flight7.eof())
		{
			if (flights.Flightcode[0] == firstfrom && flights.Flightcode[1] == firstto)
			{
				cout << flights.flightday << ":     " << flights.Flightcode << "    | " << flights.flightNo << "      | " << flights.planeID << " |  " << flights.fromCountry << "    |  " << flights.toCounty << "    | " << flights.duration_hours
					<< " |      " << flights.Dtime << "      |     " << flights.Atime << "    | " << flights.freq_weekly << "         |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;

			}
			flight7.read((char*)&flights, sizeof(flights));
		}

		cout << "Enter the day of the flight you chose: ";
		cin >> booking.day;

		char firstLday = toupper(booking.day[0]);
		char lastLday = toupper(booking.day[1]);

		flight8.read((char*)&flights, sizeof(flights));
		while (!flight8.eof())
		{
			if (flights.Flightcode[0] == firstfrom && flights.Flightcode[1] == firstto && firstLday == flights.Flightcode[2] && lastLday == flights.Flightcode[3])
			{
				for (int i = 0; i < 20; i++)
				{
					flightID_ticket[i] = flights.Flightcode[i];
				}
			}
			flight8.read((char*)&flights, sizeof(flights));
		}
		cout << endl;
		cout << "Enter the date of that day (Day, Month then Year): " << endl;
		cout << "Your booking MUST be within a range of 3 months from TODAY " << endl;
		cout << "day: ";
		cin >> booking.D;
		cout << "month: ";
		cin >> booking.M;
		int yourMonth = atoi(booking.M);
		cout << "year: ";
		cin >> booking.Y;
		int yourYear = atoi(booking.Y);
		cout << endl;

		if ((yourMonth - nowmonth) <= 3 && (yourYear == nowyear))
		{
			FLIGHTid[0] = toupper(booking.fromdestination[0]);
			FLIGHTid[1] = toupper(booking.todestination[0]);
			FLIGHTid[2] = toupper(booking.day[0]);
			FLIGHTid[3] = toupper(booking.day[1]);
			FLIGHTid[4] = booking.D[0];
			FLIGHTid[5] = booking.D[1];
			FLIGHTid[6] = booking.M[0];
			FLIGHTid[7] = booking.M[1];
			FLIGHTid[6] = booking.Y[0];
			FLIGHTid[9] = booking.Y[1];
			FLIGHTid[10] = booking.Y[2];
			FLIGHTid[11] = booking.Y[3];

			cout << "Do you have an account code on our MiuAir or you would creat a new one" << endl;
			cout << "Press (1) if you have an account" << endl;
			cout << "Press (2) to creat a new account" << endl;
			cin >> choice;

			ifstream passengerfile5("passengers.dat", ios::binary);
			passengerfile5.read((char*)&passengers, sizeof(passengers));

			switch (choice)
			{
			case 1:
				cout << "enter your account code: ";
				cin >> account_code;
				while (!passengerfile5.eof())
				{
					if (account_code == passengers.UniqeID)
					{
						count_to_find++;
						break;
					}
					passengerfile5.read((char*)&passengers, sizeof(passengers));
				}

				if (count_to_find = 1)
				{
					while (!passengerfile5.eof())
					{
						if (account_code == passengers.UniqeID)
						{

							cout << "choose your seat" << endl << endl;
							cheacking_Plane();

							strncpy_s(booking.passengerID, passengers.UniqeID, 20);
							strncpy_s(booking.flightID, FLIGHTid, 20);

							inbooking.write((char*)&booking, sizeof(booking));
							inbooking.close();

							PASSENGERid = account_code;

							break;
						}
						passengerfile5.read((char*)&passengers, sizeof(passengers));
					}
				}

				if (count_to_find = 0)
				{
					system("cls");
					cout << "Error!! the account code you entered does not exist" << endl << endl;
					multiDestinations();
				}
				print_ticket();
				break;
			case 2:
				add_passenger();
				for (int j = 0; j < 20; j++)
				{
					if (PASSENGERid[j] == '\0')
					{
						break;
					}
					booking.passengerID[j] = PASSENGERid[j];
				}
				for (int z = 0; z < 20; z++)
				{
					booking.flightID[z] = FLIGHTid[z];
				}

				cout << "choose your seat" << endl << endl;
				cheacking_Plane();

				inbooking.write((char*)&booking, sizeof(booking));
				inbooking.close();
				print_ticket();
				break;
			default:
				system("cls");
				cout << "  ERROR!! (invalid input)  " << endl;
				exit(0);
				break;
			}
			passengerfile5.close();
		}
		else
		{
			system("cls");
			cout << "Your booking MUST be within a range of 3 months from TODAY" << endl;
			multiDestinations();
		}
		flight7.close();

		cout << "Do you want to add more destination? (y/n)";
		cin >> choice;
	} while (choice != 'n' || choice != 'N');
}
//task 2
void chooseflight()
{
	char choice;

	cout << "AirMIU have trips from CAIRO to the following cities" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Our flights to Europe:  " << endl;
	cout << "-----------------------------------" << endl;
	cout << "London   |";
	cout << "Paris      |";
	cout << "Frankfurt   |" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Rome     |";
	cout << "Athena     |";
	cout << "Larnaka     |" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Our flights to The Middle East:  " << endl;
	cout << "-----------------------------------" << endl;
	cout << "Jeddah   |";
	cout << "Kuwait     |";
	cout << "Amman       |" << endl;
	cout << "-----------------------------------" << endl;

	cout << "Choose the type of the trip:" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "| (O)ne way | (R)ound trip | (M)ulti-destination |" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Your choice:";
	cin >> choice;

	switch (choice)
	{
	case 'o':
	case 'O':
		oneWay();
		switchcustomerfunction();
		break;
	case 'R':
	case 'r':
		roundTrip();
		switchcustomerfunction();
		break;
	case 'M':
	case 'm':
		multiDestinations();
		switchcustomerfunction();
		break;
	default:
		cout << "  ERROR!!  " << endl;
		cout << "please enter a valid choice" << endl;
		cout << endl << endl;
		chooseflight();
		break;
	}
}
//task 2
void customer_menu()
{
	system("cls");
	char choice = ' ';

	cout << "----------------------------------------" << endl;
	cout << "|         book a (R)eservation         |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|  display your own booking (T)icket   |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|                 (B)ACK               |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|                 (E)xit               |" << endl;
	cout << "----------------------------------------" << endl;

	cout << endl << "enter the letter of your choice" << endl;
	cout << "Your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 'r':
	case 'R':
		system("cls");
		chooseflight();
		switchcustomerfunction();
		break;
	case 't':
	case 'T':
		system("cls");
		print_ticket_choice();
		switchcustomerfunction();
		break;
	case 'b':
	case 'B':
		system("cls");
		the_menu();
		break;
	case 'e':
	case 'E':
		cout << "thank you for visiting our airline" << endl;
		exit(0);
		break;
	default:
		cout << "  ERROR!!  " << endl;
		cout << "please enter a valid choice" << endl;
		cout << endl << endl;
		customer_menu();
		break;
	}
}
//task 2
void delete_passenger()
{
	system("cls");
	passergersinfo passengers;
	string deletePassenger;
	string deleteBooking;
	string accountID;
	char choose = ' ';
	char choice = ' ';
	char thechoice = ' ';

	cout << "do you want to delete your (A)ccount or (B)ooking " << endl;
	cin >> thechoice;

	ofstream passengerfile4("newpassengers.dat", ios::binary | ios::app);
	ifstream passengerfile5("passengers.dat", ios::binary);

	ofstream bookingfile1("newbooking.dat", ios::binary | ios::app);
	ifstream bookingfile2("booking.dat", ios::binary);

	switch (thechoice)
	{
	case 'a':
	case 'A':
		cout << "enter the passenger code to delete" << endl;
		cout << "account ID: ";
		cin >> deletePassenger;

		passengerfile5.read((char*)&passengers, sizeof(passengers));
		while (!passengerfile5.eof())
		{
			if (deletePassenger != passengers.UniqeID)
			{
				passengerfile4.write((char*)&passengers, sizeof(passengers));
			}
			passengerfile5.read((char*)&passengers, sizeof(passengers));
		}
		passengerfile4.close();
		passengerfile5.close();
		remove("passengers.dat");
		rename("newpassengers.dat", "passengers.dat");

		system("cls");
		break;
	case 'b':
	case 'B':
		cout << "enter the account ID" << endl;
		cout << "account ID: ";
		cin >> accountID;
		cout << "enter the passenger code to delete" << endl;
		cout << "Booking Code: ";
		cin >> deleteBooking;

		passengerfile5.read((char*)&passengers, sizeof(passengers));
		while (!bookingfile2.eof())
		{
			if (deleteBooking != booking.flightID && accountID != booking.passengerID)
			{

				bookingfile1.write((char*)&passengers, sizeof(passengers));
			}
			bookingfile2.read((char*)&passengers, sizeof(passengers));
		}
		bookingfile1.close();
		bookingfile2.close();
		remove("booking.dat");
		rename("newbooking.dat", "booking.dat");
		system("cls");
		break;
	default:
		cout << "Error while entering your choice" << endl;
		break;
	}

	cout << "Do you want to delete another passenger or try again? (y/n)" << endl;
	cout << "your choice: ";
	cin >> choose;
	switch (choose)
	{
	case 'y':
	case 'Y':
		system("cls");
		delete_passenger();
	case 'n':
	case 'N':
		system("cls");
		cout << "Do you want to return to the passenger module menu? (y/n)" << endl;
		cout << "your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 'y':
		case 'Y':
			system("cls");
			passenger_module();
		case 'n':
		case 'N':
			system("cls");
			break;
		default:
			cout << "  ERROR!!  " << endl;
			cout << "please enter a valid number" << endl;
			cout << endl << endl;
			passenger_module();
			break;
		}
		break;
	default:
		cout << "  ERROR!!  " << endl;
		cout << "please enter a valid number" << endl;
		cout << endl << endl;
		passenger_module();
		break;
	}
}
//task 3
void modify_seat()
{
	char accountID[20];
	bool correct;
	int rowIndex, seatIndex;

	ifstream read("booking.dat", ios::binary);
	ofstream write2("booking2.dat", ios::binary | ios::app);

	cout << "Please enter your Account ID: ";
	cin >> accountID;

	for (int i = 0; i < 20; i++)
	{
		accountID[i] = toupper(accountID[i]);
	}


	read.read((char*)&booking, sizeof(booking));

	while (!read.eof())
	{
		for (int i = 0; i < 20; i++)
		{
			if (accountID[i] == booking.passengerID[i])
			{
				correct = true;
			}
			else
			{
				correct = false;
				break;
			}
			read.read((char*)&booking, sizeof(booking));
		}

		if (correct = true)
		{
			switch (booking.seatclass[0])
			{
			case 'B':
				seatIndex = atoi(booking.seatnum) - 1;
				switch (booking.seatrow)
				{
				case 'A':
					rowIndex = 4;
					break;
				case 'C':
					rowIndex = 3;
					break;
				case 'D':
					rowIndex = 1;
					break;
				case 'F':
					rowIndex = 0;
					break;
				}
				BusSeats[rowIndex][seatIndex] = '*';
				break;
			case 'E':
				seatIndex = atoi(booking.seatnum) - 1;
				switch (booking.seatrow)
				{
				case 'A':
					rowIndex = 6;
					break;
				case 'B':
					rowIndex = 5;
					break;
				case 'C':
					rowIndex = 4;
					break;
				case 'D':
					rowIndex = 2;
					break;
				case 'E':
					rowIndex = 1;
					break;
				case 'F':
					rowIndex = 0;
					break;
				}
				EcoSeats[ecorow][ecoseats] = '*';
				break;
			}

			the_seats();
			booking.seatrow = modified_seat[0];
			booking.seatnum[1] = modified_seat[1];
			booking.seatnum[2] = modified_seat[2];
			write2.write((char*)&booking, sizeof(booking));
		}
		else
		{
			write2.write((char*)&booking, sizeof(booking));
		}

		read.read((char*)&booking, sizeof(booking));
	}

	read.close();
	write2.close();

	remove("booking.dat");
	rename("booking2.dat", "booking.dat");
}
//task 2
void modify_passenger()
{
	system("cls");
	passergersinfo passengers;
	string modifyPassenger;
	string modifyBooking;
	string accountID;
	char choice3 = ' ';
	char choose = ' ';
	char choice = ' ';
	char thechoice = ' ';

	cout << "Do you want to modify your (A)ccount ,(B)ooking or (S)eat " << endl;
	cin >> thechoice;

	ofstream passengerfile2("thenewpassengers.dat", ios::binary | ios::app);
	ifstream passengerfile3("passengers.dat", ios::binary);

	ofstream bookingfile1("thenewbooking.dat", ios::binary | ios::app);
	ifstream bookingfile2("booking.dat", ios::binary);

	switch (thechoice)
	{
	case 'a':
	case 'A':
		cout << "enter the passenger account ID to modify" << endl;
		cout << "Account ID: ";
		cin >> modifyPassenger;

		passengerfile3.read((char*)&passengers, sizeof(passengers));
		while (!passengerfile3.eof())
		{
			if (modifyPassenger != passengers.UniqeID)
			{
				passengerfile2.write((char*)&passengers, sizeof(passengers));
			}
			if (modifyPassenger == passengers.UniqeID)
			{
				int thechoice;
				cout << "Please enter the data after modification" << endl << endl;
				cout << "to change First Name press (1)" << endl;
				cout << "to change Middle Name press (2)" << endl;
				cout << "to change Last Name press (3)" << endl;
				cout << "to change Date of Birth press (4)" << endl;
				cout << "to change Profession press (5)" << endl;
				cout << "to change Nationality press (6)" << endl;
				cout << "to change passport Number press (7)" << endl;
				cout << "to change passport expiration date press (8)" << endl;
				cout << "to change ALL press (9)" << endl;
				cin >> thechoice;
				cout << endl;
				switch (thechoice)
				{
				case 1:
					cout << "First Name: ";
					cin >> passengers.first_name;
					break;
				case 2:
					cout << "Middle Name: ";
					cin >> passengers.middle_name;
					break;
				case 3:
					cout << "Last Name: ";
					cin >> passengers.last_name;
					break;
				case 4:
					cout << "Date of Birth: ";
					cin >> passengers.date_of_birth;
					break;
				case 5:
					cout << "Profession: ";
					cin >> passengers.profession;
					break;
				case 6:
					cout << "Nationality: ";
					cin >> passengers.nationality;
					break;
				case 7:
					cout << "Passport Number: ";
					cin >> passengers.passportNo;
					break;
				case 8:
					cout << "Passport Expiration Date: ";
					cin >> passengers.passport_expiration_date;
					break;
				case 9:
					cout << "First Name: ";
					cin >> passengers.first_name;
					cout << "Middle Name: ";
					cin >> passengers.middle_name;
					cout << "Last Name: ";
					cin >> passengers.last_name;
					cout << "Date of Birth: ";
					cin >> passengers.date_of_birth;
					cout << "Profession: ";
					cin >> passengers.profession;
					cout << "Nationality: ";
					cin >> passengers.nationality;
					cout << "Passport Number: ";
					cin >> passengers.passportNo;
					cout << "Passport Expiration Date: ";
					cin >> passengers.passport_expiration_date;
					passengerfile2.write((char*)&passengers, sizeof(passengers));
					break;
				default:
					cout << "  ERROR!!  " << endl;
					cout << "please enter a valid choice" << endl;
					cout << endl << endl;
					break;
				}
			}
			cout << endl;
			passengerfile3.read((char*)&passengers, sizeof(passengers));
		}

		passengerfile2.close();
		passengerfile3.close();
		remove("passengers.dat");
		rename("thenewpassengers.dat", "passengers.dat");
		break;
	case 'b':
	case 'B':
		cout << "enter the account ID" << endl;
		cout << "Account ID: ";
		cin >> accountID;
		cout << "enter the booking code to modify" << endl;
		cout << "Booking code: ";
		cin >> modifyBooking;

		bookingfile2.read((char*)&booking, sizeof(booking));
		while (!bookingfile2.eof())
		{
			if (modifyBooking != booking.flightID && accountID != booking.passengerID)
			{
				bookingfile1.write((char*)&passengers, sizeof(passengers));
			}
			if (modifyBooking == booking.flightID && accountID == booking.passengerID)
			{
				int thechoice;
				cout << "Please enter the data after modification" << endl << endl;
				cout << "to change the distination press (1)" << endl;
				cout << "to change day and date of the flight press (2)" << endl;
				cin >> thechoice;
				cout << endl;
				switch (thechoice)
				{
				case 1:
					chooseflight();
					break;
				case 2:
					//to get the current time
					int nowday; // day of month from 1 to 31
					int nowmonth; // month of year from 0 to 11
					int nowyear; // year since 1900
					int month, year;

					time_t current_time = time(0); // current date/time based on current system
					struct tm the_time_now;
					localtime_s(&the_time_now, &current_time); //takes current time in the struct format

					nowday = the_time_now.tm_mday;
					nowmonth = 1 + the_time_now.tm_mon;
					nowyear = 1900 + the_time_now.tm_year;

					cout << "Do you want to change the trip (Y/N)" << endl;
					cin >> choice3;
					choice3 = toupper(choice3);

					if (choice3 == 'Y')
					{
						cout << "Day of travelling: ";
						cin >> booking.day;
						cout << "day: ";
						cin >> booking.D;
						cout << "month: ";
						cin >> booking.M;
						month = atoi(booking.M);
						cout << "year: ";
						cin >> booking.Y;
						year = atoi(booking.Y);
						cout << endl;
						if ((month - nowmonth) <= 3 && (year == nowyear))
						{
							FLIGHTid[0] = toupper(booking.fromdestination[0]);
							FLIGHTid[1] = toupper(booking.todestination[0]);
							FLIGHTid[2] = toupper(booking.day[0]);
							FLIGHTid[3] = toupper(booking.day[1]);
							FLIGHTid[4] = booking.D[0];
							FLIGHTid[5] = booking.D[1];
							FLIGHTid[6] = booking.M[0];
							FLIGHTid[7] = booking.M[1];
							FLIGHTid[8] = booking.Y[0];
							FLIGHTid[9] = booking.Y[1];
							FLIGHTid[10] = booking.Y[2];
							FLIGHTid[11] = booking.Y[3];
							for (int z = 0; z < 20; z++)
							{
								booking.flightID[z] = FLIGHTid[z];
							}
							bookingfile1.write((char*)&passengers, sizeof(passengers));
							break;
						}
						else
						{
							cout << "Your booking MUST be within a range of 3 months from TODAY" << endl;
							modify_passenger();
						}
						/*default:
						cout << "  ERROR!!  " << endl;
						cout << "please enter a valid choice" << endl;
						cout << endl << endl;
						break;*/
					}

					cout << endl;
				}
				bookingfile2.read((char*)&passengers, sizeof(passengers));
			}

			bookingfile1.close();
			bookingfile2.close();
			remove("booking.dat");
			rename("thenewbooking.dat", "booking.dat");
			break;

	case 's':
	case 'S':
	{
		modify_seat();
	}
	default:
		cout << "Error!! while entering your choice" << endl;
		break;
		}

		cout << "Do you want to modify another flight? (y/n)" << endl;
		cout << "your choice: ";
		cin >> choose;
		switch (choose)
		{
		case 'y':
		case 'Y':
			system("cls");
			modify_passenger();
		case 'n':
		case 'N':
			system("cls");
			cout << "Do you want to return to the passenger module menu? (y/n)" << endl;
			cout << "your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 'y':
			case 'Y':
				system("cls");
				passenger_module();
			case 'n':
			case 'N':
				system("cls");
				break;
			default:
				cout << "  ERROR!!  " << endl;
				cout << "please enter a valid choice" << endl;
				cout << endl << endl;
				passenger_module();
				break;
			}
			break;
		default:
			cout << "  ERROR!!  " << endl;
			cout << "please enter a valid choice" << endl;
			cout << endl << endl;
			passenger_module();
			break;
		}
	}
}
//task 2
void list_passengers_onFlight()
{
	bookinginfo booking;
	passergersinfo passengers;
	string bookingCode;
	int x = 0;

	ifstream bookingfile("booking.dat", ios::binary);
	ifstream passengersfile("passengers.dat", ios::binary);

	cout << "Enter the flight code you want to list the passengers on it " << endl;
	cin >> bookingCode;

	bookingfile.read((char*)&booking, sizeof(booking));
	passengersfile.read((char*)&passengers, sizeof(passengers));
	while (!bookingfile.eof())
	{
		if (bookingCode == booking.flightID)
		{
			cout << x++ << ".  " << booking.passengerID << " " << setw(5) << " " << passengers.first_name << " " << setw(5) << " " << passengers.middle_name << " " << setw(5) << " "
				<< passengers.last_name << " " << setw(5) << " " << passengers.nationality << " " << setw(5) << " " << passengers.passportNo << endl;
		}
		bookingfile.read((char*)&booking, sizeof(booking));
		passengersfile.read((char*)&passengers, sizeof(passengers));
	}
	bookingfile.close();
	passengersfile.close();
}

void switchpassengerfunction()
{
	char choice = ' ';
	cout << endl << endl << "Do you want to return to the passenger module menu? (y/n)" << endl;
	cout << "your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 'y':
	case 'Y':
		system("cls");
		passenger_module();
	case 'n':
	case 'N':
		system("cls");
		break;
	default:
		system("cls");
		cout << "  ERROR!! (invalid input)  " << endl;
		exit(0);
		break;

	}
}
//task 2
void passenger_module()
{
	system("cls");
	char choice = ' ';

	cout << "-------------------------------------------------" << endl;
	cout << "|         dis(P)lay the flight schdules         |" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "|         (L)ist all the available passenger    |" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "|                add a b(O)oking                |" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "|                (A)dd a passenger              |" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "|         (D)elete a passenger or a booking     |" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "|         (M)odify a passenger or a booking     |" << endl; //what about if he wanna to change anything in his booking
	cout << "-------------------------------------------------" << endl;
	cout << "|                     (B)ACK                    |" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "|                     (E)XIT                    |" << endl;
	cout << "-------------------------------------------------" << endl;

	cout << endl << "enter the letter of your choice" << endl;
	cout << "Your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 'p':
	case 'P':
		system("cls");
		display_data_customer();
		switchpassengerfunction();
		break;
	case 'l':
	case 'L':
		system("cls");
		list_passengers_onFlight();
		switchpassengerfunction();
		break;
	case 'o':
	case 'O':
		system("cls");
		chooseflight();
		switchpassengerfunction();
		break;
	case 'a':
	case 'A':
		system("cls");
		add_passenger();
		switchpassengerfunction();
		break;
	case 'd':
	case 'D':
		system("cls");
		delete_passenger();
		switchpassengerfunction();
		break;
	case 'm':
	case 'M':
		system("cls");
		modify_passenger();
		switchpassengerfunction();
		break;
	case 'b':
	case 'B':
		system("cls");
		the_menu();
		break;
	case 'e':
	case 'E':
		cout << "thank you for visiting our airline" << endl;
		exit(0);
		break;
	default:
		cout << "  ERROR!!  " << endl;
		cout << "please enter a valid choice" << endl;
		cout << endl << endl;
		passenger_module();
		break;
	}


}
//task 3
void intiPlane()
{
	//Business*********************************************
	for (int z = 0; z < 4; z++)
	{
		BusSeats[2][z] = static_cast<char>(z + 49);
	}


	for (int q = 0; q < 2; q++) //column
	{
		for (int w = 0; w < 4; w++) //row
		{
			BusSeats[q][w] = '*';
		}
	}

	for (int q = 3; q < 5; q++)
	{
		for (int w = 0; w < 4; w++)
		{
			BusSeats[q][w] = '*';
		}
	}

	//Ecomony*****************************************

	for (int z = 0; z < 25; z++)
	{
		EcoNo[z] = z + 6;
	}

	for (int q = 0; q < 3; q++)
	{
		for (int w = 0; w < 25; w++)
		{
			EcoSeats[q][w] = '*';
		}
	}

	for (int q = 4; q < 7; q++)
	{
		for (int w = 0; w < 25; w++)
		{
			EcoSeats[q][w] = '*';
		}
	}

}
//task 3
void seats_display()
{
	cout << "   _________________________________________________________________________________________________________________" << endl;
	cout << endl;

	for (int i = 0; i < 7; i++)
	{
		if (i < 5)
		{
			cout << "   " << Busletters[i] << " ";

			for (int j = 0; j < 4; j++)
			{
				cout << BusSeats[i][j] << " ";
			}
			cout << "|";
		}
		else if (i == 5 || i == 6)
		{
			cout << "             |";
		}

		cout << Ecoletters[i] << " ";

		if (i == 3)
		{
			for (int k = 0; k < 25; k++)
			{
				if (k < 4)
					cout << EcoNo[k] << "   ";
				else
					cout << EcoNo[k] << "  ";

			}
			cout << "|" << endl;
		}
		else
		{
			for (int b = 0; b < 25; b++)
			{
				cout << EcoSeats[i][b] << "   ";
			}
			cout << "|" << endl;
		}

	}

	cout << "   __________________________________________________________________________________________________________________" << endl;

}
//task 3
void print_ticket()
{
	string account_code;
	account_code = PASSENGERid;

	ifstream passengersfile("passengers.dat", ios::binary);
	ifstream bookingfile("booking.dat", ios::binary);
	ifstream bookingfile2("booking.dat", ios::binary);
	ifstream flightsfile("flights.dat", ios::binary);

	passengersfile.read((char*)&passengers, sizeof(passengers));
	bookingfile.read((char*)&booking, sizeof(booking));
	bookingfile2.read((char*)&booking, sizeof(booking));
	flightsfile.read((char*)&flights, sizeof(flights));

	cout << "Here is your ticket:" << endl;
	cout << "_______________________________________________________" << endl;

	while (!passengersfile.eof())
	{
		//if (account_code == passengers.UniqeID)
		
			cout << passengers.first_name << " " << passengers.middle_name << " " << passengers.last_name << endl << endl;
			break;
		
		passengersfile.read((char*)&passengers, sizeof(passengers));
	}
	//------
	while (!bookingfile.eof())
	{
		if (account_code == booking.passengerID)
		{
			//if (booking.flightID == FLIGHTid)
			
				cout << booking.fromdestination << " to " << booking.todestination << endl;
				cout << "Day of flight: " << booking.day << endl;
				cout << "Date of flight: " << booking.D << " \ " << booking.M << " \ " << booking.Y << endl << endl;
				break;
			
		}
		bookingfile.read((char*)&booking, sizeof(booking));
	}
	//------
	while (!flightsfile.eof())
	{
		if (_stricmp(flightID_ticket, flights.Flightcode) == 0)
		{
			cout << "Depearture time: " << flights.Dtime << "   Arival time: " << flights.Atime << endl;
			cout << "Flight Code: " << flights.Flightcode << "   Flight number: " << flights.flightNo << endl << endl;
			break;
		}
		flightsfile.read((char*)&flights, sizeof(flights));
	}
	//------
	while (!bookingfile2.eof())
	{
		if (account_code == booking.passengerID)
		{
			if (booking.flightID == FLIGHTid)
			{
				cout << "Booking Class: " << booking.seatclass << "   Your Seat: " << booking.seatrow << booking.seatnum << endl << endl;
				break;
			}
		}
		bookingfile2.read((char*)&booking, sizeof(booking));
	}

	cout << "Account ID: " << account_code << endl;
	cout << "_______________________________________________________" << endl;

	passengersfile.close();
	bookingfile.close();
	bookingfile2.close();
	flightsfile.close();

}
//task 3
void print_ticket_choice()
{
	string account_ID;
	char flightCode[20];
	cout << "enter you Account ID and your flight code to display your ticket " << endl;
	cout << "Account ID: ";
	cin >> account_ID;
	cout << "Flight Code: ";
	cin >> flightCode;

	ifstream passengersfile("passengers.dat", ios::binary);
	ifstream bookingfile("booking.dat", ios::binary);
	ifstream bookingfile2("booking.dat", ios::binary);
	ifstream flightsfile("flights.dat", ios::binary);

	passengersfile.read((char*)&passengers, sizeof(passengers));
	bookingfile.read((char*)&booking, sizeof(booking));
	bookingfile2.read((char*)&booking, sizeof(booking));
	flightsfile.read((char*)&flights, sizeof(flights));

	cout << "Here is your ticket:" << endl;
	cout << "_______________________________________________________" << endl;

	while (!passengersfile.eof())
	{
		if (account_ID == passengers.UniqeID)
		{
			cout << passengers.first_name << " " << passengers.middle_name << " " << passengers.last_name << endl << endl;
			break;
		}
		passengersfile.read((char*)&passengers, sizeof(passengers));
	}
	//------
	while (!bookingfile.eof())
	{
		if (account_ID == booking.passengerID)
		{
			cout << booking.fromdestination << " to " << booking.todestination << endl;
			cout << "Day of flight: " << booking.day << endl;
			cout << "Date of flight: " << booking.D << " \ " << booking.M << " \ " << booking.Y << endl << endl;
			break;
		}
		bookingfile.read((char*)&booking, sizeof(booking));
	}
	//------
	while (!flightsfile.eof())
	{
		if (_stricmp(flightCode, flights.Flightcode) == 0)
		{
			cout << "Depearture time: " << flights.Dtime << "   Arival time: " << flights.Atime << endl;
			cout << "Flight Code: " << flights.Flightcode << "   Flight number: " << flights.flightNo << endl << endl;
			break;
		}
		flightsfile.read((char*)&flights, sizeof(flights));
	}
	//------
	while (!bookingfile2.eof())
	{
		if (account_ID == booking.passengerID)
		{
			cout << "Booking Class: " << booking.seatclass << "   Your Seat: " << booking.seatrow << booking.seatnum << endl << endl;
			break;
		}
		bookingfile2.read((char*)&booking, sizeof(booking));
	}

	cout << "Account ID: " << account_ID << endl;
	cout << "_______________________________________________________" << endl;

	passengersfile.close();
	bookingfile.close();
	bookingfile2.close();
	flightsfile.close();

}
//task 3
void the_seats()
{
	int seatsTakenB = 0;
	int seatsTakenE = 0;
	int seatsB = busrow * busseats;
	int seatsE = ecorow * ecoseats;
	int rowIndex, seatIndex;
	char choose = ' ';
	char seat[3];
	char row = ' ';

	cout << "please Choose your Class: " << endl;
	cout << "Row 1 to 4 are for Business Class seats " << endl;
	cout << "Row 6 to 32 are for Economy Class seats " << endl;
	cout << "(B) for business & (E) for economy class " << endl;
	cin >> choose;
	switch (choose)
	{
	case 'b':
	case 'B':
		cout << "you choosed business class " << endl;
		strcpy_s(booking.seatclass, "Busniss_Class");

		while (seatsTakenB < seatsB)
		{
			seats_display();
			cout << "please enter your row letter: ";
			cin >> row;
			cout << "please enter your seat number: ";
			cin >> seat;
			row = toupper(row);

			seatIndex = atoi(seat) - 1;

			switch (row)
			{
			case 'A':
				rowIndex = 4;
				break;
			case 'C':
				rowIndex = 3;
				break;
			case 'D':
				rowIndex = 1;
				break;
			case 'F':
				rowIndex = 0;
				break;
			}

			if (seatIndex >= 0 && seatIndex < 4)
				cout << "your seat is valid" << endl;
			else
			{
				system("cls");
				cout << "your seat is not valid" << endl;
				the_seats();
			}

			if (BusSeats[rowIndex][seatIndex] == 'X')
			{
				system("cls");
				cout << "Sorry, " << row << seat << " is already taken." << endl;
				the_seats();
			}
			else
			{
				cout << "DONE YOU HAVE BOOKED  " << row << seatIndex + 1 << endl;
				BusSeats[rowIndex][seatIndex] = 'X';
				booking.seatrow = row;
				booking.seatnum[0] = seat[0];
				booking.seatnum[1] = seat[1];
				seatsTakenB++;
				seats_display();
			}
			break;
		}
		break;
	case 'e':
	case 'E':
		cout << "you choosed economy class " << endl;
		strcpy_s(booking.seatclass, "Economy_Class");

		while (seatsTakenE < seatsE)
		{
			seats_display();
			cout << "please enter your row letter: ";
			cin >> row;
			cout << "please enter your seat number: ";
			cin >> seat;
			row = toupper(row);

			seatIndex = atoi(seat) - 1;

			if (seatIndex >= 5 && seatIndex < 30)
				cout << "your seat is valid" << endl;
			else
			{
				system("cls");
				cout << "your seat is not valid" << endl;
				the_seats();
			}
			switch (row)
			{
			case 'A':
				rowIndex = 6;
				break;
			case 'B':
				rowIndex = 5;
				break;
			case 'C':
				rowIndex = 4;
				break;
			case 'D':
				rowIndex = 2;
				break;
			case 'E':
				rowIndex = 1;
				break;
			case 'F':
				rowIndex = 0;
				break;
			}

			if (EcoSeats[rowIndex][seatIndex - 5] == 'X')
			{
				system("cls");
				cout << "Sorry, " << row << seat << " is already taken." << endl;
				the_seats();
			}
			else
			{
				cout << "DONE YOU HAVE BOOKED  " << row << seatIndex + 1 << endl;
				EcoSeats[rowIndex][seatIndex - 5] = 'X';
				booking.seatrow = row;
				booking.seatnum[0] = seat[0];
				booking.seatnum[1] = seat[1];
				seatsTakenE++;
				seats_display();
			}
			break;
		}
		break;
	default:
		system("cls");
		cout << "your choice is invalid " << endl;
		the_seats();
		break;
	}
	modified_seat[0] = booking.seatrow;
	modified_seat[1] = booking.seatnum[0];
	modified_seat[2] = booking.seatnum[1];
}
//task 3
void cheacking_Plane()
{
	int seatsTakenB = 0;
	int seatsTakenE = 0;
	int rowIndex, seatIndex;
	int seatsB = busrow * busseats;
	int seatsE = ecorow * ecoseats;
	int all_seats = seatsB + seatsE;
	int seatTaken = seatsTakenB + seatsTakenE;
	char choice = ' ';

	intiPlane();

	ifstream bookings("booking.dat", ios::binary);
	bookings.read((char*)&booking, sizeof(booking));
	while (!bookings.eof())
	{
		if ((_stricmp(booking.flightID, FLIGHTid) == 0) && seatTaken < all_seats)
		{
			seatTaken++;
			switch (booking.seatclass[0])
			{
			case 'B':
				seatIndex = atoi(booking.seatnum) - 1;
				switch (booking.seatrow)
				{
				case 'A':
					rowIndex = 4;
					break;
				case 'C':
					rowIndex = 3;
					break;
				case 'D':
					rowIndex = 1;
					break;
				case 'F':
					rowIndex = 0;
					break;
				}
				BusSeats[rowIndex][seatIndex] = 'X';
				break;
			case 'E':
				seatIndex = atoi(booking.seatnum) - 1;
				switch (booking.seatrow)
				{
				case 'A':
					rowIndex = 6;
					break;
				case 'B':
					rowIndex = 5;
					break;
				case 'C':
					rowIndex = 4;
					break;
				case 'D':
					rowIndex = 2;
					break;
				case 'E':
					rowIndex = 1;
					break;
				case 'F':
					rowIndex = 0;
					break;
				}
				EcoSeats[rowIndex][seatIndex] = 'X';
				break;
			}
		}
		bookings.read((char*)&booking, sizeof(booking));
	}
	bookings.close();
	if (seatTaken > all_seats)
	{
		system("cls");
		cout << "This flight is FULL" << endl;
		cout << "Do you want to book another flight? (y/n)" << endl;
		cin >> choice;
		choice = toupper(choice);
		switch (choice)
		{
		case 'Y':
			chooseflight();
			break;
		case 'N':
			cout << "Thank you and have a nice day" << endl;
			the_menu();
			break;
		default:
			cout << "ERROR!! invalid choice" << endl;
			break;
		}
	}
	else
	{
		the_seats();
	}
}
//task 1
void the_menu()
{
	system("cls");
	int choose;
	string username;
	string password;

	cout << "Welcome to MiuAir comapny.. " << endl;
	cout << "press (1) if you are an admin" << endl;
	cout << "press (2) if you are a passenger module" << endl;
	cout << "press (3) if you are a passenger" << endl;
	cout << "press (4) to exit the program" << endl;
	cin >> choose;
	system("cls");
	char again = ' ';
	while (again == 'y' || again == 'Y' && again != 'n' || again != 'N')
	{
		switch (choose)
		{
		case 1:
			cout << "please enter your username and password" << endl;
			cout << "username: ";
			cin >> username;
			cout << "password: ";
			cin >> password;
			if (username == "adminlogin1019" && password == "miucompanyteam4456")
			{
				system("cls");
				cout << "the username and password was entered correctly" << endl << endl;
				admin_menu();
			}
			else
			{
				cout << "the username or the password was NOT entered correctly" << endl;
				cout << "Do you want to try again ? (y/n)" << endl;
				cin >> again;
				system("cls");
				the_menu();
			}
			break;
		case 2:
			cout << "please enter your username and password" << endl;
			cout << "username: ";
			cin >> username;
			cout << "password: ";
			cin >> password;
			if (username == "passengermodule009" && password == "passengerm009")
			{
				system("cls");
				cout << "the username and password was entered correctly" << endl << endl;
				passenger_module();
			}
			else
			{
				cout << "the username or the password was NOT entered correctly" << endl;
				cout << "Do you want to try again ? (y/n)" << endl;
				cin >> again;
				system("cls");
				the_menu();
			}
			break;
		case 3:
			system("cls");
			customer_menu();
			break;
		case 4:
			cout << "thank you for visiting our airline" << endl;
			exit(0);
			break;
		default:
			cout << "  ERROR!!  " << endl;
			cout << "please enter a valid number" << endl;
			cout << endl << endl;
			the_menu();
			break;
		}
		break;
	}
}

int main()
{
	system("color F0"); // makes background white and text black
	the_menu();
	return 0;
}