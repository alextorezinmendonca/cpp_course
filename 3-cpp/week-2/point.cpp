#include<iostream>

using namespace std;

class point{
    public:
        double getx(){
            return x;
        }
        double gety(){
            return y;
        }

        void setx(double v){
            x = v;
        }
        void sety(double v){
            y = v;
        }

        double x, y;

        // point(){
        //     cout << "constructor";
        // }

        ~point(){
            cout << "Destructor";
        }


};

point operator+ (point& p1, point& p2){
    point sum = {p1.x + p2.x, p1.y + p2.y};
    return sum;
};

ostream& operator<< (ostream& out, const point& p){
    out << "( " << p.x << ", " << p.y <<" )";
    return out;
};

int main(){
    point a = {3.5, 2.5}, {2.5, 4.5}, c;
    cout << "a = " << a << " b = " << b << endl;
    cout << "sum = " << a + b << endl;
    return 0;
}
    as