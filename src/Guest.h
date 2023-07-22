#pragma once

#ifdef __linux__ 
//linux code goes here
#define CLEAR_SCREEN system("clear");

#elif _WIN32
// windows code goes here
#define CLEAR_SCREEN system("cls");
#define SSCANF sscanf_s 

#endif


#include <iostream>
#include <thread>
#include <string>
#include <limits>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Constants.h"

namespace app {

    int get_choice(const int a1, const int a2);

    class Guest
    {
    public:
        Guest() = default;
        void SetGuestName(std::string name);
        void SetGuestAge(int age);
        void SetGuestCash(int cash);
        std::string GetGuestName() const;
        int GetGuestAge() const;
        int GetGuestCash() const;
        int GetGuestTokens() const;
        void CheckStatus() const;
        void Exchanger();
        Guest& Placebet();
    private:
        std::string name_;
        int age_ = 0;
        int cash_ = 0;
        int tokens_ = 0;
    };

}