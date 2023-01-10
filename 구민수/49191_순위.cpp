#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(int n, vector<vector<int>> results)
{
    int answer = 0;
    vector<vector<int>> lMap(n + 1), wMap(n + 1);
    vector<bool> isVisted(n + 1);
    vector<int> cnt(n + 1);
    queue<int> q;
    for (auto r : results)
    {
        lMap[r[0]].push_back(r[1]);
        wMap[r[1]].push_back(r[0]);
    }
    for (int i = 1; i <= n; ++i)
    {
        fill(isVisted.begin(), isVisted.end(), false);
        q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int next : lMap[cur])
            {
                if (isVisted[next])
                    continue;
                isVisted[next] = true;
                ++cnt[next];
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        fill(isVisted.begin(), isVisted.end(), false);
        q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int next : wMap[cur])
            {
                if (isVisted[next])
                    continue;
                isVisted[next] = true;
                ++cnt[next];
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (cnt[i] == n - 1)
            ++answer;
    }
    return answer;
}