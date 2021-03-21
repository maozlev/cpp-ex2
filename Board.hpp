#include "Direction.hpp"
// using ariel::Direction;

#include <iostream>
#include <stdexcept>
#include <vector>

namespace ariel{
    class Board{
        
        std::vector<std::vector<char>> Main_Board{};
        static int flag;
        public:
       
        void post(unsigned int raw, unsigned int col, Direction, std::string message);
        std::string read(unsigned int raw, unsigned int col, Direction, unsigned int len);
        void show();


    };
}
