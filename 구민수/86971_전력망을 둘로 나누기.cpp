#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires)
{
    bool visit[101];
    bool check[101][101];
    vector<vector<int>> wV;
    for (int i = 0; i < 101; i++)
    {
        wV.push_back(vector<int>());
    }
    int answer = 101;
    queue<int> bfs;
    for (vector<int> wire : wires)
    {
        wV[wire[0]].push_back(wire[1]);
        wV[wire[1]].push_back(wire[0]);
    }

    for (int i = 1; i <= wV.size(); ++i)
    {
        for (int j = 0; j < wV[i].size(); ++j)
        {
            if (check[i][wV[i][j]]) // 이미 분리해봤다면 넘김
                continue;
            check[i][wV[i][j]] = true;
            int record = 0;
            visit[i] = true;
            visit[wV[i][j]] = true;
            bfs.push(wV[i][j]);
            while (!bfs.empty()) // 더하는 부분
            {
                int curPos = bfs.front();
                visit[curPos] = true;
                bfs.pop();
                ++record;
                for (int k = 0; k < wV[curPos].size(); ++k)
                {
                    if (!visit[wV[curPos][k]])
                    {
                        bfs.push(wV[curPos][k]);
                    }
                }
            }
            bfs.push(i);
            while (!bfs.empty()) // 빼는 부분
            {
                int curPos = bfs.front();
                visit[curPos] = true;
                bfs.pop();
                --record;
                for (int k = 0; k < wV[curPos].size(); ++k)
                {
                    if (!visit[wV[curPos][k]])
                    {
                        bfs.push(wV[curPos][k]);
                    }
                }
            }
            if (abs(record) < answer)
                answer = abs(record);
            memset(visit, false, sizeof(visit));
        }
    }
    return answer;
}