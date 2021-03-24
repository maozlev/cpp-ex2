#include "Direction.hpp"
// using ariel::Direction;

#include <iostream>
#include <stdexcept>
#include <vector>

namespace ariel{
    class Board{
        
        std::vector<std::vector<char>> Main_Board{};
        unsigned int flag;
        
        public:

        Board();
        Board(unsigned int row,unsigned int col);
        void post(unsigned int row, unsigned int col, Direction, std::string message);
        std::string read(unsigned int row, unsigned int col, Direction, unsigned int len);
        void show();
        
    };
}
