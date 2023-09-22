#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> a = {1, 2, 3};
    vector<int> b = a;
    b[0] = 0;
    cout << "A: ";
    for(int i: a){
        cout << i << ' ';
    }
    cout << endl << "B: ";
    for(int i: b){
        cout << i << ' ';
    }
    a = b;
    b[0] = 100;
    cout << "A: ";
    for(int i: a){
        cout << i << ' ';
    }

    return 0;
}