#include <string>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1}, dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int map[201][201];
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    queue<pair<int, int>> bfs;
    for (auto pos : rectangle)
        for (int i = (pos[1] << 1); i <= (pos[3] << 1); ++i)
            for (int j = (pos[0] << 1); j <= (pos[2] << 1); ++j)
            {
                map[i][j] = INT_MAX;
            }
    for (auto pos : rectangle)
        for (int i = (pos[1] << 1) + 1; i < (pos[3] << 1); ++i)
            for (int j = (pos[0] << 1) + 1; j < (pos[2] << 1); ++j)
            {
                map[i][j] = 0;
            }
    itemX <<= 1;
    itemY <<= 1;
    characterX <<= 1;
    characterY <<= 1;
    map[characterY][characterX] = 1;
    bfs.push({characterY, characterX});
    while (!bfs.empty())
    {
        auto cur = bfs.front();
        if (cur.first == itemY && cur.second == itemX)
            break;
        bfs.pop();
        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
            if (!map[next.first][next.second] || map[next.first][next.second] != INT_MAX) // 사각형 안에 있는가?, 이미 탐색한 곳인가?
                continue;
            map[next.first][next.second] = map[cur.first][cur.second] + 1;
            bfs.push({next.first, next.second});
        }
    }
    return (map[bfs.front().first][bfs.front().second] >> 1);
}