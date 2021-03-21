#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

namespace ariel{
    
    void Resize_Board_rows(vector<vector<char>> &Board, unsigned int add_rows, unsigned int col);
    void Resize_Board_cols(vector<vector<char>> &Board, unsigned int add_col, unsigned int row);
    

    void Board::post(unsigned int row, unsigned int col, Direction d, string message ){
        // if(d == Direction::Horizontal){

        //     if(row > Main_Board.size()){
        //         cout<<"1="<<row - Main_Board.size()<<endl;
        //         cout<<"2="<<Main_Board[0].size()<<endl;
        //         Resize_Board_rows(Main_Board, row - Main_Board.size(),message.length() ); //Main_Board[0].size()
        //     }
        //     if(col + message.length() > Main_Board[0].size())
        //         Resize_Board_cols(Main_Board, Main_Board.size(), col + message.length());

        //     unsigned int size_string = 0;
        //     for (unsigned int i = col; i < col + message.length(); i++){
        //         Main_Board[row][i] = message[size_string];
        //         size_string++;
        //     }
        // }
        // else if(d == Direction::Vertical){

        //     if(row + message.length()> Main_Board.size())
        //         Resize_Board_rows(Main_Board, row + message.length() - Main_Board.size(), Main_Board[0].size());
            
        //     if(col > Main_Board[0].size())
        //         Resize_Board_cols(Main_Board, Main_Board.size(), col);
            
        //     unsigned int size_string = 0;
        //     for (unsigned int i = row; i < row + message.length(); i++){
        //         Main_Board[i][col] = message[size_string];
        //         size_string++;
        //     }
        // }
    }

    string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int len ){
        // string message_out;
        // if(d == Direction::Horizontal){

        //     unsigned int size_string = 0;
        //     for (unsigned int i = col-1; i < col + len-1 ; i++){
        //         message_out+=Main_Board[row-1][i];
        //         size_string++;
        //     }
        //     return message_out;
        // }
        // else if(d == Direction::Vertical){
        //     unsigned int size_string = 0;
        //     for (unsigned int i = row-1; i < row + len-1; i++){
        //         message_out += Main_Board[i][col-1];
        //         size_string++;
        //     }
        //     return message_out;
        // }
        return "loser";
    }


    void Board::show() {
        for (vector<char> row: Main_Board) {
            for (char val: row) {
            	cout << val << " ";
            }
            cout << '\n';
	    }
    }

     void Resize_Board_rows(vector<vector<char>> &Board, unsigned int add_rows, unsigned int col ){
        vector<char> v (col);
        fill(v.begin(), v.end(), '_');
        for (unsigned int  i = 0; i < add_rows; i++){
            Board.push_back(v);
        }   
    }

    void Resize_Board_cols(vector<vector<char>> &Board, unsigned int row, unsigned int add_col ){
        for (unsigned int i = 0; i < row; i++){
            unsigned int size = Board[i].size();
            Board[i].resize(add_col);
            fill(Board[i].begin()+size, Board[i].end(),'_');
        }
    }
}
