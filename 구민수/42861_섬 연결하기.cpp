#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> costs)
{
    vector<vector<pair<int, int>>> v;
    bool visit[101] = {};
    int answer = 0;
    for (int i = 0; i < 101; ++i)
    {
        v.push_back(vector<pair<int, int>>());
    }
    for (vector<int> cost : costs)
    {
        v[cost[0]].push_back({cost[1], cost[2]});
        v[cost[1]].push_back({cost[0], cost[2]});
    }
    visit[0] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < v[0].size(); ++i)
    {
        pq.push({v[0][i].second, v[0][i].first});
    }
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (visit[node])
            continue;
        visit[node] = true;
        answer += cost;
        for (int i = 0; i < v[node].size(); ++i)
        {
            pq.push({v[node][i].second, v[node][i].first});
        }
    }
    return answer;
}