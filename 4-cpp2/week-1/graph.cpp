#include <iostream>
#include <vector>
#include <random>

#include "graph.h"

using namespace std;

// Constructor
Graph::Graph(double density, int verticeNum, int distMaxRange):
    density(density),
    verticeNum(verticeNum),
    distMaxRange(distMaxRange),
    gen(random_device()()), 
    distribution(1, distMaxRange), 
    matrix(verticeNum, vector<int>(verticeNum, 0))
{
    cout << "Density: " << density << " Number of members: " << verticeNum << " Maximum distance: " << distMaxRange;
    cout << " Needed edges: " << needEdges() << endl;

    //Comment bellow and uncomment TEST CASE to test
    fillMatrix();

    //------------- TEST CASE -------------
    //Result: u=0 and w=2, short path is 7
    // matrix = {{0, 5, 0, 2},
    //           {2, 0, 0, 9},
    //           {0, 0, 0, 0},
    //           {6, 0, 0, 0}};
}


// Destructor
Graph::~Graph(){
}


//Calcute number of edges based on density
int Graph::needEdges(){
    int numberEdges = verticeNum * verticeNum * density;
    return numberEdges;
}


//Genarete random numbers between range fixed
int Graph::generateRandomNumber() {
    return distribution(gen);;
}


//Overload method, Genarete random numbers between range as parameter
int Graph::generateRandomNumber(int lowerBound, int upperBound) {
    uniform_int_distribution<int> newDistribution(lowerBound, upperBound);
    return newDistribution(gen); 
}


//Fill Graph matrix with random number in random positions.
//Sometimes the same position can be overwrite for the next one.
void Graph::fillMatrix(){
    int numberEdges = needEdges();
    int k = 0;
    while(k < numberEdges){
        int i = generateRandomNumber(0, verticeNum-1);
        int j = generateRandomNumber(0, verticeNum-1);

        //Check if value from matrix is 0, 
        //If i=j value is 0, distance from him to himself is always 0
        if(matrix[i][j] == 0 and i != j){
            matrix[i][j] = generateRandomNumber();
            k++;
        }
    }
}
    

//Print whole vector
void Graph::printVector(vector<int> vector){
    for(int i = 0; i < 7; i++){
        cout << vector[i] << endl;
    }
}


void Graph::printGraph(){
    cout << "Graph with Edge value is:" << endl;
    for (int i = 0; i < this->verticeNum; ++i) {
        for (int j = 0; j < this->verticeNum; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


//Return the number of vertices in the Graph
int Graph::V(){
    return this->verticeNum;
}


//Returns the number of edges in the Graph
//Needed to be counted, maybe new one was added
int Graph::E(){
    int edgesCount = 0;
    for(int i = 0; i < this->verticeNum; i++){
        for(int j = 0; j < this->verticeNum; j++){
            if( matrix[i][j] != 0) edgesCount++;
        }
    }
    return edgesCount;
}


//Test wheter there is an edge from node x to node y
bool Graph::adjacent(int x, int y){
    
    if(matrix[x][y] != 0){
        cout << "Edge size between " << x << " and " << y << " is: " << matrix[x][y] << endl;
        return true;
    }
    cout << "No Edge size between " << x << " and " << y << endl;
    return false;
}


//List all nodes y such that there is an edge from x to y
vector<int> Graph::neighbors(int x){
    vector<int> neighbordEdge(this->verticeNum, -1);
    int indexVector = 0;

    for(int i = 0; i < this->verticeNum; i++){    
        if(matrix[x][i] != 0){
            neighbordEdge[indexVector] = i; //matrix[x][i];
            indexVector++;
        }
    }
    return neighbordEdge;
}


bool Graph::validate(int x, int y){
    if (x >=0 && x < verticeNum && y >=0 && y < verticeNum && matrix[x][y] == 0){
        return true;
    }
    return false;
}


//Adds to G the edge from x to y with distance d, if it is not there
bool Graph::add(int x, int y, int mark){
    if(!validate(x, y)){
        cout << "!!ERROR!! Need to be between < x, y < " << verticeNum-1  << endl;
        return false;
    }
    matrix[x][y] = mark;
    return true;

}


//Removes the edge from x to y, if it is there
void Graph::deleteEdge(int x, int y){
    if (adjacent(x, y)){
        matrix[x][y] = 0;
        cout << "Edge was deleted with success!" << endl;
        return;
    }
    cout << "Edge not deleted, there is edge betwen: " << x << " and " << y << endl;
}

// //returns the value associated with the node x
// int get_node_value(int x){
//     return x;
// }

//Returns the value associated to the edge (x,y)
int Graph::getEdgeValue(int x, int y){
    return matrix[x][y];
}


//Sets the value associated to the edge (x,y) to v
void Graph::setEdgeValue(int x, int y, int v){
    matrix[x][y] = v;
}


//Sets the value associated to the edge (x,y) to v
vector<vector<int>> Graph::getGraphMatrix(){
    return matrix;
}
