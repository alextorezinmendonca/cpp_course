#include "table.h"

using namespace std;

void Table::printConnection(int initSpace, int size){
    cout << endl;
    printSpace(initSpace);
    for(int i = 0; i < size-1; i++){
        cout << " \\ /";
    }
    cout << " \\" << endl;

}


void Table::printSpace(int howMany){
    for(int i = 0; i < howMany; i++){
        cout << "  " ;
    }
    
}


void Table::printBoard(vector<vector<int>> board){

    for (int i = 0; i < board.size(); ++i) {
        printSpace(i);
        for (int j = 0; j < board.size(); ++j) {
            switch(board[i][j]){
                case 88: 
                    cout << "X";
                    break;
                case 79: 
                    cout << "O";
                    break;
                default: cout << ".";
            }
            if(j<board.size()-1) cout << " - ";
        }
        if(i<board.size()-1) printConnection(i, board.size()); // Don't print connect at last line
    }
    cout << endl;
}