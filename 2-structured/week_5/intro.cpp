#include <iostream>
using namespace :: std;

int fact(int n){
    long long f = 1;
    for(int i = 1; i <= n; i++) f *= i;
    return f;
}

int main(void){
    cout << "This program uses some feature not in C89\n";

    for(auto i = 0; i < 16; i++){
        cout << "fatorial of " << i << " is " << fact(i) << endl;
    }
 
    cout << "Thats all" << endl;
}

