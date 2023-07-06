#include "../headers/Guest.h"



void Guest::SetGuestName(string name)
{
	this->name = name;
}
void Guest::SetGuestAge(int age)
{
	this->age = age;
}
void Guest::SetGuestCash(int cash)
{
	this->cash = cash;
}
string Guest::GetGuestName()
{
	return this->name;
}
int Guest::GetGuestAge()
{
	return this->age;
}
int Guest::GetGuestCash()
{
	return this->cash;
}
int Guest::GetGuestTokens()
{
	return this->tokens;
}
void Guest::CheckStatus()
{
	cout << "Guest name - \"" << this->name << "\"" << endl;
	cout << "Guest age - " << this->age << " y.o." << endl;
	cout << "Guest cash - " << this->cash << "$" << endl;
	cout << "Guest tokens - " << this->tokens << endl;
}
void Guest::Exchanger()
{
	int choice;
	CLEAR_SCREEN;
	cout << "What kind of exchange are you interested in?\n";
	cout << "1->Cash->tokens\n";
	cout << "2->Tokens->cash\n";
	choice = get_choice(1, 2);
	switch (choice)
	{
	case 1:
		CLEAR_SCREEN;
		if (!(this->cash == 0))
		{
			cout << "\tAvailable cash - " << this->cash << "$" << endl;
			cout << "How many tokens do you want to buy?" << "\n>";
			cin >> choice;
			while (choice <= 0 || choice > this->cash)
			{
				cout << "Ooops, something is wrong, try again!\n>";
				cin >> choice;
			}
			this->tokens += choice;
			this->cash -= choice;
			cout << "Success\n";
			std::this_thread::sleep_for(1000ms);
			/* Sleep(1000); */
			break;
		}
		else
		{
			cout << "You have no cash!" << endl;
			std::this_thread::sleep_for(1000ms);
			/* Sleep(1000); */
			break;
		}
	case 2:
		CLEAR_SCREEN;
		if (!(this->tokens == 0))
		{
			cout << "\tAvailable tokens - " << this->tokens << endl;
			cout << "How many cash do you want to buy?" << "\n>";
			cin >> choice;
			while (choice <= 0 || choice > this->tokens)
			{
				cout << "Ooops, something is wrong, try again!\n>";
				cin >> choice;
			}
			this->cash += choice;
			this->tokens -= choice;
			cout << "Success\n";
			std::this_thread::sleep_for(1000ms);
			/* Sleep(1000); */
			break;
		}
		else
		{
			cout << "You have no tokens!" << endl;
			std::this_thread::sleep_for(1000ms);
			/* Sleep(1000); */
			break;
		}
	}
}
Guest& Guest::Placebet()
{
	CLEAR_SCREEN;
	if (!(this->tokens == 0))
	{
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		/* HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); */
		/* SetConsoleTextAttribute(console, 7); */
		for (int i = 0; i < 37; i++)
		{
			if (i == 0)
			{
				cout << '-';
				/* SetConsoleTextAttribute(console, 10); //green */
				cout << i;
				/* SetConsoleTextAttribute(console, 7); */
			}
			else if (i == 1)
			{
				cout << '-';
				/* SetConsoleTextAttribute(console, 12); //red */
				cout << i;
				/* SetConsoleTextAttribute(console, 7); */
			}
			else if (i % 2 == 0)
			{
				cout << '-';
				/* SetConsoleTextAttribute(console, 8); //black */
				cout << i;
				/* SetConsoleTextAttribute(console, 7); */
			}
			else if (i % 2 == 1)
			{
				cout << '-';
				/* SetConsoleTextAttribute(console, 12); //red */
				cout << i;
				/* SetConsoleTextAttribute(console, 7); */
			}
		}
		cout << "\n-----------------------------------------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\tYour tokenks - " << this->tokens;
		cout << "\nHow many tokens do you want to bet?\n>";
		int bet = get_choice(1, this->tokens);
		this->tokens -= bet;
		cout << "Okay. Now choose the winning color\n";
		cout << "1->Black (2x)\n";
		cout << "2->Red (2x)\n";
		cout << "3->Green (16x)\n>";
		int choice = get_choice(1, 3);
		int winlot = rand() % 37;
		if (winlot == 0)
		{
			cout << "\n\t\t\t\tWinning lot - ";
			/* SetConsoleTextAttribute(console, 10); */
			cout << winlot << " GREEN " << endl;
			/* SetConsoleTextAttribute(console, 7); */
		}
		else if (winlot % 2 == 1)
		{
			cout << "\n\t\t\t\tWinning lot - ";
			/* SetConsoleTextAttribute(console, 12); */
			cout << winlot << " RED " << endl;
			/* SetConsoleTextAttribute(console, 7); */
		}
		else if (winlot % 2 == 0)
		{
			cout << "\n\t\t\t\tWinning lot - ";
			/* SetConsoleTextAttribute(console, 8); */
			cout << winlot << " BLACK " << endl;
			/* SetConsoleTextAttribute(console, 7); */
		}
		switch (choice)
		{
		case 1:
			if (winlot % 2 == 0)
			{
				cout << "YOU WON - " << bet * 2 << " TOKENS!\n\n";
				this->tokens = this->tokens + bet * 2;
			}
			else cout << "You lost " << bet << " tokens :(\n\n";
			std::this_thread::sleep_for(3500ms);
			/* Sleep(3500); */
			break;
		case 2:
			if (winlot % 2 == 1)
			{
				cout << "YOU WON - " << bet * 2 << " TOKENS!\n\n";
				this->tokens = this->tokens + bet * 2;
			}
			else cout << "You lost " << bet << " tokens :(\n\n";
			std::this_thread::sleep_for(3500ms);
			/* Sleep(3500); */
			break;
		case 3:
			if (winlot == 0)
			{
				cout << "JACKPOTT!! YOU WON - " << bet * 16 << " TOKENS!!!\n\n";
				this->tokens = this->tokens + bet * 16;
			}
			else cout << "You lost " << bet << " tokens :(\n\n";
			std::this_thread::sleep_for(3500ms);
			/* Sleep(3500); */
			break;
		}

		system("pause");
		return *this;
	}
	else
	{
		cout << "Please exchange your cash for tokens to start playing!\n" << endl;
		std::this_thread::sleep_for(1500ms);
		/* Sleep(1500); */
	}
}
