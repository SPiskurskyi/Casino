#ifndef CASINO
#define CASINO

#include <iostream>
#include <string>

class Casino 
{
private:
	std::string casinoname = "Diamond Casino";
public:
	void Welcome();
};
/////////////////////////////////////////////////////////////////////////

void Casino::Welcome()
{
	system("cls");
	std::cout << "\n\t\t\t\t+----------------------------+";
	std::cout << "\n\t\t\t\t|Welcome in \"" << casinoname << "\"!|";
	std::cout << "\n\t\t\t\t+----------------------------+\n";
}
#endif
