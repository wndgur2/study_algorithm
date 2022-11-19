#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cmath>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string,int> map;
    for(int i=0; i<phone_book.size() ;i++)
    {
        map.insert(make_pair(phone_book[i],1));
    }
    
    
    for(int i=0; i<phone_book.size();i++)
    {
        for(int j=0;j<phone_book[i].size();j++)
        {
            if(map.end() != map.find(phone_book[i].substr(0,j)))
            {
                return false;
            }
        }
    }
    return answer;
}