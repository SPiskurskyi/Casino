#include "Bar.h"

using std::cout;
using std::endl;
using std::setw;
using std::fstream;
using namespace std::chrono_literals;

namespace app {
    
    int Bar::drunkenness_ = 0;

    int Bar::GetDrunkenness()
    {
        return drunkenness_;
    }

    void Bar::ShowAsortement()
    {
        CLEAR_SCREEN;
        barFile_.open(path_ + ".txt", fstream::out | fstream::in | fstream::app);
        if (!barFile_.is_open()) {
            cout << "File don't find";
        }
        else {
            cout << setw(8) << "Name\t";
            cout << setw(8) << "\t     Price\t";
            cout << setw(8) << "   Avalible";
            cout << setw(8) << "           Id\t" << endl;
            while (!barFile_.eof())
            {
                barFile_ >> name_ >> price_ >> quantity_ >> id_;
                cout << setw(8) << name_ << '\t';
                cout << setw(8) << price_ << "$\t";
                cout << setw(8) << quantity_ << '\t';
                cout << setw(8) << id_ << '\t';
                cout << endl;
            }
            barFile_.close();
        }
    }
  
    bool Bar::MakeOrder(int id, Guest& obj)
    {
        barFile_.open(path_ + ".txt", fstream::out | fstream::in | fstream::app);
        if (!barFile_.is_open()) {
            cout << "File don't find";
            return false;
        }
        else {
            while (!barFile_.eof())
            {
                barFile_ >> name_ >> price_ >> quantity_ >> id_;
                if (id_ == id && quantity_ == 'V')
                {
                    if (price_ > obj.GetGuestCash())
                    {
                        barFile_.close();
                        cout << "Not enough money on the balance\n";
                        std::this_thread::sleep_for(2000ms);
                        return false;
                    }
                    else
                    {
                        obj.SetGuestCash(obj.GetGuestCash() - price_);
                        cout << "\"You drank a " << name_ << '\"' << endl;
                        create_phrase();
                        std::this_thread::sleep_for(2500ms);
                        barFile_.close();
                        drunkenness_++;
                        return true;
                    }
                }
            }
            barFile_.close();
            cout << "Item is not available\n";
            std::this_thread::sleep_for(2000ms);
            return false;
        }
    }

    void check_drunkenness(const Bar& obj, bool& shouldExit)
    {
        int choice;
        CLEAR_SCREEN;
        if (obj.GetDrunkenness() == 2)
        {
            cout << "Bartender: - Are you okay, maybe you better go home?\n";
            cout << "1->Sure\n2->Nope\n>";
            choice = get_choice(1, 2);
            if (choice == 1)
            {
                cout << "Ending..." << endl;
                std::this_thread::sleep_for(2000ms);
                shouldExit = true;
            }
            else if (choice == 2)
            {
                cout << "\nOkay....\n";
            }
        }
        if (obj.GetDrunkenness() == 3)
        {
            cout << "AGHHHHHHH\n";
            std::this_thread::sleep_for(2000ms);
            shouldExit = true;
        }
    }
}