/**
 * 2023.10.2 14:44
 * 
 * 0,0부터 오른쪽으로 탐색해서 0인 칸에 대하여
 *  availables = 1, 2, 3, 4, 5, 6, 7, 8, 9
 *  여기서 해당 행에 있는 숫자를 제거,
 *  해당 열에 있는 숫자를 제거,
 *  해당 (3x3) 칸에 있는 숫자를 제거
 *  남은 수들 중 하나씩 오름차순으로 해당 칸에 넣고,
 *  다음 빈칸을 탐색 (같은 방향으로)
 * 완성할 수 없다면 (false를 리턴 받는다면),
 * 다음 숫자를 넣고 다시 탐색. (백트래킹)
 * 
*/
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> board (9, vector<int> (9));
int maxDepth = 0;

vector<int> getAvailables(int y, int x){
    vector<int> availables;
    // get available numbers to put at y, x

    return availables;
}

bool DFS(int y, int x, int depth){
    if(depth == maxDepth) return true;
    vector<int> availables = getAvailables(y, x);
    // put number in y, x

    int newY = y, newX = x;
    while(board[y][x] > 0){
        // move right
        if(newX==8) {
            if(newY==8) break;
            ++newY;
            newX=0;
        }
        else ++newX;
    }

    while(!DFS(newY, newX, depth+1)){

    }
}

int main(){
    int i, j;
    for(i=0; i<9; ++i)
        for(j=0; j<9; ++j){
        	char ch = cin.get();
            while( ch == '\n' )
            {
            	ch = cin.get();
            }
        	board[i][j] = ch-'0';
            if(board[i][j]==0) ++maxDepth;
        }
    
    for(i=0; i<81; ++i)
        if(board[i/9][i%9]==0){
            DFS(i/9, i%9, 0);
            break;
        }
    
    for(i=0; i<9; ++i){
        for(j=0; j<9; ++j){
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}