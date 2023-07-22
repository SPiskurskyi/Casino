#pragma once

#include "Funcs.h"

namespace app {

    class Casino {
    public:
        explicit Casino(std::string name) : name_{ std::move(name) } {}
        void setup();
    private:
        std::string name_;
    };

}