#pragma once

#include "Bar.h"

namespace app {

    int get_choice(int a1, int a2);
    void print_mainmenu();
    void print_guestmenu(const std::string& GuestName);
    void create_guest(Guest& other);
    void print_casinomenu();
    void check_drunkenness(const Bar& obj, bool& shouldExit);
    void create_phrase();
    void print_welcome();
    void create_guest_menu(Guest& guest);
}