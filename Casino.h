using namespace std;
#ifndef CASINO
#define CASINO
class Casino 
{
private:
	string casinoname = "Diamond Casino";
public:
	void Welcome();
};
/////////////////////////////////////////////////////////////////////////

void Casino::Welcome()
{
	system("cls");
	cout << "\n\t\t\t\t+----------------------------+";
	cout << "\n\t\t\t\t|Welcome in \"" << casinoname << "\"!|";
	cout << "\n\t\t\t\t+----------------------------+\n";
}
#endif
