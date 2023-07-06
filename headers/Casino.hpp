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
    srand(time(NULL));

    while (true)
    {
        print_mainmenu();
        int mainChoice = get_choice(1, 2);

        if (mainChoice == 1)
        {
            Guest guest;
            create_guest_menu(guest);

            while (true)
            {
                print_guestmenu(guest.GetGuestName());
                int guestChoice = get_choice(1, 3);

                if (guestChoice == 1)
                {
                    CLEAR_SCREEN;
                    guest.CheckStatus();
                    cout << "Press \"Enter\" to continue\n>";
                    getchar();
                }
                else if (guestChoice == 2)
                {
                    if (guest.GetGuestAge() < 18)
                    {
                        CLEAR_SCREEN;
                        cout << "You are still too young to gamble. Are you sure you want to continue?\n1-> Yes\n2-> No\n>";
                        int ageChoice = get_choice(1, 2);

                        if (ageChoice == 2)
                        {
                            cout << "Bye, Bye\n";
                            std::this_thread::sleep_for(500ms);
                            break;
                        }

                        std::this_thread::sleep_for(500ms);
                    }

                    print_welcome();
                    std::this_thread::sleep_for(1500ms);

                    Bar bar;
                    while (true)
                    {
                        check_drunkenness();
                        print_casinomenu();
                        int casinoChoice = get_choice(1, 4);

                        if (casinoChoice == 1)
                        {
                            guest.Exchanger();
                            getchar();
                        }
                        else if (casinoChoice == 2)
                        {
                            guest.Placebet();
                        }
                        else if (casinoChoice == 3)
                        {
                            if (guest.GetGuestAge() < 18)
                            {
                                CLEAR_SCREEN;
                                cout << "Unfortunately, the bar is only available for adults\n";
                                std::this_thread::sleep_for(2000ms);
                            }
                            else
                            {
                                bar.ShowAsortement();
                                cout << "\t\t\tBalance - " << guest.GetGuestCash() << endl;
                                cout << "Choose any id of the drink that interests you\n>";
                                int drinkId = get_choice(1, 8);
                                bar.MakeOrder(drinkId, guest);
                            }
                        }
                        else if (casinoChoice == 4)
                        {
                            CLEAR_SCREEN;
                            cout << "Leaving..." << endl;
                            std::this_thread::sleep_for(300ms);
                            break;
                        }
                    }
                }
                else if (guestChoice == 3)
                {
                    break;
                }
            }
        }
        else if (mainChoice == 2)
        {
            cout << "Ending..." << endl;
            exit(EXIT_SUCCESS);
        }
    }
}

#endif

