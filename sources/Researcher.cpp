#include "Researcher.hpp"

using namespace std;
using namespace pandemic;
const int CARDS_FOR_DISCOVER_CURE = 5;

Player &Researcher::discover_cure(Color color1)
{
    int count = 0;
    for (const auto &t : cards)
    {
        if (colors_of_cities.at(t) == color1)
        {
            count++;
        }
    }
    if (count < CARDS_FOR_DISCOVER_CURE)
    {
        throw std::invalid_argument{"You do not have enough cards"};
    }
    count = 1;
    for (std::set<City>::iterator iterator = cards.begin(); iterator != cards.end(); count++)
    {
        if (count == CARDS_FOR_DISCOVER_CURE)
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
