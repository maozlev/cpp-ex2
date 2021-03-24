#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;

ariel::Board board;

TEST_CASE("simple test") {   // abcd
    
    board.post(20,20,Direction::Horizontal, "abcd");
    CHECK(board.read(20,20,Direction::Horizontal, 4) == "abcd");
    CHECK(board.read(20,20,Direction::Vertical, 1) == "a");
    CHECK(board.read(20,21,Direction::Vertical, 1) == "b");
    CHECK(board.read(20,22,Direction::Vertical, 1) == "c");
    CHECK(board.read(20,23,Direction::Vertical, 1) == "d");
    

    board.post(10,10,Direction::Vertical, "abcd");
    CHECK(board.read(10,10,Direction::Vertical, 4) == "abcd");
    CHECK(board.read(10,10,Direction::Horizontal, 1) == "a");
    CHECK(board.read(11,10,Direction::Horizontal, 1) == "b");
    CHECK(board.read(12,10,Direction::Horizontal, 1) == "c");
    CHECK(board.read(13,10,Direction::Horizontal, 1) == "d");

}


TEST_CASE("test empty line") {

    board.post(15,15,Direction::Vertical, "abcd");
    CHECK(board.read(1,1,Direction::Vertical, 4) == "____");
    CHECK(board.read(14,15,Direction::Vertical, 2) == "_a");
    CHECK(board.read(14,15,Direction::Vertical, 3) == "_ab");
    CHECK(board.read(14,15,Direction::Vertical, 4) == "_abc");
    CHECK(board.read(14,15,Direction::Vertical, 5) == "_abcd");
    CHECK(board.read(14,15,Direction::Vertical, 6) == "_abcd_");

}

TEST_CASE("post on post") {
                                                        //              a
    board.post(5,5,Direction::Horizontal, "abcd");      // look like: abbd
    board.post(4,7,Direction::Vertical, "abcd");        //              c
                                                        //              d
    
    CHECK(board.read(5,5,Direction::Horizontal, 4) != "abcd");
    CHECK(board.read(5,5,Direction::Horizontal, 4) == "abbd");
                                      
    board.post(1,1,Direction::Horizontal, "abcd"); 
    board.post(1,1,Direction::Horizontal, "hel");  

    CHECK(board.read(1,1,Direction::Horizontal, 4) != "abcd");
    CHECK(board.read(1,1,Direction::Horizontal, 4) == "held"); 
                                                   
}