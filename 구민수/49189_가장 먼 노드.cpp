#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0, depth = 0;
    vector<vector<int>> map(n + 1);
    vector<bool> isVisted(n + 1);
    queue<pair<int, int>> wait;
    for (auto e : edge)
    {
        map[e[0]].push_back(e[1]);
        map[e[1]].push_back(e[0]);
    }
    wait.push({1, 1});
    isVisted[1] = true;
    while (!wait.empty())
    {
        auto cur = wait.front();
        wait.pop();
        for (auto m : map[cur.first])
        {
            if (isVisted[m])
                continue;
            isVisted[m] = true;
            pair<int, int> next = {m, cur.second + 1};
            if (depth == next.second)
            {
                ++answer;
            }
            else if (depth < next.second)
            {
                answer = 1;
                depth = next.second;
            }
            wait.push(next);
        }
    }
    return answer;
}