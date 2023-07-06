#include "../headers/Bar.h"

int Bar::drunkenness = 0;

void Bar::ShowAsortement()
{
	CLEAR_SCREEN;
	BarFile.open(path + ".txt", fstream::out | fstream::in | fstream::app);
	if (!BarFile.is_open()) {
		cout << "File don't find";
	}
	else {
		cout << setw(8) << "Name\t";
		cout << setw(8) << "\t     Price\t";
		cout << setw(8) << "   Avalible";
		cout << setw(8) << "           Id\t" << endl;
		while (!BarFile.eof())
		{
			BarFile >> Name >> Price >> Quantity >> id;
			cout << setw(8) << Name << '\t';
			cout << setw(8) << Price << "$\t";
			cout << setw(8) << Quantity << '\t';
			cout << setw(8) << id << '\t';
			cout << endl;
		}
		BarFile.close();
	}
}
bool Bar::MakeOrder(int id, Guest& obj)
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
					std::this_thread::sleep_for(2000ms);
					/* Sleep(2000); */
					return false;
				}
				else
				{
					obj.cash -= Price;
					cout << "\"You drank a " << Name << '\"' << endl;
					create_phrase();
					std::this_thread::sleep_for(2500ms);
					/* Sleep(2500); */
					BarFile.close();
					drunkenness++;
					return true;
				}
			}
		}
		BarFile.close();
		cout << "Item is not available\n";
		std::this_thread::sleep_for(2000ms);
		/* Sleep(2000); */
		return false;
	}
}

void check_drunkenness()
{
	int choice;
	CLEAR_SCREEN;
	if (Bar::drunkenness == 4)
	{
		cout << "Are you okay, maybe you better go home?\n";
		cout << "1->Sure\n2->Nope\n>";
		choice = get_choice(1, 2);
		if (choice == 1)
		{
			cout << "Ending..." << endl;
			exit(EXIT_SUCCESS);
		}
		else if (choice == 2)
		{
			cout << "\nOkay....\n";
		}
	}
	if (Bar::drunkenness == 8)
	{
		cout << "AGHHHHHHH\n";
		exit(EXIT_SUCCESS);
	}
}
