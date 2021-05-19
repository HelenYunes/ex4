#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Player& Virologist::treat(City city){
    if (current_city != city) { 
        if(cards.count(city)==0) {
            throw std::invalid_argument{"You do not have a suitable card"};
        }
        cards.erase(city);
    }
    else if (board[city] == 0) {
        throw std::invalid_argument{"There is no disease at all in the city"};
    }
    else if (board.cure_discoverd.count(colors_of_cities.at(city))>0){
        board[city] = 0;
        return *this;
    }
    board[city]--;
    return *this;
}