#include<iostream>
using namespace std;

int main(){
    int a = 10, b = 3;
    float c = static_cast< float >(a)/static_cast< float >(b);
    cout << c << endl;
    return 0;
}