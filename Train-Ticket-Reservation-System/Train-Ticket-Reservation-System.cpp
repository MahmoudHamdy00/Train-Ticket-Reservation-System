#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<string>

HANDLE mahmoud = GetStdHandle(STD_OUTPUT_HANDLE);
#define clr(i) SetConsoleTextAttribute(mahmoud, i);

using namespace std;

//seat structure 
struct seats {
	int stid;
	bool sts = false;
};

//car strcture
struct cars {
	int cid, nfs = 30;
	bool csts = true;
	seats seat[31];
};
cars car[11];
//start form
void menu();
//intialisation function
void initial(cars car[]);
//input car id function
void carinput(int& cid);
//input seat id function
void seatinput(int& sid);
//1 - Reserve a ticket.
bool reserve(int carid, int seatid);
//2 - Cancel the reservation.
bool cancel(int carid, int seatid);
//3-Check whether a specific car has available seat or not.
bool car_availability(int carid);
//4-Check whether a specific seat is available or not.
bool seat_availability(int carid, int seatid);
//5-Get the number of the available seats in a specific car.
int numofseats(int carid);
//6-Show all the seats status of a specific car.
void car_status(int carid);
//exit form
void exit();

int main()
{
	//intializing the variables
	initial(car);
	for (;;) {
		system("cls");
		menu();
		int n, cid, sid;
		string s;
		//inputting the choice num... 
		cin >> s;
		if (s[0] < '0' || s[0]>'7' || s.length() > 1)
		{
			clr(4);
			cout << "\aInvaild Input,Please try again...\n";
			clr(15);
			system("pause");
			continue;
		}
		n = s[0] - 48;
		system("cls");
		switch (n) {
			//1-Reserve a ticket
		case 1: {
			system("cls");
			while (1) {
			o:clr(8);
				cout << "==================================== Reserving seats ==================================== code by \"Mahmoud Hamdy\"\n\n";
				clr(15);
				bool status = 0;
				do {
					//calling car id input function
					carinput(cid);
					//check wheather thair is available seats or not...
					if (car[cid].nfs == 0) {
						system("cls");
						clr(4);
						cout << "\aSorry, The car you selcted is completely reserved.\n";
						clr(11);
						cout << "Please choose another car...\n";
						clr(15);
					}
				} while (car[cid].nfs == 0);
				//calling seat id input function
				seatinput(sid);
				while (1) {
					status = reserve(cid, sid);
					if (status)
						break;
					else {
						clr(11);
						cout << "Enter the Car's ID 1->10\n";
						cin >> cid;
						cout << "Enter the Seat's ID 1->30\n";
						cin >> sid;
						clr(15);
					}
				}
				bool done = 0;
				while (1) {
					clr(13);
					cout << "\n\nDo you want to reserve another seat?\nYes -> press 1\nNo  -> press 2\n";
					clr(15);
					int in;
					cin >> in;
					system("cls");
					if (in == 2) {
						done = 1;
						break;
					}
					else if (in == 1)
						goto o;
					else {
						clr(4);
						cout << "\aInvaild Input\n";
						clr(15);
					}
				}
				if (done)
					break;
			}
			break; }
			  //2-Cancel the reservation
		case 2: {
			system("cls");
			clr(8);
			cout << "================================= Cancelling Reservation =================================  code by \"Mahmoud Hamdy\"\n\n";
			bool status = 0;
			while (!status) {
				//calling car id input function
				carinput(cid);
				//calling seat id input function
				seatinput(sid);
				clr(15);
				status = cancel(cid, sid);
			}
			break;
		}
			  //3-Check whether a specific car has available seat or not
		case 3: {
			system("cls");
			clr(8);
			cout << "======================== Seats availability of a specific car ======================== code by \"Mahmoud Hamdy\"\n\n";
			//calling car id input function
			carinput(cid);
			bool ca = car_availability(cid);
			if (ca) {
				clr(10);
				cout << "There available seats\n";
				clr(15);
			}
			else {
				clr(4);
				cout << "Sorry, No seats available\n";
				clr(15);
			}
			system("pause");
			break;
		}
			  //4-Check whether a specific seat is available or not.
		case 4: {
			system("cls");
			clr(8);
			cout << "====================================== Seats Status ====================================== code by \"Mahmoud Hamdy\"\n\n";
			//calling car id input function
			carinput(cid);
			//calling seat id input function
			seatinput(sid);
			bool status = seat_availability(cid, sid);
			if (status == true)
			{
				clr(10);
				cout << "The seat is available\n";
				clr(15);
			}
			else
			{
				clr(4);
				cout << "\aThe seat isn't available";
				clr(15);
			}
			system("pause");
			break;
		}
			  //5-Get the number of the available seats in a specific car
		case 5: {
			system("cls");
			clr(8);
			cout << "======================= Number of available Seats in a specific car ======================= code by \"Mahmoud Hamdy\"\n\n";
			//calling car id input function
			carinput(cid);

			int nums = numofseats(cid);
			if (nums == 0)
			{
				clr(4);
				cout << "Sorry, No seats available\n";
				clr(15);
			}
			else if (nums == 1)
			{
				clr(10);
				cout << "There is 1 seat available\n";
				clr(15);
			}
			else {
				clr(10);
				cout << "There are " << nums << " seats available\n";
				clr(15);
			}
			system("pause");
			break;
		}
			  //6 - Show all the seats status of a specific car.
		case 6: {
			system("cls");
			clr(8);
			cout << "================================= Status of specific car ================================= code by \"Mahmoud Hamdy\"\n\n";
			//calling car id input function
			carinput(cid);
			car_status(cid);
			system("pause");
			break;
		}
			  //exit
		case 7: {
			while (1)
			{
				clr(13);
				cout << "Are you sure you want yo exit ?\n\n";
				clr(4);
				cout << "Yes, I want to leave -> press 1\n";
				clr(10);
				cout << "No, go back -> press 2\n";
				int u;
				cin >> u;
				if (u == 1)
				{
					system("cls");
					exit();
					return 0;
				}
				else if (u == 2)
				{
					system("cls");
					break;
				}
				else {
					system("cls");
					clr(4);
					cout << "\aInvaild Input\n";
					clr(15);
				}
			}
			break;
		}
		default:
		{
			clr(4);
			cout << "\aInvaild Input,Please try again...\n";
			clr(15);
			break;
		}
		}
		//system("pause");
	}

	system("pause>nul");
}


void menu() {
	clr(8);
	cout << "==============================  Welcome to our booking system ============================== code by \"Mahmoud Hamdy\"\n\n";
	clr(7);
	cout << "Please Select an option:-\n\n";
	clr(15);
	cout << "1-Reserve a ticket.\n\n";
	cout << "2-Cancel the reservation.\n\n";
	cout << "3-Check whether a specific car has available seat or not.\n\n";
	cout << "4-Check whether a specific seat is available or not.\n\n";
	cout << "5-Get the number of the available seats in a specific car.\n\n";
	cout << "6-Show all the seats status of a specific car.\n\n";
	clr(4);
	cout << "7-Exit.\n";
	clr(15);
}
void initial(cars car[])
{
	for (int i = 1; i <= 10; i++)
	{
		car[i].cid = i;
		for (int j = 1; j <= 30; j++)
		{
			car[i].seat[j].stid = j;
		}
	}
}


//car seat id function
void carinput(int& cid) {
	do {
		clr(11);
		cout << "Enter the Car's ID 1->10\n";
		clr(15);
		//input the car id...
		cin >> cid;
		//check wheather the input is true or not...
		if (cid > 10 || cid < 1)
		{
			system("cls");
			clr(4);
			cout << "\aInvaild Input,please try again...\n";
			clr(11);


		}
		else
			break;
	} while (1);
}
//input seat id function
void seatinput(int& sid) {
	do {
		clr(11);
		cout << "Enter the Seat's ID 1->30\n";
		clr(15);
		cin >> sid;
		//check wheather the input is true or not...
		if (sid > 30 || sid < 1) {
			system("cls");
			clr(4);
			cout << "\aInvaild Input,please try again..\n";
			clr(15);
		}
		else
			break;
	} while (1);
}

//Reserve a ticket
bool reserve(int carid, int seatid) {
	bool status = car[carid].seat[seatid].sts;
	if (!status) {
		car[carid].seat[seatid].sts = true;
		system("cls");
		clr(10);
		cout << "Your reservation made successfully, your seat in car " << carid << " Seat " << seatid << "\n";
		clr(15);
		car[carid].nfs--;
		if (car[carid].nfs == 0)
			car[carid].csts = false;
		return 1;
	}
	else {
		system("cls");
		clr(4);
		cout << "\aSorry, the seat you selected is already reserved, please choose another seat\n";
		clr(15);
		return 0;
	}
}


//Cancel the reservation
bool cancel(int carid, int seatid) {
	bool status = car[carid].seat[seatid].sts;
	if (status) {
		car[carid].seat[seatid].sts = false;
		clr(10);
		cout << "Your reservation Cancelled successfully\n";
		clr(15);
		system("pause");
		car[carid].nfs++;
		if (car[carid].nfs != 0)
			car[carid].csts = true;
		return 1;
	}
	else {
		system("cls");
		clr(4);
		cout << "\aSorry, the seat you selected isn't reserved before...\n";
		clr(13);
		cout << "Do you want to try again ?\nYes -> press 1\nNo  -> press 2\n";
		clr(15);
		int in;
		cin >> in;
		if (in == 1) {
			system("cls");
			return 0;
		}
		else {
			system("cls");
			return 1;
		}
	}
}

//Check whether a specific car has available seat or not.
bool car_availability(int carid) {
	if (car[carid].csts)
		return 1;
	return 0;
}

//Get the number of the available seats in a specific car
int numofseats(int carid) {
	return car[carid].nfs;
}

//Check whether a specific seat is available or not
bool seat_availability(int carid, int seatid) {
	bool s = car[carid].seat[seatid].sts;
	if (s == true)
		return 0;
	return 1;
}

//Show all the seats status of a specific car.
void car_status(int carid) {
	for (int j = 1; j <= 30; j++)
	{
		cout << setw(10) << "Seat " << car[carid].seat[j].stid;
		if (!car[carid].seat[j].sts) {
			clr(10);
			if (j < 10)
				cout << setw(21) << "Available\n";
			else
				cout << setw(20) << "Available\n";
			clr(15);
		}
		else {
			clr(4);
			if (j < 10)
				cout << setw(23) << "Not Available\n";
			else
				cout << setw(22) << "Not Available\n";
			clr(15);
		}
	}
}

//exit form 
void exit() {
	cout << "\n\n\n\n\n";
	clr(4);
	cout << setw(90) << ". . . . . . . . . . . . . . . . . . . . . . . . .\n";
	cout << setw(90) << ".                                               .\n";
	cout << setw(41) << ".";
	clr(5);
	cout << "       Thanks for using our application        ";
	clr(4);
	cout << ".\n";
	cout << setw(90) << ".                                               .\n";
	cout << setw(90) << ".                                               .\n";
	cout << setw(90) << ".                                               .\n";
	cout << setw(41) << ".";
	clr(1);
	cout << "             Mahmoud Hamdy Morsy               ";
	clr(4);
	cout << ".\n";
	cout << setw(41) << ".";
	clr(1);
	cout << "             -------------------               ";
	clr(4);
	cout << ".\n";
	cout << setw(90) << ".                                               .\n";
	cout << setw(90) << ".                                               .\n";
	cout << setw(90) << ".                                               .\n";
	cout << setw(41) << ".";
	clr(3);
	cout << "                  emails :                     ";
	clr(4);
	cout << ".\n";
	cout << setw(41) << ".";
	clr(11);
	cout << "           mahmoudhamdy@aun.edu.eg             ";
	clr(4);
	cout << ".\n";
	cout << setw(41) << ".";
	clr(11);
	cout << "           eng.ma7mod17@gmail.com              ";
	clr(4);
	cout << ".\n";
	cout << setw(90) << ".                                               .\n";
	cout << setw(90) << ".                                               .\n";
	cout << setw(41) << ".";
	clr(3);
	cout << "                   Phone :                     ";
	clr(4);
	cout << ".\n";
	cout << setw(41) << ".";
	clr(11);
	cout << "                201012776232                   ";
	clr(4);
	cout << ".\n";
	cout << setw(41) << ".";
	clr(11);
	cout << "                201274645006                   ";
	clr(4);
	cout << ".\n";
	cout << setw(90) << ".                                               .\n";
	cout << setw(90) << ". . . . . . . . . . . . . . . . . . . . . . . . .\n";
	clr(15);
	system("pause>nul");
}
