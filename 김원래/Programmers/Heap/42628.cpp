#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>


using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer = {0,0};
    deque<int> q;
    
    for(int i=0;i<operations.size();i++)
    {
        if(operations[i].substr(0,1)=="I")
        {
            string s=operations[i].substr(2,operations[i].size()-2);
            int x = stoi(s);
            q.push_back(x);
            sort(q.begin(),q.end());
        }
        else if(!q.empty())
        {
            if(operations[i] == "D -1")
            {
                q.pop_front();
            }
            else
            {
                q.pop_back();  
            } 
        }
    }
    if(!q.empty())
    {
        deque<int>::iterator iter;
        iter = --q.end();
        answer[0] = *(iter);
        iter = q.begin();
        answer[1] = *(iter);
    }
    return answer;
}

// -45 333

// time complecity = n
