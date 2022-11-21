#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    unordered_map<string, int> unMap;
    vector<int> vec;
    for (int i = 0; i < clothes.size(); ++i)
    {
        unMap[clothes[i][1]]++;
    }
    for (auto i : unMap)
    {
        answer *= (i.second + 1);
    }

    return answer - 1;
}