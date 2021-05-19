#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

namespace pandemic {

    class Player {

        protected:
            Board& board;
            std::set<City> cards;
            City current_city; 
            std::string player_role;
            
        public:
            Player(Board& board, City city, std::string role = "Player"): board(board), current_city(city), player_role(role){}

            Player& take_card(City city);
    
            virtual Player& build();
            virtual Player& discover_cure(Color color1);
            virtual Player& treat(City city);
            std::string role(){return player_role;}
            Player& drive(City city);
            virtual Player& fly_direct(City city);
            Player& fly_charter(City city);
            Player& fly_shuttle(City city);
            virtual void medic_entered(){};

    };

}
