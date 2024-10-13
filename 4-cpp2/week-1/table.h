#include <iostream>
#include <vector>

using namespace std;

class Table{
    public:
        void printBoard(vector<vector<int>> board);
        void printConnection(int initSpace, int size);
        void printSpace(int howMany);
        vector<vector<int>> board;
        int size;
        int connections;
};
