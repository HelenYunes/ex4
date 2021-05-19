#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class Scientist: public Player {
        int n;

        public:
            Scientist(Board& board, City city, int number): Player(board, city, "Scientist"), n(number) {}
            Player& discover_cure(Color c) override;
    };
    
}