#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;


Player& FieldDoctor::treat(City city){
        if (board[city] == 0) {
        throw invalid_argument{"There is no disease at all in the city"};
    }
    if (current_city != city && !Board::connected(current_city, city)) {
    throw invalid_argument{"The cities are not connected"};
    }
  //  if (current_city == city && Board::connected(current_city, city)) {
    
    Color color_city=colors_of_cities.at(city);
    if (board.cure_discoverd.count(color_city)>0) {
        board[city] = 0;
    }
    else {
        board[city]=board[city]-1;
    }
    return *this;
    //}
     
}