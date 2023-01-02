#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> visted(n);
    queue<int> bfs;
    for (int i = 0; i < n; ++i)
    {
        if (visted[i]) // 이미 방문한 경우
            continue;
        ++answer;
        visted[i] = true;
        bfs.push(i);
        while (!bfs.empty())
        {
            int cur = bfs.front();
            bfs.pop();
            for (int j = 0; j < n; ++j)
            {
                if (cur == j || !computers[cur][j] || visted[j]) // 나 자신인 경우, 길이 없는 경우 ,이미 방문한 경우
                    continue;
                visted[j] = true;
                bfs.push(j);
            }
        }
    }
    return answer;
}