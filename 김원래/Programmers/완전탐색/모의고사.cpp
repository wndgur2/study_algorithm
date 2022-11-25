#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int,int>> v;
    
    int order_two[4] = {1,3,4,5};
    int cnt_two = 0;
    int order_three[10] = {3,3,1,1,2,2,4,4,5,5};
    int cnt_three = 0;
    
    for(int i=0;i<3;i++)
    {
        v.push_back(make_pair(0,i+1));
    }
    
    for(int i=0;i<answers.size();i++)
    {
        if(answers[i] == i%5+1)
        {
            v[0].first++;
        }
        
        if(i%2 == 0){
            if(answers[i]==2) v[1].first++;
        }
        else
        {
            if(answers[i] == order_two[cnt_two%4])
            {
                v[1].first++;
            }
            cnt_two++;
        }
        
        
        if(answers[i]==order_three[cnt_three%10])
        {
            v[2].first++;
        }
        cnt_three++;
        
    }
    

    sort(v.begin(),v.end(),compare);
    
    int x=v[0].first;
    answer.push_back(v[0].second);
    
    for(int i=1;i<3;i++)
    {
        if(x==v[i].first)
        {
            answer.push_back(v[i].second);
        }
    }
    
    if(x==0)
    {
        answer.clear();
    }
    
    return answer;
}

//수포자 삼인방이 수학문제를 전부 찍는다.
//1번 수포자 : 1,2,3,4,5 (i%5)
//2번 수포자 : 2,1,2,3,2,4,5, (i%2 == 0 일때는 무조건 2, i%2 == 1 일때는 1,3,4,5를 돌면서)
//3번 수포자 : 33,11,22,44,55 (3,1,2,4,5 순서로 돌면서 연속 두번씩)
