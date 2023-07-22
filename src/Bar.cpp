#include "Bar.h"

namespace app {
    
    int Bar::drunkenness_ = 0;

    int Bar::GetDrunkenness()
    {
        return drunkenness_;
    }

    void Bar::ShowAsortement()
    {
        CLEAR_SCREEN;
        barFile_.open(path_ + ".txt", std::fstream::out | std::fstream::in | std::fstream::app);
        if (!barFile_.is_open()) {
            std::cout << "File don't find";
        }
        else {
            std::cout << std::setw(TAB_WIDTH) << "Name\t";
            std::cout << std::setw(TAB_WIDTH) << "\t     Price\t";
            std::cout << std::setw(TAB_WIDTH) << "   Avalible";
            std::cout << std::setw(TAB_WIDTH) << "           Id\t" << std::endl;
            while (!barFile_.eof())
            {
                barFile_ >> name_ >> price_ >> quantity_ >> id_;
                std::cout << std::setw(TAB_WIDTH) << name_ << '\t';
                std::cout << std::setw(TAB_WIDTH) << price_ << "$\t";
                std::cout << std::setw(TAB_WIDTH) << quantity_ << '\t';
                std::cout << std::setw(TAB_WIDTH) << id_ << '\t';
                std::cout << std::endl;
            }
            barFile_.close();
        }
    }
  
    bool Bar::MakeOrder(int id, Guest& obj)
    {
        barFile_.open(path_ + ".txt", std::fstream::out | std::fstream::in | std::fstream::app);
        if (!barFile_.is_open()) {
            std::cout << "File don't find";
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
                        std::cout << "Not enough money on the balance\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                        return false;
                    }
                    else
                    {
                        obj.SetGuestCash(obj.GetGuestCash() - price_);
                        std::cout << "\"You drank a " << name_ << '\"' << std::endl;
                        create_phrase();
                        std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                        barFile_.close();
                        drunkenness_++;
                        return true;
                    }
                }
            }
            barFile_.close();
            std::cout << "Item is not available\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            return false;
        }
    }

    void check_drunkenness(const Bar& obj, bool& shouldExit)
    {
        int choice;
        CLEAR_SCREEN;
        if (obj.GetDrunkenness() == 2)
        {
            std::cout << "Bartender: - Are you okay, maybe you better go home?\n";
            std::cout << "1->Sure\n2->Nope\n>";
            choice = get_choice(1, 2);
            if (choice == 1)
            {
                std::cout << "Ending..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                shouldExit = true;
            }
            else if (choice == 2)
            {
                std::cout << "\nOkay....\n";
            }
        }
        if (obj.GetDrunkenness() == 3)
        {
            std::cout << "AGHHHHHHH\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            shouldExit = true;
        }
    }
}