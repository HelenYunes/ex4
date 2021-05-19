#include "Medic.hpp"

using namespace std;
using namespace pandemic;


Player& Medic::treat(City city) {
    if (current_city == city) {
        
    if (board[city] == 0) {
        throw invalid_argument{"There is no disease at all in the city"};
    }

    board[city] = 0;
    return *this;
}
throw invalid_argument{"You can not treat the disease in a city where you are not"};
    }

void Medic::medic_entered() {
    Color color_city=colors_of_cities.at(current_city);
    if (board.cure_discoverd.count(color_city)>0){
        board[current_city] = 0;
    }
}
    //  Medic& Medic::drive(const City city) {
    //     Player::drive(city);
    //       Color color_city=cities_colors.at(current_city);
    //        if (board.cure_discoverd.count(color_city)>0){
    //          board[current_city] = 0;
    //     }
    //     return *this;
    // }
    // Medic& Medic::fly_charter(const City city){
    //    Color color_city=cities_colors.at(current_city);
    //        if (board.cure_discoverd.count(color_city)>0){
    //          board[current_city] = 0;
    //     }
    //     return *this;
    // }
    // Medic& Medic::fly_shuttle(const City city){
    //     Player::fly_shuttle(city);
    //    Color color_city=cities_colors.at(current_city);
    //        if (board.cure_discoverd.count(color_city)>0){
    //          board[current_city] = 0;
    //     }
    //     return *this;
    // }
    // Medic& Medic::fly_direct(const City city){
    //     Player::fly_direct(city);
    //    Color color_city=cities_colors.at(current_city);
    //        if (board.cure_discoverd.count(color_city)>0){
    //          board[current_city] = 0;
    //     }
    //     return *this;
    // }
