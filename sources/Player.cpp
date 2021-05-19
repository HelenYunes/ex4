#include "Player.hpp"

using namespace std;
using namespace pandemic;
const int CARDS_FOR_DISCOVER_CURE = 5;

Player& Player::fly_shuttle(City city){
    if(current_city == city){
        throw invalid_argument{"It is not possible to travel from a city to itself"};
    }
    if(!board.is_research_station(current_city) || !board.is_research_station(city)){
        throw std::invalid_argument{"There is no research station in the city"};
    }
    current_city = city;
    medic_entered();
    return *this;
}
Player& Player::fly_direct(City city){
    if(current_city == city){
        throw std::invalid_argument{"It is not possible to travel from a city to itself"};
    }
    if(cards.count(city)==0){
        throw std::invalid_argument{"You do not have a suitable card"};
    }
    cards.erase(city);
    current_city = city;
    medic_entered();
    return *this;
}

Player& Player::fly_charter(City city){
    if(current_city == city){
        throw std::invalid_argument{"You can not fly from a city to itself"};
    }
    if(cards.count(current_city)==0){
        throw std::invalid_argument{"You do not have a suitable card"};
    }
    cards.erase(current_city);
    current_city = city;
    medic_entered();
    return *this;
}

Player& Player::drive(City city){
    if(current_city == city){
        throw std::invalid_argument{"You can not drive from a city to itself"};
    }
    if(!Board::connected(current_city, city)){
        throw std::invalid_argument{"The cities are not connected"};
    }
    current_city = city;
   medic_entered();
    return *this;
}

Player& Player::build(){
    if(cards.count(current_city)==0){
        throw std::invalid_argument{"You do not have a suitable card"};
    }
    board.build_research_station(current_city);
    cards.erase(current_city);
    return *this;
}

Player& Player::discover_cure(Color color1){

    if(board.cure_discoverd.count(color1)>0){    //"There is already a cure for the disease
         
                        return *this;   
        }
    
   if(board.is_research_station(current_city)){
   
    int count = 0;
    for (const City& city2 : cards){
        if(colors_of_cities.at(city2) == color1) {
            count++;
        }
    }
    if(count < CARDS_FOR_DISCOVER_CURE){
        throw std::invalid_argument{"You do not have enough cards" };
    }
    count = 1;
    for(std::set<City>::iterator  iterator = cards.begin(); iterator != cards.end(); count++){
        if(count == CARDS_FOR_DISCOVER_CURE) {
             break; 
             }
        if(colors_of_cities.at(*iterator) == color1) {
            iterator = cards.erase(iterator);
        }
        else {
            ++iterator;
        }
    }
    board.cure_discoverd.insert(color1);
    return *this;
   }
    throw invalid_argument{"There is no research station in the city"};
}

Player& Player::treat(City city){
    if (current_city != city) {
        throw std::invalid_argument{"You can not treat the disease in a city where you are not"};
    }
    if (board[city] == 0) {
        throw std::invalid_argument{"There is no disease at all in the city"};
    }
Color color_city=colors_of_cities.at(city);
    if (board.cure_discoverd.count(color_city)==0) {
        board[city]--;
    }
    if (board.cure_discoverd.count(color_city)>0){
        board[city] = 0;
    }

    return *this;
}
Player& Player::take_card(City city){
    cards.insert(city);
    return *this;
}