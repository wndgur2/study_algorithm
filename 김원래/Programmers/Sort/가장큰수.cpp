#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.first > b.first;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<pair<int,int>> v;
    for(int i=0;i<numbers.size();i++)
    {
        if(numbers[i] == 0) v.push_back(make_pair(0,i));
        else if(numbers[i] == 1000) v.push_back(make_pair(1000,i));
        else if(numbers[i] < 1000 && numbers[i] > 99){
            v.push_back(make_pair(numbers[i]*1000+numbers[i],i));
        }
        else if(numbers[i] < 100 && numbers[i] >9){
            v.push_back(make_pair(numbers[i]*10000+numbers[i]*100+numbers[i],i));
        }
        else{
            v.push_back(make_pair((numbers[i]*100000)+(numbers[i]*10000)+(numbers[i]*1000)
                                  +(numbers[i]*100)+(numbers[i]*10)+numbers[i],i));
        }
    }
    sort(v.begin(),v.end(),compare);
    
    for(int i=0;i<v.size();i++)
    {
        string s = to_string(numbers[v[i].second]);
        answer += s;
    }
    
    if(v[0].first == 0)
    {
        answer = "0";
    }
    
    return answer;
}