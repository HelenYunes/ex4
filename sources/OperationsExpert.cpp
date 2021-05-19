#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;


Player& OperationsExpert::build(){
    board.build_research_station(current_city);
    return *this;
}