#include "Casino.h"


namespace app {

    void Casino::setup()
    {
        bool shouldExit = false;
        srand(static_cast<unsigned int>(time(nullptr)));

        while (!shouldExit)
        {
            print_mainmenu();
            int mainChoice = get_choice(1, MAIN_CHOICE);
            switch (mainChoice) {
            case 1:
            {
                Guest guest;
                create_guest_menu(guest);

                while (!shouldExit)
                {
                    print_guestmenu(guest.GetGuestName());
                    int guestChoice = get_choice(1, GUEST_CHOICE);
                    switch (guestChoice) {
                    case 1:
                        CLEAR_SCREEN;
                        guest.CheckStatus();
                        system("pause");
                        continue;
                    case 2:
                    {
                        if (guest.GetGuestAge() < MIN_AGE)
                        {
                            CLEAR_SCREEN;
                            std::cout << "You are still too young to gamble. Are you sure you want to continue?\n1-> Yes\n2-> No\n>";
                            int ageChoice = get_choice(1, AGE_CHOICE);
                            if (ageChoice == 2)
                            {
                                std::cout << "Bye, Bye\n";
                                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                                break;
                            }
                            std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        }
                        print_welcome();
                        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                        Bar bar;
                        while (!shouldExit)
                        {
                            check_drunkenness(bar, shouldExit);
                            if (shouldExit) {
                                break;
                            }
                            print_casinomenu();
                            int casinoChoice = get_choice(1, CASINO_CHOICE);
                            switch (casinoChoice) {
                            case 1:
                                guest.Exchanger();
                                continue;
                            case 2:
                                guest.Placebet();
                                continue;
                            case 3:
                                if (guest.GetGuestAge() < MIN_AGE)
                                {
                                    CLEAR_SCREEN;
                                    std::cout << "Unfortunately, the bar is only available for adults\n";
                                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                                }
                                else
                                {
                                    bar.ShowAsortement();
                                    std::cout << "\t\t\tBalance - " << guest.GetGuestCash() << std::endl;
                                    std::cout << "Choose any id of the drink that interests you\n>";
                                    int drinkId = get_choice(1, DRINK_CHOICE);
                                    bar.MakeOrder(drinkId, guest);
                                }
                                continue;
                            case 4:
                                CLEAR_SCREEN;
                            }
                            break;
                        }
                        continue;
                    }
                    case 3:
                        CLEAR_SCREEN;
                    }
                    break;
                }
            }
            continue;
            case 2:
                std::cout << "Ending..." << std::endl;
            }
            break;
        }
    }
}