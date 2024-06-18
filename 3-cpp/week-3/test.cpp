#include <iostream>
#include <vector>
#include <random>
#include <tuple>
#include <numeric>
using namespace std;
int main(){
    vector<int> data(5,1);  
    //data.push_back(2);

    //data.push_back(3);
    int a = 5;
    double b = 2.5;
    int t = 0;
    int c = 1;
    t = a; 

    cout << a+b-t+c <<endl;
    cout << accumulate(data.begin(), data.end(), data[0]) << endl;
    return 0;
}