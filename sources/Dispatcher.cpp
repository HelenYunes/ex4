#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player& Dispatcher::fly_direct(City city){
    if(current_city == city){
        throw invalid_argument{"It is impossible to travel from a city to itself"};
    }
    if(board.is_research_station(current_city)) {
        current_city = city;
    }
    else {
        return Player::fly_direct(city);
    }
    return *this;
}