#pragma once

#include "Guest.h"

namespace app {

    void create_phrase();

    class Bar
    {
    public:
        bool MakeOrder(int id, Guest& obj);
        void ShowAsortement();
        static int GetDrunkenness();
    private:
        static int drunkenness_;
        std::fstream barFile_;
        std::string name_;
        int price_ = 0;
        int id_ = 0;
        char quantity_ = 0;
        std::string path_ = "../assortment";

    };
}