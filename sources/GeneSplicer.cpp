#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;

const int CARDS_FOR_DISCOVER_CURE = 5;

Player& GeneSplicer::discover_cure(Color color){
    if(!board.is_research_station(current_city)){
        throw invalid_argument{"There is no research station in the city"};
    }
    if(cards.size() < CARDS_FOR_DISCOVER_CURE){
        throw invalid_argument{"You do not have enough cards" };
    }
    int count = 1;
    for(auto it = cards.begin(); it != cards.end(); count++){
        if(count == CARDS_FOR_DISCOVER_CURE) { break; }
        it = cards.erase(it);
    }
    board.cure_discoverd.insert(color);
    return *this;
}