#include<iostream>
#include<vector>
using namespace std;

/**
 * 2023.11.04 18:30
 * 1. 방향은 양옆으로만 꺾을 수 있다. 뒤로 갈 수 없다.
 * 2. 거울은 무제한. 놓을 수 없는 곳이 있음(방향을 전환할 수 없는 곳)
 * 
 * 그냥 BFS 하고 꺾은 횟수 기록
 * ! 최소 꺾횟인지 어떻게 판단?
 * 가장 빨리 들어오면 가장 적은 거울 개수인가? x 별로 상관 없다.
 * 꺾횟 제한하기? 0~n^2 ㄱㄱㄱㄱ
*/
int n;
vector<vector<char>> room;
int main(){
    cin >> n;
    room = vector<vector<char>> (n, vector<char> (n));
    

    for(int i=0; i<n*n; ++i){
        if(bfs(i, ))
    }


    return 0;
}