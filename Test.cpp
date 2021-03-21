#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;

ariel::Board board;

TEST_CASE("simple test") {   // abcd

    CHECK_NOTHROW(board.post(100,200,Direction::Horizontal, "abcd"));
    board.post(100,200,Direction::Horizontal, "abcd");
    CHECK(board.read(100,200,Direction::Horizontal, 4) == "abcd");
    CHECK(board.read(100,200,Direction::Vertical, 1) == "a");
    CHECK(board.read(100,201,Direction::Vertical, 1) == "b");
    CHECK(board.read(100,202,Direction::Vertical, 1) == "c");
    CHECK(board.read(100,203,Direction::Vertical, 1) == "d");

    CHECK_NOTHROW(board.post(100,200,Direction::Vertical, "abcd"));
    board.post(100,200,Direction::Vertical, "abcd");
    CHECK(board.read(100,200,Direction::Vertical, 4) == "abcd");
    CHECK(board.read(100,200,Direction::Horizontal, 1) == "a");
    CHECK(board.read(101,200,Direction::Horizontal, 1) == "b");
    CHECK(board.read(102,200,Direction::Horizontal, 1) == "c");
    CHECK(board.read(103,200,Direction::Horizontal, 1) == "d");

}

TEST_CASE("simple test with empty cell") {   

    CHECK_NOTHROW(board.post(100,200,Direction::Horizontal, "abcd"));
    board.post(100,200,Direction::Horizontal, "abcd");
    CHECK(board.read(100,199,Direction::Horizontal, 5) == "_abcd");
    CHECK(board.read(99,200,Direction::Vertical, 2) == "_a");
    CHECK(board.read(99,201,Direction::Vertical, 2) == "_b");
    CHECK(board.read(99,202,Direction::Vertical, 2) == "_c");
    CHECK(board.read(99,203,Direction::Vertical, 2) == "_d");

    CHECK_NOTHROW(board.post(100,200,Direction::Vertical, "abcd"));
    board.post(100,200,Direction::Vertical, "abcd");
    CHECK(board.read(99,200,Direction::Vertical, 6) == "_abcd_");
    CHECK(board.read(100,200,Direction::Horizontal, 2) == "ab");
    CHECK(board.read(101,200,Direction::Horizontal, 2) == "b_");
    CHECK(board.read(102,200,Direction::Horizontal, 2) == "c_");
    CHECK(board.read(103,200,Direction::Horizontal, 2) == "d_");
}

TEST_CASE("test empty line") {

    CHECK(board.read(50,200,Direction::Vertical, 4) == "____");

}

TEST_CASE("post on post") {
    CHECK_NOTHROW(board.post(100,200,Direction::Horizontal, "abcd"));
                                                       //              a
    board.post(100,200,Direction::Horizontal, "abcd"); // look like: abbd
    board.post(99,202,Direction::Vertical, "abcd");    //              c
                                                       //              d
    
    CHECK(board.read(100,200,Direction::Horizontal, 4) != "abcd");
    CHECK(board.read(100,200,Direction::Horizontal, 4) == "abbd");

}