#include "../headers/funcs.h"

string tempstring;


void print_mainmenu()
{
	system("cls");
	cout << "--MAIN MENU--" << endl;
	cout << "1-> Guest menu" << endl;
	cout << "2-> Exit program" << endl;
	cout << '>';
}
void print_guestmenu(const string& GuestName)
{
	system("cls");
	cout << "--GUEST MENU--" << endl;
	cout << "1-> Check \"" << GuestName << "\" status" << endl;
	cout << "2-> Go to the casino" << endl;
	cout << "3-> Go back to main menu" << endl;
	cout << '>';
}
void print_casinomenu()
{
	system("cls");
	cout << "--CASINO MENU--" << endl;
	cout << "1-> Exchanger" << endl;
	cout << "2-> Place a bet" << endl;
	cout << "3-> Go to the bar" << endl;
	cout << "4-> Leave the casino" << endl;
	cout << '>';
}
int get_choice(const int a1, const int a2)
{
	int choice;
	string s;
	getline(cin, s);
	while (sscanf_s(s.c_str(), "%d", &choice) != 1 || choice < a1 || choice > a2)
	{
		cout << "Incorrect input. Try again\n>";
		getline(cin, s);
	}
	return choice;
}
int get_choice()
{
	int choice;
	string s;
	getline(cin, s);
	while (sscanf_s(s.c_str(), "%d", &choice) != 1 || choice < 8 || choice > 80)
	{
		cout << "Wrong Age, try again please (8-80)\n>";
		getline(cin, s);
	}
	return choice;
}
int get_cash()
{
	int choice;
	string s;
	getline(cin, s);
	while (sscanf_s(s.c_str(), "%d", &choice) != 1 || choice < 1)
	{
		cout << "Wrong cash value, try again please (minimum 1$)\n>";
		getline(cin, s);
	}
	return choice;
}
void create_guest(Guest& other)
{
	other.age = (rand() % 72) + 8;
	other.cash = rand() % 1000;
	int a = rand() % 5;
	switch (a)
	{
	case 0:
		other.name = "Mostavchuk Petro";
		break;
	case 1:
		other.name = "Billy Herrington";
		break;
	case 2:
		other.name = "Volodymyr Zelenskyy";
		break;
	case 3:
		other.name = "Joe Biden";
		break;
	case 4:
		other.name = "Lionel Messi";
		break;
	}
}
void create_phrase()
{
	int a = rand() % 5;
	switch (a)
	{
	case 0:
		cout << "What a good drink!\n";
		break;
	case 1:
		cout << "Nice one!\n";
		break;
	case 2:
		cout << "Cheers!\n";
		break;
	case 3:
		cout << "Bartender i love you\n";
		break;
	case 4:
		cout << "One more!\n";
		break;
	}
}


