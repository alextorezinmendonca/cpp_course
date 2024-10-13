/*
Author: Alex Torezin Mendonca
Country: Brazil
Linkedin: https://www.linkedin.com/in/mendoncaalex/

Hex Board Game for C++ Especialization Course.
Octover, 2024.

GCC version 9.4.0
C++ 14
*/


#include <iostream>
#include <vector>
#include <random>
#include "table.h"
#include "graph.h"

using namespace std;

int main(){
    int size = 0;
    int posX;
    int posY;

    cout << "Enter board size: " << endl;
    cin >> size;

    Graph gameBoardGraph(0, size, 0);
    vector<vector<int>> gameGraph = gameBoardGraph.getGraphMatrix();
    Table boardGame;
    boardGame.printBoard(gameGraph);

    while(true){
        cout << "BLUE PLAY TURN (99 to stop)" << endl;
        cout << "X position: ";
        cin >> posX;
        if(posX == 99) break;

        cout << "Y position: ";
        cin >> posY;
        if(posY == 99)  break;

        cout << "Position to insert your BLUE PIN is: (" << posX << ", " << posY << ")"  << endl;
        gameBoardGraph.add(posX, posY, 'X');
        gameGraph = gameBoardGraph.getGraphMatrix();
        boardGame.printBoard(gameGraph);


        cout << "RED PLAY TURN" << endl;
        cout << "X position: ";
        cin >> posX;
        if(posX == 99) break;

        cout << "Y position: ";
        cin >> posY;
        if(posY == 99)  break;

        cout << "Position to insert your RED PIN is: (" << posX << ", " << posY << ")"  << endl;

        gameBoardGraph.add(posX, posY, 'O');
        gameGraph = gameBoardGraph.getGraphMatrix();
        boardGame.printBoard(gameGraph);

    }


    return 0;
}