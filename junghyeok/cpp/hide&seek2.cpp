#include <iostream>
using namespace std;
#include <vector>
#define X 1000

int main(){
    int i, j;
    int me, goal;
    scanf("%d %d", &me, &goal);
    int states[X];
    vector<int> que;
    for(i=0; i<X; i++){
        states[i] = 0;
    }
    states[me] = 1;
    states[goal] = 2;

    return 0;
}