#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> v;
    cout<<commands.size();
    for(int i=0;i<commands.size();i++)
    {

        int x=commands[i][0];
        int y=commands[i][1];
        int z=commands[i][2];
        
        for(int j=x-1; j < y ;j++)
        {
            v.push_back(array[j]);
        }
        
        sort(v.begin(),v.end());
        answer.push_back(v[z-1]);
        
        v.clear();
    }
    return answer;
}