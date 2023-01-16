#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;
vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    unordered_map<string, unordered_set<string>> targetMap, reportMap;
    unordered_map<string, bool> ban;
    for (string id : id_list)
    {
        targetMap.insert({id, unordered_set<string>()});
        reportMap.insert({id, unordered_set<string>()});
    }
    for (string r : report)
    {
        stringstream ss(r);
        string x, y;
        ss >> x >> y;
        targetMap[y].insert(x);
        reportMap[x].insert(y);
    }
    for (string id : id_list)
    {
        if (targetMap[id].size() >= k)
            ban[id] = true;
    }
    for (string id : id_list)
    {
        int cnt = 0;
        for (string r : reportMap[id])
        {
            if (ban[r])
                ++cnt;
        }
        answer.push_back(cnt);
    }
    return answer;
}