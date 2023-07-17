#include "Guest.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using namespace std::chrono_literals;

namespace app {

    void Guest::SetGuestName(string name)
    {
        name_ = name;
    }
    void Guest::SetGuestAge(int age)
    {
        age_ = age;
    }
    void Guest::SetGuestCash(int cash)
    {
        cash_ = cash;
    }
    string Guest::GetGuestName() const
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
        cout << "Guest name - \"" << name_ << "\"" << endl;
        cout << "Guest age - " << age_ << " y.o." << endl;
        cout << "Guest cash - " << cash_ << "$" << endl;
        cout << "Guest tokens - " << tokens_ << endl;
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
            if (!(cash_ == 0))
            {
                cout << "\tAvailable cash - " << cash_ << "$" << endl;
                cout << "How many tokens do you want to buy?" << "\n>";
                choice = get_choice(1, cash_);
                tokens_ += choice;
                cash_ -= choice;
                cout << "Success\n";
                std::this_thread::sleep_for(1000ms);
                break;
            }
            else
            {
                cout << "You have no cash!" << endl;
                std::this_thread::sleep_for(1000ms);
                break;
            }
        case 2:
            CLEAR_SCREEN;
            if (!(tokens_ == 0))
            {
                cout << "\tAvailable tokens - " << tokens_ << endl;
                cout << "How many cash do you want to buy?" << "\n>";
                cin >> choice;
                while (choice <= 0 || choice > tokens_)
                {
                    cout << "Ooops, something is wrong, try again!\n>";
                    cin >> choice;
                }
                cash_ += choice;
                tokens_ -= choice;
                cout << "Success\n";
                std::this_thread::sleep_for(1000ms);
                break;
            }
            else
            {
                cout << "You have no tokens!" << endl;
                std::this_thread::sleep_for(1000ms);
                break;
            }
        }
    }
    Guest& Guest::Placebet()
    {
        CLEAR_SCREEN;
        if (!(tokens_ == 0))
        {
            cout << "-----------------------------------------------------------------------------------------------------" << endl;
            for (int i = 0; i < 37; i++)
            {
                if (i == 0)
                {
                    cout << '-';
                    cout << i;
                }
                else if (i == 1)
                {
                    cout << '-';
                    cout << i;
                }
                else if (i % 2 == 0)
                {
                    cout << '-';
                    cout << i;
                }
                else if (i % 2 == 1)
                {
                    cout << '-';
                    cout << i;
                }
            }
            cout << "\n-----------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\tGreen is zero\n";
            cout << "\t\t\t\t\tRed are odd numbers\n";
            cout << "\t\t\t\t\tBlack are even numbers\n";
            cout << "\n\t\t\t\t\tYour tokens - " << tokens_;
            cout << "\nHow many tokens do you want to bet?\n>";
            int bet = get_choice(1, tokens_);
            tokens_ -= bet;
            cout << "Okay. Now choose the winning color\n";
            cout << "1->Black (2x)\n";
            cout << "2->Red (2x)\n";
            cout << "3->Green (16x)\n>";
            int choice = get_choice(1, 3);
            int winlot = rand() % 37;
            if (winlot == 0)
            {
                cout << "\n\t\t\t\tWinning lot - ";
                cout << winlot << " GREEN " << endl;
            }
            else if (winlot % 2 == 1)
            {
                cout << "\n\t\t\t\tWinning lot - ";
                cout << winlot << " RED " << endl;
            }
            else if (winlot % 2 == 0)
            {
                cout << "\n\t\t\t\tWinning lot - ";
                cout << winlot << " BLACK " << endl;
            }
            switch (choice)
            {
            case 1:
                if (winlot % 2 == 0)
                {
                    cout << "YOU WON - " << bet * 2 << " TOKENS!\n\n";
                    tokens_ = tokens_ + bet * 2;
                }
                else cout << "You lost " << bet << " tokens :(\n\n";
                std::this_thread::sleep_for(3500ms);
                break;
            case 2:
                if (winlot % 2 == 1)
                {
                    cout << "YOU WON - " << bet * 2 << " TOKENS!\n\n";
                    tokens_ = tokens_ + bet * 2;
                }
                else cout << "You lost " << bet << " tokens :(\n\n";
                std::this_thread::sleep_for(3500ms);
                break;
            case 3:
                if (winlot == 0)
                {
                    cout << "JACKPOTT!! YOU WON - " << bet * 16 << " TOKENS!!!\n\n";
                    tokens_ = tokens_ + bet * 16;
                }
                else cout << "You lost " << bet << " tokens :(\n\n";
                std::this_thread::sleep_for(3500ms);
                break;
            }
            return *this;
        }
        else
        {
            cout << "Please exchange your cash for tokens to start playing!\n" << endl;
            std::this_thread::sleep_for(1500ms);
            return *this;
        }
    }
}
