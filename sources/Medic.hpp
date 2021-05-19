#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Medic: public Player {

        public:
            Medic(Board& board, City city): Player(board, city, "Medic") {}
            Player& treat(City city) override;
            // Medic& drive(const City city)  ; 
            // Medic& fly_charter(const City city)  ;
            // Medic& fly_shuttle(const City city)  ;
            // Medic& fly_direct(const City city) override ;
            // //std::string role() override ;
            void medic_entered() override;
    };
    
}