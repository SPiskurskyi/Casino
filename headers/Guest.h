#ifndef GUEST
#define GUEST

#include <iostream>
#include <windows.h>
#include <string>
#include <limits>
#include <ctime>
#include <iomanip>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;
using std::fstream;

int get_choice(const int a1,const int a2);


class Guest
{
	friend class Bar;
public:
	Guest();
	void SetGuestName(string name);
	void SetGuestAge(int age);
	void SetGuestCash(int cash);
	string GetGuestName();
	int GetGuestAge();
	int GetGuestCash();
	int GetGuestTokens();
	void CheckStatus();
	friend void create_guest(Guest& other);
	void Exchanger();
	Guest& Placebet();
private:
	string name;
	int age = 0;
	int cash = 0;
	int tokens = 0;
};
/////////////////////////////////////////////////////////////////////////

inline Guest::Guest()
{
}
#endif