#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <vector>
// #include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;

namespace ariel{
    
    void Resize_Board_rows(vector<vector<char>> &Board, unsigned int row, unsigned int col);
    void Resize_Board_cols(vector<vector<char>> &Board, unsigned int row, unsigned int col);
    
    void Resize_Board_rows(vector<vector<char>> &Board, unsigned int row, unsigned int col ){
        vector<char> v (col);
        fill(v.begin(), v.end(), '_');
        for (unsigned int  i = 0; i < row; i++){
            Board.push_back(v);
        }   
    }

    void Resize_Board_cols(vector<vector<char>> &Board, unsigned int row, unsigned int col ){
         unsigned int size = Board[0].size();
        for (unsigned int i = 0; i < col; i++){   
            Board[i].resize(row);
            fill(Board[i].begin()+size, Board[i].end(),'_');
        }
    }

    Board::Board(){
       vector<char> tmp{};
       tmp.push_back('_');
       Main_Board.push_back(tmp);
    }

    void Board::post(unsigned int row, unsigned int col, Direction d, string message ){
        
        if(d == Direction::Horizontal){

            if(row >= Main_Board.size()){
                Resize_Board_rows(Main_Board, row+2 - Main_Board.size(),Main_Board[0].size()); 
            }
            if(col + message.length() > Main_Board[0].size()){
                Resize_Board_cols(Main_Board, col+message.length(), Main_Board.size());
            }
            unsigned int size_string = 0;
            for (unsigned int i = col; i < col + message.length(); i++){
                Main_Board[row][i] = message[size_string];
                size_string++;
            }
        }
        else if(d == Direction::Vertical){

            if(row + message.length()> Main_Board.size()){
                Resize_Board_rows(Main_Board, row + message.length() - Main_Board.size(), Main_Board[0].size());}
            
            if(col >= Main_Board[0].size()){
                Resize_Board_cols(Main_Board, col+2, Main_Board.size());}
            
            unsigned int size_string = 0;
            for (unsigned int i = row; i < row + message.length(); i++){
                Main_Board[i][col] = message[size_string];
                size_string++;
            }
        }
    }

    string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int len ){
        string message_out;
        if(d == Direction::Horizontal){
            if(row>=Main_Board.size()){
                Resize_Board_rows(Main_Board, row+1-Main_Board.size(), Main_Board[0].size());        
            }
            if(col+len>Main_Board[0].size()){
                Resize_Board_cols(Main_Board, col+len, Main_Board.size());
            }
            for (unsigned int i = col; i < col + len ; i++){
                message_out+=Main_Board[row][i];
            }
        }
        else if(d == Direction::Vertical){
            if(row+len>Main_Board.size()){
                Resize_Board_rows(Main_Board, row+len-Main_Board.size(), Main_Board[0].size());        
            }
            if(col>=Main_Board[0].size()){
                Resize_Board_cols(Main_Board, col+1, Main_Board.size());
            }
            for (unsigned int i = row; i < row + len; i++){
                message_out += Main_Board[i][col];
            }
        }
        return message_out;
    }


    void Board::show() {
        for (vector<char> row: Main_Board) {
            for (char val: row) {
            	cout << val << " ";
            }
            cout << '\n';
	    }
    }

   
}
