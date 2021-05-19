#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Player &Scientist::discover_cure(Color color1)
{
    if (!board.is_research_station(current_city))
    {
        throw std::invalid_argument{"There is no research station in the city"};
    }
    int count = 0;
    for (const City &c1 : cards)
    {
        if (colors_of_cities.at(c1) == color1)
        {
            count++;
        }
    }
    if (count < n)
    {
        throw std::invalid_argument{"You do not have enough cards"};
    }
    count = 1;
    for (set<City>::iterator iterator = cards.begin(); iterator != cards.end(); count++)
    {
        if (count == n)
        {
            break;
        }
        if (colors_of_cities.at(*iterator) == color1)
        {
            iterator = cards.erase(iterator);
        }
        else
        {
            ++iterator;
        }
    }
    board.cure_discoverd.insert(color1);
    return *this;
}