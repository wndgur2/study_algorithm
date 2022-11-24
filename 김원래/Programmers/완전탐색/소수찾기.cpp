#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> v;
set<int> s;

void dfs(int x, int y,bool check[])
{

    for(int i=0;i<v.size();i++)
    {
        if(check[i]==false)
            break;
        else
        {
            if(v.size()-1 == i)
                return;
        }
    }
    
    bool f_check[7];
    copy(check,check + 7, f_check);
    int a = (x*10)+v[y];
        
    
    s.insert(a);
    f_check[y] = true;
    
    for(int i=0;i<v.size();i++)
    {
        if(f_check[i] == false)
            dfs(a, i, f_check);
    }
}


int solution(string numbers) {
    int answer = 0;
    
    for(int i=0;i<numbers.size();i++)
        v.push_back(numbers[i]-48);
    
    bool check[7] = {false, };

    
    for(int i=0;i<numbers.size();i++)
        dfs(0,i,check);
    
    for(auto i=s.begin() ;i != s.end();i++)
    {   
        bool flag = true;
        cout << (*i) << " ";
        for(int j=2;j<=sqrt((*i));j++)
        {
            if((*i)%j == 0)
            {
                flag=false;
                break;
            }
        }
        if(flag==true && *i!=0 && *i!=1) answer++;
        
            
    }
        
    return answer;
}

//어떻게?