#ifndef BAR
#define BAR

void create_phrase();

class Bar
{
private:
	fstream BarFile;
	string Name;
	int Price;
	int id;
	char Quantity;
	string path = "assortment";
public:
	bool MakeOrder(int id,Guest& obj);
	void ShowAsortement();
	static int drunkenness;
};
 int Bar::drunkenness = 0;
 /////////////////////////////////////////////////////////////////////////

void Bar::ShowAsortement()
{
	system("cls");
	BarFile.open(path + ".txt", fstream::out | fstream::in | fstream::app);
	if (!BarFile.is_open()) {
		cout << "File don't find";
	}
	else {
		cout << setw(8) <<"Name\t";
		cout << setw(8) <<"\t     Price\t";
		cout << setw(8) <<"   Avalible";
		cout << setw(8) <<"           Id\t" << endl;
		while (!BarFile.eof())
		{
			BarFile >> Name >> Price >> Quantity >> id;
			cout << setw(8) << Name << '\t';
			cout  << setw(8) << Price << "$\t";
			cout  << setw(8) << Quantity << '\t';
			cout  << setw(8) << id << '\t';
			cout << endl;
		}
		BarFile.close();
	}
}
bool Bar::MakeOrder(int id, Guest & obj)
{
	BarFile.open(path + ".txt", fstream::out | fstream::in | fstream::app);
	if (!BarFile.is_open()) {
		cout << "File don't find";
	}
	else {
		while (!BarFile.eof())
		{
			BarFile >> Name >> Price >> Quantity >> this->id;
			if (this->id == id && Quantity == 'V')
			{
				if (Price > obj.cash)
				{
					BarFile.close();
					cout << "Not enough money on the balance\n";
					Sleep(2000);
					return false;
				}
				else 
				{
					obj.cash -= Price;
					cout << "\"You drank a " << Name << '\"' << endl;
					create_phrase();
					Sleep(2500);
					BarFile.close();
					drunkenness++;
					return true;
				}
			}
		}
		BarFile.close();
		cout << "Item is not available\n";
		Sleep(2000);
		return false;
	}
}
#endif