#include "Funcs.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


namespace app {

    void print_mainmenu()
    {
        CLEAR_SCREEN;
        cout << "--MAIN MENU--" << endl;
        cout << "1-> Guest menu" << endl;
        cout << "2-> Exit program" << endl;
        cout << '>';
    }
    void print_guestmenu(const string& GuestName)
    {
        CLEAR_SCREEN;
        cout << "--GUEST MENU--" << endl;
        cout << "1-> Check \"" << GuestName << "\" status" << endl;
        cout << "2-> Go to the casino" << endl;
        cout << "3-> Go back to main menu" << endl;
        cout << '>';
    }
    void print_casinomenu()
    {
        CLEAR_SCREEN;
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
        std::string input;

        while (true)
        {
            std::getline(std::cin, input);

            std::istringstream iss(input);
            if (iss >> choice && choice >= a1 && choice <= a2)
            {
                std::cin.clear();
                break;
            }

            std::cout << "Incorrect input. Try again." << std::endl;
            std::cin.clear();
        }

        return choice;
    }
   
    void create_guest(Guest& other)
    {
        other.SetGuestAge((rand() % 72) + 8);
        other.SetGuestCash(rand() % 1000);
        int a = rand() % 5;
        switch (a)
        {
        case 0:
            other.SetGuestName("Mostavchuk Petro");
            break;
        case 1:
            other.SetGuestName("Billy Herrington");
            break;
        case 2:
            other.SetGuestName("Volodymyr Zelenskyy");
            break;
        case 3:
            other.SetGuestName("Joe Biden");
            break;
        case 4:
            other.SetGuestName("Lionel Messi");
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
    void print_welcome()
    {
        CLEAR_SCREEN;
        std::cout << "\n\t\t\t\t+----------------------------+";
        std::cout << "\n\t\t\t\t|\tWelcome in Casino!   |";
        std::cout << "\n\t\t\t\t+----------------------------+\n";
    }

    void create_guest_menu(Guest& guest)
    {
        CLEAR_SCREEN;
        cout << "Create guest:\n1->Manually\n2->Randomize\n>";
        int choice = get_choice(1, 2);

        switch (choice)
        {
        case 1: 
        {
            CLEAR_SCREEN;
            cout << "Enter Guest's name -> ";
            std::string tempname;
            getline(cin, tempname);
            cout << "\nEnter Guest's age(8-80 REQUIRED) -> ";
            int tempage = get_choice(8,80);
            cout << "\nEnter Guest's cash -> ";
            int tempcash = get_choice(1,999999999);
            guest.SetGuestName(tempname);
            guest.SetGuestAge(tempage);
            guest.SetGuestCash(tempcash);
            break;
        }
        case 2:
        {
            create_guest(guest);
            break;
        }
        }
    }
}