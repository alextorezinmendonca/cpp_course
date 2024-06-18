#include <iostream>
#include <vector>

// Sum program will convert from C code to C++
// Will sum all number between 0 and N
// Author: Alex Mendonça
// Linkedin: https://www.linkedin.com/in/mendoncaalex/


using namespace std;

//Global variable
const int N = 40;

//In line function to sum values in pointer
inline void sum(int& acc, vector<int>& data) { 

    for(auto i = 0; i < data.size(); i++) {
        acc = acc + data[i];
    }; 
};

int main(){

    vector<int> data;
    int acc = 0;

    //Add all values from 0 to N in vector
    for(int i = 0; i < N; i++){
        data.push_back(i);
    }

    sum(acc, data);
    cout << "The sum is: " << acc;
    cout << "\n";

    return 0;
}