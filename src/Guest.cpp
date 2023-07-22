#include "Guest.h"

namespace app {

    void Guest::SetGuestName(std::string name)
    {
        name_ = std::move(name);
    }
    void Guest::SetGuestAge(int age)
    {
        age_ = age;
    }
    void Guest::SetGuestCash(int cash)
    {
        cash_ = cash;
    }
    std::string Guest::GetGuestName() const
    {
        return name_;
    }
    int Guest::GetGuestAge() const
    {
        return age_;
    }
    int Guest::GetGuestCash() const
    {
        return cash_;
    }
    int Guest::GetGuestTokens() const
    {
        return tokens_;
    }
    void Guest::CheckStatus() const
    {
        std::cout << "Guest name - \"" << name_ << "\"" << std::endl;
        std::cout << "Guest age - " << age_ << " y.o." << std::endl;
        std::cout << "Guest cash - " << cash_ << "$" << std::endl;
        std::cout << "Guest tokens - " << tokens_ << std::endl;
    }
    void Guest::Exchanger()
    {
        int choice;
        CLEAR_SCREEN;
        std::cout << "What kind of exchange are you interested in?\n";
        std::cout << "1->Cash->tokens\n";
        std::cout << "2->Tokens->cash\n";
        choice = get_choice(1, EXCHANGER_CHOICE);
        switch (choice)
        {
        case 1:
            CLEAR_SCREEN;
            if (!(cash_ == 0))
            {
                std::cout << "\tAvailable cash - " << cash_ << "$" << std::endl;
                std::cout << "How many tokens do you want to buy?" << "\n>";
                choice = get_choice(1, cash_);
                tokens_ += choice;
                cash_ -= choice;
                std::cout << "Success\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                break;
            }
            else
            {
                std::cout << "You have no cash!" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                break;
            }
        case 2:
            CLEAR_SCREEN;
            if (!(tokens_ == 0))
            {
                std::cout << "\tAvailable tokens - " << tokens_ << std::endl;
                std::cout << "How many cash do you want to buy?" << "\n>";
                std::cin >> choice;
                while (choice <= 0 || choice > tokens_)
                {
                    std::cout << "Ooops, something is wrong, try again!\n>";
                    std::cin >> choice;
                }
                cash_ += choice;
                tokens_ -= choice;
                std::cout << "Success\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                break;
            }
            else
            {
                std::cout << "You have no tokens!" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                break;
            }
        }
    }
    Guest& Guest::Placebet()
    {
        CLEAR_SCREEN;
        if (!(tokens_ == 0))
        {
            std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < ROULETTE_COUNT; i++){
                std::cout << '-';
                std::cout << i;
            }
            std::cout << "\n-----------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "\t\t\t\t\tGreen is zero\n";
            std::cout << "\t\t\t\t\tRed are odd numbers\n";
            std::cout << "\t\t\t\t\tBlack are even numbers\n";
            std::cout << "\n\t\t\t\t\tYour tokens - " << tokens_;
            std::cout << "\nHow many tokens do you want to bet?\n>";
            int bet = get_choice(1, tokens_);
            tokens_ -= bet;
            std::cout << "Okay. Now choose the winning color\n";
            std::cout << "1->Black (2x)\n";
            std::cout << "2->Red (2x)\n";
            std::cout << "3->Green (16x)\n>";
            int choice = get_choice(1, BET_CHOICE);
            int winlot = rand() % ROULETTE_COUNT;
            if (winlot == 0)
            {
                std::cout << "\n\t\t\t\tWinning lot - ";
                std::cout << winlot << " GREEN " << std::endl;
            }
            else if (winlot % 2 == 1)
            {
                std::cout << "\n\t\t\t\tWinning lot - ";
                std::cout << winlot << " RED " << std::endl;
            }
            else if (winlot % 2 == 0)
            {
                std::cout << "\n\t\t\t\tWinning lot - ";
                std::cout << winlot << " BLACK " << std::endl;
            }
            switch (choice)
            {
            case 1:
                if (winlot % 2 == 0)
                {
                    std::cout << "YOU WON - " << bet * RED_AND_BLACK_MULTIPLIER << " TOKENS!\n\n";
                    tokens_ = tokens_ + bet * RED_AND_BLACK_MULTIPLIER;
                }
                else std::cout << "You lost " << bet << " tokens :(\n\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(3500));
                break;
            case 2:
                if (winlot % 2 == 1)
                {
                    std::cout << "YOU WON - " << bet * RED_AND_BLACK_MULTIPLIER << " TOKENS!\n\n";
                    tokens_ = tokens_ + bet * RED_AND_BLACK_MULTIPLIER;
                }
                else std::cout << "You lost " << bet << " tokens :(\n\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(3500));
                break;
            case 3:
                if (winlot == 0)
                {
                    std::cout << "JACKPOTT!! YOU WON - " << bet * GREEN_MULTIPLIER << " TOKENS!!!\n\n";
                    tokens_ = tokens_ + bet * GREEN_MULTIPLIER;
                }
                else std::cout << "You lost " << bet << " tokens :(\n\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(3500));
                break;
            }
            return *this;
        }
        else
        {
            std::cout << "Please exchange your cash for tokens to start playing!\n" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            return *this;
        }
    }
}
