/*
Author: Alex Torezin Mendonca
Country: Brazil
Linkedin: https://www.linkedin.com/in/mendoncaalex/

Dijkstra Algorith for C++ Especialization Course.
December, 2023.

GCC version 9.4.0
C++ 14
*/


#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Graph class implement graph, with some methods.
// The class genarete random graph based on the input vertice Number, density and distanceMaxRange;
// The output graph the edge can be uni or bi directional.
// When bi directional, the edge size isn't necessary the same.
// Is used random uniform int distribution library to generate the edges.
// The possition of the edges is random generated too.

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
                    matrix[i][j] = generateRandomNumber();
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
            fillMatrix();

            //------------- TEST CASE -------------
            //Result: u=0 and w=2, short path is 7
            // matrix = {{0, 5, 0, 2},
            //           {2, 0, 0, 9},
            //           {0, 0, 0, 0},
            //           {6, 0, 0, 0}};
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
        vector<int> neighbors(int x){
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

        //Sets the value associated to the edge (x,y) to v
        void set_edge_value(int x, int y, int v){
            matrix[x][y] = v;
        }
};

class priorityQueue{
    private:
        vector<int> PQ;

    public:
        //Constructor
        priorityQueue(vector<int> pq):
        PQ(pq)
        {
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

        void print(){
            cout << "Queue print" << endl;
            for(int i = 0; i < this->size(); i++){
                cout << PQ[i] << " ";
            }
            cout << endl;
        }
};


class shortestPath{
    private:
        double randomNodeProbality;
        int numberOfNode;
        int maxDist;
        int u, w;
        int maxPathSize;

        priorityQueue Q;
        priorityQueue visitedNode;

        vector<int> pathVector;

    public:

        graph g = {randomNodeProbality, numberOfNode, maxDist};

        //Constructor
        shortestPath(double randomNodeProbality, int numberOfNode, int maxDist):
        randomNodeProbality(randomNodeProbality),
        numberOfNode(numberOfNode),
        maxDist(maxDist),
        maxPathSize(maxDist + 100),
        pathVector(g.V(), maxPathSize),
        Q(vector<int>{}),
        visitedNode(vector<int>{g.V()})
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
        
        //Find shortest path between u and w
        //vector<int> path(int source, int w){
        int path(int source, int destiny){

            vector<int> dist(g.V(), 100000); //Start distance vector, from Source to Destiny with "infinite value"
            dist[source] = 0;
            Q.insert(source);
            visitedNode.insert(source);

            int u; //Intermediate node to visit
            int alt; //Temporary distance from the current node to the source

            while(Q.size() != 0){
                u = Q.pop(); //Get first element from queue and remove than
                vector<int> v = g.neighbors(u);

                //Dijkstra algorithm
                for(int i = 0; i < v.size(); i++){
                    if(v[i] > 0){ //Check if the neighbor is not in the empty(default -1) position
                        alt = dist[u] + g.get_edge_value(u, v[i]);
                        if(alt < dist[v[i]]){
                            dist[v[i]] = alt;
                        }
                        //Check if node was visited before, if not, inser queue to be visite
                        if( !visitedNode.contains(v[i]) ){
                            Q.insert(v[i]);
                            visitedNode.insert(v[i]);
                        }
                    }
                }                    
            }

            return dist[destiny];
        }


        //Return path cost associated with the shortest path
        int path_size(){
            int pathSize = 0;
            int p1 = 0;
            int p2 = 1;

            //Edge cases
            if(pathVector.size() <= 1){
                return 0;
            }
            if(pathVector.size() == 2){
                return g.get_edge_value(pathVector[0], pathVector[1]);
            }

            //Sum loop
            for(int i = 0; i < pathVector.size() - 1; i++){
                if(pathVector[p1] <= this->numberOfNode and pathVector[p2] <= this->numberOfNode ){
                    pathSize += g.get_edge_value(pathVector[p1], pathVector[p2]);
                }
                p1 += p1;
                p2 += p2;
            }
            return pathSize;
        }

};


int main(){
    vector<double> randomNodeProbality = {0.2, 0.4};
    int numberOfNode = 50;
    int maxDist = 10.; ;

    //Nodes to get short distance
    int source = 0;
    int tempPath = 0;
    int pathLenghtTotal = 0;
    int numberOfValidPath = 0;

    for(int i = 0; i < randomNodeProbality.size(); i++)
    {    
        shortestPath shortPath = {randomNodeProbality[i], numberOfNode, maxDist};

        //Print output genareted matrix GRAPH
        //shortPath.g.printGraph();

        //Calculate average path lenght between node 0 and n nodes
        //Get the short path between 2 points
        //If value is infinity (100000) there isn't path between 2 nodes
        for(int i = 1; i < numberOfNode; i++){
            tempPath = shortPath.path(source, i);
            if(tempPath < 100000){
                pathLenghtTotal += tempPath;
                numberOfValidPath += 1;
            }
        }
        cout << "Final short path for random probability: " << randomNodeProbality[i] << " is: " << pathLenghtTotal/numberOfValidPath << endl;
    }    

    return 0;
}