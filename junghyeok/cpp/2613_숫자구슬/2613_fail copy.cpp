#include <iostream>
#include <vector>

using namespace std;

/**
 * 그냥 N을 M개로 나누고 큰거에서 작은거로 나눠주기? > 최악 300
 * 
 * 누적합 구간합으로 그룹의 합 구하기
 * 
 * 그리디?
 * 
 * x 연쇄작용을 못함
 * 
*/

vector<int> beads;
vector<int> sums;
vector<int> borders;
vector<int> sumOfGroups;

int main(){
    int N, M, i;
    cin >> N >> M;

    beads = vector<int> (N);
    sums = vector<int> (N);
    borders = vector<int> (M);
    sumOfGroups = vector<int> (M);


    for(i=0; i<N; ++i){
        cin >> beads[i];
        if(i==0) sums[i] = beads[i];
        else sums[i] = sums[i-1] + beads[i];
    }
    for(i=0; i<M; ++i){
        borders[i] = i; // 맨 뒤 그룹에 몰아서줌
    }

    bool changed = true;
    int sumStart, sumEnd, maxBefore;

    while(changed){
        changed = false;
        // 각 그룹의 sum 구하기
        for(i=0; i<M; ++i){
            sumStart = sums[borders[i]];
            sumEnd = i == M-1? sums[N-1]: sums[borders[i+1]];
            sumOfGroups[i] = sumEnd - sumStart + beads[borders[i]];
        }
        // 각 그룹 돌면서 넘겨주면 최대값이 줄어드는지 보기 > 300
        for(i=0; i<M; ++i){
            if((borders[i+1] - borders[i] > 1) || (i==M-1 && borders[i] < N-1)) { // 2개 이상 인덱스가 있으면
                if( i<M-1 && sumOfGroups[i+1] < sumOfGroups[i]) { // 오른쪽이 나보다 작으면
                    // 오른쪽으로 넘겨서 합 최대값이 작아지면 넘겨
                    if(sumOfGroups[i] > max(sumOfGroups[i] - beads[borders[i+1]-1], sumOfGroups[i+1] + beads[borders[i+1]-1])){
                        sumOfGroups[i] -= beads[borders[i+1]-1];
                        sumOfGroups[i+1] += beads[borders[i+1]-1];
                        --borders[i+1];
                        changed = true;
                    }
                }
            }
            if((borders[i+1] - borders[i] > 1) || (i==M-1 && borders[i] < N-1)) { // 2개 이상 인덱스가 있으면
                if( i>0 && sumOfGroups[i-1] < sumOfGroups[i]){ // 왼쪽이 나보다 작으면
                    // 왼쪽으로 넘겨서 합 최대값이 작아지면 넘겨
                    if(sumOfGroups[i] > max(sumOfGroups[i] - beads[borders[i]], sumOfGroups[i-1] + beads[borders[i]])){
                        sumOfGroups[i] -= beads[borders[i]];
                        sumOfGroups[i-1] += beads[borders[i]];
                        ++borders[i];
                        changed = true;
                    }
                }
            }
        }
    }

    int maxSum = 0;

    for(i=0; i<M; ++i){
        maxSum = sumOfGroups[i] > maxSum? sumOfGroups[i]: maxSum;
    }
    cout << maxSum << endl;
    for(i=0; i<M-1; ++i){
        cout << borders[i+1] - borders[i] << ' ';
    }
    cout << N - borders[M-1] << endl;
    return 0;
}