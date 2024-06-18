/*
Author: Alex Torezin Mendonca
Country: Brazil
Linkedin: https://www.linkedin.com/in/mendoncaalex/

Minimum Spaning tree Algorith for C++ Especialization Course.
December, 2023.

GCC version 9.4.0
C++ 14
*/


#include <iostream>
#include <vector>
#include <random>
#include <tuple>

using namespace std;

// Graph class implement graph, with some methods.
// The class genarete random graph based on the input vertice Number, density and distanceMaxRange;
// The output graph the edge can be uni or bi directional.
// When bi directional, the edge size isn't necessary the same.
// Is used random uniform int distribution library to generate the edges.
// The possition of the edges is random generated too.


class priorityQueue{
    private:
        vector<int> PQ;

    public:
        //Constructor
        priorityQueue(){
        }

        //Destructor
        ~priorityQueue(){
        }

        //Does the queue contain queue_element
        bool contains(int queue_element){
            for(int i = 0; i < PQ.size(); i++){
                if(PQ[i] == queue_element){
                    return true;
                }
            }
            return false;
        }

        //Insert queue_element into queue
        void insert(int queue_element){
            PQ.push_back(queue_element);
        }

        //Delete especific value from Queue
        void del(int position){
            PQ.erase(PQ.begin() + position);
            
        }

        void delByValue(int value){
            for(int i = 0; i < this->size(); i++){
                if( this->read(i) == value){
                    this->del(i);
                }
            }
        }


        //return the top element of the queue
        int pop(){
            int top = PQ[0];
            PQ.erase(PQ.begin());
            return top;
        }

        //Return the number of queue_elements
        int size(){
            return PQ.size(); 
        }

        int indexOf(int value) {
            for (int i = 0; i < PQ.size(); ++i) {
                if (PQ[i] == value) {
                    return i;
                }
            }
            return -1;  // If not found
        }

        void print(){
            for(int i = 0; i < this->size(); i++){
                cout << PQ[i] << " ";
            }
            cout << endl;
        }

        int read(int i){
            return PQ[i];
        }

          // Set the key value for a given vertex
        void setKeyValue(int vertex, int keyValue) {
            PQ[vertex] = keyValue;
            return;
        }

        //Fill with sequencial integer based on input
        void fillBySize(int i){
            for(int j = 0; j < i; j++){
                insert(j);
            }
        }

        void fillBySizeAndValue(int i, int k){
            for(int j = 0; j < i; j++){
                insert(k);
            }
        }

        int getIndexMinimumEdge(priorityQueue Q){
            int position;
            int sizeValue = 100000;

            for(int j = 0; j < this->size(); j++){
                if(Q.contains(j)){
                    if(this->read(j) < sizeValue){
                        sizeValue = read(j);
                        position = j;
                    }
                }
            }
            return position;
        }

};

class graph{
    private:
        double density; //Definy density for random graph generator. 0.1 will create 10% of edges
        int verticeNum; //Numbers of maximum vertice in the graph
        int distMaxRange; //Maximum edge value between 2 nodes

        vector<vector<int>> matrix;
        mt19937 gen;
        uniform_int_distribution<int> distribution;


        //Calcute number of edges based on density
        int needEdges(){
            int numberEdges = verticeNum * verticeNum * density;
            return numberEdges;
        }

        //Genarete random numbers between range fixed
        int generateRandomNumber() {
            return distribution(gen);;
        }

        //Overload method, Genarete random numbers between range as parameter
        int generateRandomNumber(int lowerBound, int upperBound) {
            uniform_int_distribution<int> newDistribution(lowerBound, upperBound);
            return newDistribution(gen); 
        }

        //Fill graph matrix with random number in random positions.
        //Sometimes the same position can be overwrite for the next one.
        void fillMatrix(){
            int numberEdges = needEdges();
            int k = 0;
            while(k < numberEdges){
                int i = generateRandomNumber(0, verticeNum-1);
                int j = generateRandomNumber(0, verticeNum-1);

                //Check if value from matrix is 0, 
                //If i=j value is 0, distance from him to himself is always 0
                if(matrix[i][j] == 0 and i != j){
                    matrix[i][j] = matrix[j][i] = generateRandomNumber();
                    k++;
                }
            }
        }
        
        //Print whole vector
        void printVector(vector<int> vector){
            for(int i = 0; i < 7; i++){
                cout << vector[i] << endl;
            }
        }


    public:
        //constructor
        graph(double density, int verticeNum, int distMaxRange):
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
            //fillMatrix();

            //------------- TEST CASE -------------
            //Result: u=0 and w=2, short path is 7
            matrix = {{0, 5, 0, 2},
                      {5, 0, 3, 9},
                      {0, 3, 0, 7},
                      {2, 9, 7, 0}};
        }

        //destructor
        ~graph(){
        }


        void printGraph(){
            cout << "Graph with Edge value is:" << endl;
            for (int i = 0; i < this->verticeNum; ++i) {
                for (int j = 0; j < this->verticeNum; ++j) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }


        //Return the number of vertices in the graph
        int V(){
            return this->verticeNum;
        }

        //Returns the number of edges in the graph
        //Needed to be counted, maybe new one was added
        int E(){
            int edgesCount = 0;
            for(int i = 0; i < this->verticeNum; i++){
                for(int j = 0; j < this->verticeNum; j++){
                    if( matrix[i][j] != 0) edgesCount++;
                }
            }
            return edgesCount;
        }

        //Test wheter there is an edge from node x to node y
        bool adjacent(int x, int y){
            
            if(matrix[x][y] != 0){
                cout << "Edge size between " << x << " and " << y << " is: " << matrix[x][y] << endl;
                return true;
            }
            cout << "No Edge size between " << x << " and " << y << endl;
            return false;
        }

        //List all nodes y such that there is an edge from x to y
        priorityQueue neighbors(int x){
            priorityQueue neighbordEdge;

            for(int i = 0; i < this->verticeNum; i++){    
                if(matrix[x][i] != 0){
                    neighbordEdge.insert(i); //matrix[x][i];
                }
            }
            return neighbordEdge;
        }

        //Adds to G the edge from x to y with distance d, if it is not there
        void add(int x, int y, int d){
            if (!adjacent(x, y)){
                matrix[x][y] = d;
                cout << "Edge was add with success!" << endl;
                return;
            }
            cout << "Edge not Added, there is edge betwen: " << x << " and " << y << endl;
        }

        //Removes the edge from x to y, if it is there
        void deleteEdge(int x, int y){
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
        int get_edge_value(int x, int y){
            return matrix[x][y];
        }

        //Return the vertix with the minimum edge
        int minimumEdge(int x){
            int value = 10000;
            int position = 0;

            priorityQueue neighbors = this->neighbors(x);

            for(int i = 0; i < neighbors.size(); i++){    

                if(get_edge_value(x, neighbors.read(i)) < value){
                    value = get_edge_value(x, neighbors.read(i));
                    position = neighbors.read(i);
                }
            }
            return position;
        }

        //Vertex with minimum edge in vertex prioQueue
        int minimumEdge(priorityQueue unvistedVertex){
            int position_from;
            int position_to;
            int minimumValue = 10000;
            int pos_to;

            //Minimum edge between all unvisted vertex
            for(int i = 0; i < unvistedVertex.size(); i++){

                pos_to = minimumEdge(unvistedVertex.read(i));

                if( get_edge_value(i, pos_to) < minimumValue) {
                    position_from = i;
                    position_to = pos_to;
                }
            }

            return position_from;
        }

        //Sets the value associated to the edge (x,y) to v
        void set_edge_value(int x, int y, int v){
            matrix[x][y] = v;
        }
};




class shortestPath{
    private:
        double randomNodeProbality;
        int numberOfNode;
        int maxDist;
        int u, w;
        int maxPathSize;

        

    public:

        graph g = {randomNodeProbality, numberOfNode, maxDist};

        //Constructor
        shortestPath(double randomNodeProbality, int numberOfNode, int maxDist):
            randomNodeProbality(randomNodeProbality),
            numberOfNode(numberOfNode),
            maxDist(maxDist),
            maxPathSize(maxDist + 100)
        {
        }

        //Destructor
        ~shortestPath(){

        }

        //List of vertices in graph
        vector<int> vertices(){
            vector<int> vertices(100, 0);

            return vertices;
        }
        
        // //Find shortest path between u and w
        tuple<priorityQueue, priorityQueue> prim(int startVertex){

            priorityQueue Q;
            priorityQueue key;
            priorityQueue pi;
            priorityQueue v;
            int u;
            int vertice;

            //Initialize struct
            Q.fillBySize(numberOfNode);
            key.fillBySizeAndValue(numberOfNode, 1000);
            key.setKeyValue(startVertex, 0);
            pi.fillBySizeAndValue(numberOfNode, 0);

            while( Q.size() != 0){
                u = key.getIndexMinimumEdge(Q);
                Q.delByValue(u);

                v = g.neighbors(u);
                while( v.size() != 0){
                    vertice = v.pop();
                    if(  Q.contains(vertice) && ( g.get_edge_value(u, vertice) < key.read(vertice) ) ){
                        pi.setKeyValue(vertice, u);
                        key.setKeyValue(vertice, g.get_edge_value(u, vertice));
                    }
                }
            }

            return make_tuple(key, pi);
        }
};


int main(){
    vector<double> randomNodeProbality = {0.4, 0.4};
    int numberOfNode = 4;
    int maxDist = 10.;
    tuple<priorityQueue, priorityQueue> result;
    priorityQueue mstKey, mstPi;

    //Nodes to get short distance
    int source = 3;
    shortestPath shortPath = {randomNodeProbality[0], numberOfNode, maxDist};

    result = shortPath.prim(source);
    mstKey = get<0>(result);
    mstPi = get<1>(result);

    printf("MST path by father node:\n");
    mstPi.print();

    printf("MST cost:\n");
    mstKey.print();

    return 0;
}