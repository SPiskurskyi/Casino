#ifndef CASINO
#define CASINO

#include "../headers/Funcs.h"

class Casino {
private:
    string Name;
public:
    Casino(string name) : Name(name) {};
    void setup();
};


void Casino::setup()
{

    // variables
    Guest g;
    Bar b;
    int choice;
    string tempname;
    string tempstring;
    int tempage;
    int tempcash;
    char tempchar;
    int tempid;
    srand(time(NULL));
    do

    {
    MainMenu:
        print_mainmenu();
        choice = get_choice(1, 2);
        switch (choice)
        {
        case 1: //Creating guest menu
            system("cls");
            cout << "Create guest:\n" << "1->Manually " << endl << "2->Randomize \n>";
            choice = get_choice(1, 2);
            switch (choice)
            {
            case 1: //Manual create
                system("cls");
                cout << "Enter Guest`s name -> ";
                getline(cin, tempname);
                cout << "\nEnter Guest`s age -> ";
                tempage = get_choice();
                cout << "\nEnter Guest`s cash -> ";
                tempcash = get_cash();
                g.SetGuestName(tempname);
                g.SetGuestAge(tempage);
                g.SetGuestCash(tempcash);
                break;
            case 2: //random create
                create_guest(g);
                break;
            }
        GuestMenu:
            print_guestmenu(g.GetGuestName());
            choice = get_choice(1, 3);
            switch (choice)
            {
            case 1: //Status check case
                system("cls");
                g.CheckStatus();
                cout << "Press \"Enter\" to continue\n>";
                tempchar = getchar();
                goto GuestMenu;
            case 2:  //Casino entering case
                system("cls");
                if (g.GetGuestAge() < 18)
                {
                    cout << "You are still too young to gamble. Are you sure you want to continue?\n1-> Yes\n2-> No\n>";
                    choice = get_choice(1, 2);
                    if (choice == 2)
                    {
                        cout << "Bye, Bye\n";
                        Sleep(1500);
                        goto MainMenu;
                    }
                    else Sleep(500);
                }
                print_welcome();
                Sleep(1500);
            CasinoMenu:
                check_drunkenness();
                print_casinomenu();
                choice = get_choice(1, 4);
                switch (choice)
                {
                case 1: // Exchanger case
                    g.Exchanger();
                    tempchar = getchar();
                    goto CasinoMenu;
                case 2: //Betting case
                    g.Placebet();
                    goto CasinoMenu;
                case 3: //Bar case
                    if (g.GetGuestAge() < 18)
                    {
                        system("cls");
                        cout << "Unfortunately, the bar is only available for adults\n";
                        Sleep(2000);
                        goto CasinoMenu;
                    }
                    else
                    {
                        b.ShowAsortement();
                        cout << "\t\t\tBalance - " << g.GetGuestCash() << endl;
                        cout << "Choose any id of the drink that interests you\n>";
                        tempid = get_choice(1, 8);
                        b.MakeOrder(tempid, g);
                        goto CasinoMenu;
                    }
                case 4: //Leave casino case
                    system("cls");
                    cout << "Leaving..." << endl;
                    Sleep(1000);
                    goto GuestMenu;
                }
            case 3:
                goto MainMenu;
            }
        case 2:
            cout << "Ending..." << endl;
            exit(EXIT_SUCCESS);
        }
    } while (true);
}

#endif
