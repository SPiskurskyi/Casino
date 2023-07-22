#include "Funcs.h"

namespace app {

    void print_mainmenu()
    {
        CLEAR_SCREEN;
        std::cout << "--MAIN MENU--" << std::endl;
        std::cout << "1-> Guest menu" << std::endl;
        std::cout << "2-> Exit program" << std::endl;
        std::cout << '>';
    }
    void print_guestmenu(const std::string& GuestName)
    {
        CLEAR_SCREEN;
        std::cout << "--GUEST MENU--" << std::endl;
        std::cout << "1-> Check \"" << GuestName << "\" status" << std::endl;
        std::cout << "2-> Go to the casino" << std::endl;
        std::cout << "3-> Go back to main menu" << std::endl;
        std::cout << '>';
    }
    void print_casinomenu()
    {
        CLEAR_SCREEN;
        std::cout << "--CASINO MENU--" << std::endl;
        std::cout << "1-> Exchanger" << std::endl;
        std::cout << "2-> Place a bet" << std::endl;
        std::cout << "3-> Go to the bar" << std::endl;
        std::cout << "4-> Leave the casino" << std::endl;
        std::cout << '>';
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
        other.SetGuestAge((rand() % AGE_GENERATOR) + MIN_AGE_REQUIRED);
        other.SetGuestCash(rand() % CASH_GENERATOR);
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
            std::cout << "What a good drink!\n";
            break;
        case 1:
            std::cout << "Nice one!\n";
            break;
        case 2:
            std::cout << "Cheers!\n";
            break;
        case 3:
            std::cout << "Bartender i love you\n";
            break;
        case 4:
            std::cout << "One more!\n";
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
        std::cout << "Create guest:\n1->Manually\n2->Randomize\n>";
        int choice = get_choice(1, 2);

        switch (choice)
        {
        case 1: 
        {
            CLEAR_SCREEN;
            std::cout << "Enter Guest's name -> ";
            std::string tempname;
            getline(std::cin, tempname);
            std::cout << "\nEnter Guest's age(" << MIN_AGE_REQUIRED  << "-" << AGE_GENERATOR + MIN_AGE_REQUIRED << " REQUIRED) -> ";
            int tempage = get_choice(MIN_AGE_REQUIRED,AGE_GENERATOR + MIN_AGE_REQUIRED);
            std::cout << "\nEnter Guest's cash -> ";
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