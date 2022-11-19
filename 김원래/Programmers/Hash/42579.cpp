#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

bool compare2(pair<string,int> a, pair<string,int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,int> genre; 
    unordered_map<string,vector<pair<int,int>>> in_genre; 
    
    for(int i=0;i<genres.size();i++)
    {
        if(genre.end() == genre.find(genres[i]))
        {
            genre.insert(make_pair(genres[i],plays[i]));
            pair<int,int> p = make_pair(i,plays[i]);
            vector<pair<int, int>> tmp;
            tmp.push_back(p);
            in_genre.insert(make_pair(genres[i],tmp));
        }
        else
        {
            genre[genres[i]] += plays[i];
            in_genre[genres[i]].push_back(make_pair(i,plays[i]));
        }
    }
    
    vector<pair<string, int>> vec_genre(genre.begin(), genre.end());
    
    sort(vec_genre.begin(),vec_genre.end(),compare2);
    
    for(int i=0; i<vec_genre.size();i++)
    {
        string s = vec_genre[i].first;
        vector<pair<int,int>> v = in_genre[s];
        sort(v.begin(),v.end(),compare);
        answer.push_back(v[0].first);
        if(v.size() > 1)
        {
            answer.push_back(v[1].first);
        }
            
    }
    return answer;
}
