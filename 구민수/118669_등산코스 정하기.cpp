#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    vector<int> visted(n + 1, 10000001), type(n + 1);
    vector<vector<pii>> graph(n + 1, vector<pii>());
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int ret = 10000001, summ;
    for (vector<int> path : paths)
    {
        graph[path[0]].push_back({path[1], path[2]});
        graph[path[1]].push_back({path[0], path[2]});
    }
    for (int gate : gates)
        type[gate] = 1;
    for (int summit : summits)
        type[summit] = 2;
    for (int gate : gates)
    {
        visted[gate] = 1;
        pq.push({1, gate});
    }
    while (!pq.empty())
    {
        pii cur = pq.top();
        int curVal = cur.first, curIdx = cur.second;
        pq.pop();
        if (curVal > ret) // 현재 최솟값보다 큰 경우
            continue;
        for (pii next : graph[curIdx])
        {
            int nextVal = max(curVal, next.second), nextIdx = next.first;
            if (type[nextIdx] == 2)
            {
                if (nextVal == ret)
                    summ = min(summ, nextIdx);
                else if (nextVal < ret)
                {
                    ret = nextVal;
                    summ = nextIdx;
                }
            }
            if (type[nextIdx] || visted[nextIdx] <= nextVal || nextVal > ret) // 출입구인 경우, 이미 낮은 값으로 방문한 경우, 현재 최솟값보다 큰 경우
                continue;
            visted[nextIdx] = nextVal;
            pq.push({nextVal, nextIdx});
        }
    }
    return {summ, ret};
}