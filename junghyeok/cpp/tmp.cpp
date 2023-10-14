#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
/**
 * 2023.10.14 13:00
 * 
 * N: 나무 농장 크기
 * M: 나무 개수
 * K: 보낼 기간(년)
 * 
 * 봄: 나무가 나이만큼 양분을 먹고 나이가 들거나, 양분을 먹지 못하고 양분이 된다. (어린 나무부터)
 * 여름: 죽은 나무의 나이/2가 해당 칸의 양분으로 변한다.
 * 가을: 나이가 5의 배수인 나무가 주변 8칸에 나이 1인 나무를 생성한다.
 * 겨울: 주어진 배열만큼 양분을 뿌린다.
 * 
 * 각 계절을 함수로 만들기
*/
struct ascendingAge
{
    inline bool operator() (vector<int> a, vector<int> b)
    {
        return (b[2] > a[2]);
    }
};

int N, M, K;
vector<vector<int>> trees;
vector<vector<int>> fertilizer;
vector<vector<int>> nutrition;
vector<vector<int>> deadTrees;

void pop_tree(int index){
    while(index < trees.size()-1){
        trees[index] = trees[index+1];
        ++index;
    }
    trees.pop_back();
}

// 봄: 나무가 나이만큼 양분을 먹고 나이가 들거나, 양분을 먹지 못하고 양분이 된다. (어린 나무부터)
void spring(){
    sort(trees.begin(), trees.end(), ascendingAge());

    int i_tree=0;
    while(i_tree < trees.size()){
        if(nutrition[trees[i_tree][0]][trees[i_tree][1]] >= trees[i_tree][2]){
            nutrition[trees[i_tree][0]][trees[i_tree][1]] -= trees[i_tree][2]++;
            ++i_tree;
        }
        else{
            deadTrees.push_back(trees[i_tree]);
            pop_tree(i_tree);
        }
    }
}

// 여름: 죽은 나무의 나이/2가 해당 칸의 양분으로 변한다.
void summer(){
    for(int i_tree=0; i_tree<deadTrees.size(); ++i_tree)
        nutrition[deadTrees[i_tree][0]][deadTrees[i_tree][1]] += deadTrees[i_tree][2]/2;
    deadTrees = {};
}

// 가을: 나이가 5의 배수인 나무가 주변 8칸에 나이 1인 나무를 생성한다.
void fall(){
    vector<pair<int, int>> ds = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    for(int i_tree=0; i_tree<trees.size(); ++i_tree){
        if(trees[i_tree][2]%5 != 0) continue;
        for(pair<int, int> d: ds){
            int newY = trees[i_tree][0]+d.first,
            newX = trees[i_tree][1]+d.second;
            if(newX < 0 || newX >= N || newY < 0 || newY >= N) continue;
            trees.push_back({newY, newX, 1});
        }
    }
}

// 겨울: 주어진 배열만큼 양분을 뿌린다.
void winter(){
    for(int y=0; y<N; ++y)
        for(int x=0; x<N; ++x)
            nutrition[y][x] += fertilizer[y][x];
}

int main(){
    cin >> N >> M >> K;
    fertilizer = vector<vector<int>> (N, vector<int> (N));
    nutrition = vector<vector<int>> (N, vector<int> (N, 5));

    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            cin >> fertilizer[i][j];

    int Y, X, age;
    while(M--){
        cin >> Y >> X >> age;
        trees.push_back({Y-1, X-1, age});
    }
    
    while(K--){
        // cout << "spring" << endl;
        spring();
        // cout << "summer" << endl;
        summer();
        // cout << "fall" << endl;
        fall();
        // cout << "winter" << endl;
        winter();
    }

    cout << trees.size() << endl;

    return 0;
}