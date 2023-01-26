#include <string>
#include <vector>
#include <queue>
using namespace std;
int ret = 0;
vector<vector<int>> map;
void dfs(int idx, int sheep, int wolf, vector<int> &info, queue<int> path)
{
    if (info[idx])
        ++wolf;
    else
    {
        ++sheep;
        ret = (ret > sheep) ? ret : sheep;
    }
    if (wolf >= sheep)
        return;
    for (int m : map[idx])
        path.push(m);
    for (int i = 0; i < path.size(); ++i)
    {
        int next = path.front();
        path.pop();
        dfs(next, sheep, wolf, info, path);
        path.push(next);
    }
}
int solution(vector<int> info, vector<vector<int>> edges)
{
    map = vector<vector<int>>(info.size(), vector<int>());
    for (auto edge : edges)
    {
        map[edge[0]].push_back(edge[1]);
    }
    dfs(0, 0, 0, info, {});
    return ret;
}