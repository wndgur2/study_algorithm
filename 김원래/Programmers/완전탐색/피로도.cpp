#include <string>
#include <vector>
#include <iostream>
using namespace std;

int M=-1;

void dfs(vector<vector<int>> dungeons, int idx, bool check[],int k,int times)
{
    if(k < dungeons[idx][0] || times >= dungeons.size())
    {
        if(times > M)
        {
            M=times;
        }
        return;
    }
    
    bool check_t[8];
    copy(check,check+8,check_t);
    check_t[idx] = true;
    k -= dungeons[idx][1];
    times++;
    bool flag=true;
    for(int i=0;i<dungeons.size();i++)
    {
        if(check_t[i]==false)
        {
            dfs(dungeons, i, check_t, k,times);
            flag=false;
        }
    }
    
    if(flag==true)
    {
        if(times > M)
        {
            M=times;
        }
        return;
    }
    
    cout << times;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    bool check[8] = {false,};
    for(int i=0;i<dungeons.size();i++)
    {
        dfs(dungeons,i,check,k,0);
    }
    answer=M;
    return answer;
}

/*

피로도 >= 0 (정수)

던전을 돌기위해서는 피로도가 필요하다.

최소필요피로도 = 던전을 돌기 위해 필요한 최소한의 필요도
소모피로도 = 던전을 탐험한 후 소모되는 피로도

던전을 돌기위해서는 = 최소필요피로도+소모피로도 ( 최소필요피로도 이상이어야 던전을 돌 수 있고,
던전을 돌면 소모피로도 만큼 닳는다.)

k=현재피로도
dungeons=(최소 필요 필요도, 소모피로도)

유저가 탐험할 수 있는 최대 던전수는?

dfs로 모든 경우의 수를 만들어서 풀면 될 것 같다.
*/