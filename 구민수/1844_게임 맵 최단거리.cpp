#include <vector>
#include <queue>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int solution(vector<vector<int>> maps)
{
    queue<pair<int, int>> bfs;
    bfs.push({0, 0});
    while (!bfs.empty())
    {
        auto cur = bfs.front();
        bfs.pop();
        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
            if (next.first < 0 | next.second < 0 | next.first >= maps.size() | next.second >= maps[next.first].size())
                continue;
            if (!maps[next.first][next.second] || maps[next.first][next.second] > 1)
                continue;
            if (next.first == maps.size() - 1 && next.second == maps[next.first].size() - 1)
            {
                return maps[cur.first][cur.second] + 1;
            }
            else
            {
                maps[next.first][next.second] = maps[cur.first][cur.second] + 1;
                bfs.push(next);
            }
        }
    }
    return -1;
}