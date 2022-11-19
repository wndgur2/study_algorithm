#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string,int> map;
    for(int i=0;i<clothes.size();i++)
    {
        if(map.end()==map.find(clothes[i][1]))
        {
            map.insert(make_pair(clothes[i][1],2));
        }
        else
        {
            map[clothes[i][1]]++;
        }
    }
    
    int cnt=0;
    
    for(auto& i : map)
    {
        answer = answer* (i.second);
    }
   
    return answer-1;
}