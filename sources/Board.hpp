#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>

namespace pandemic
{

    class Board
    {
    protected:
        static std::map<City, std::set<City>> neighbors;
        std::map<City, int> disease_level;
        std::set<City> research_stations;

    public:
        std::set<Color> cure_discoverd;
        Board() {}
        int &operator[](City city);
        friend std::ostream &operator<<(std::ostream &output, const Board &board);
        bool is_clean();
        void remove_cures();
        void build_research_station(City city);
        bool is_research_station(City city);
        static bool connected(City &city1, City &city2);
    };
}
