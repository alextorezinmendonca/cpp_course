#include <iostream>
#include <vector>

using namespace std;

class Graph{
    public:
        Graph(double density, int verticeNum, int distMaxRange);
        ~Graph();
        void printGraph();
        int V();
        int E();
        bool adjacent(int, int);
        vector<int> neighbors(int);
        bool add(int x, int y, int mark);
        void deleteEdge(int, int);
        int getEdgeValue(int x, int y);
        void setEdgeValue(int, int, int);
        bool validate(int x, int y);
        vector<vector<int>> getGraphMatrix();

    private: 
        double density; //Definy density for random graph generator. 0.1 will create 10% of edges
        int verticeNum; //Numbers of maximum vertice in the graph
        int distMaxRange; //Maximum edge value between 2 nodes

        vector<vector<int>> matrix;
        mt19937 gen;
        uniform_int_distribution<int> distribution;

        int needEdges();
        int generateRandomNumber();
        int generateRandomNumber(int, int);
        void fillMatrix();
        void printVector(vector<int>);
};
