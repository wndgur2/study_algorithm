#include <string>
#include <vector>
#include <queue>
using namespace std;

struct obj
{
    int idx;
    int num;
};
int solution(vector<int> priorities, int location)
{
    int answer = 0;
    queue<obj> q;
    priority_queue<int> pq;
    for (int i = 0; i < priorities.size(); ++i)
    {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    while (!q.empty())
    {
        obj o = q.front();
        q.pop();
        if (o.num == pq.top())
        {
            pq.pop();
            ++answer;
            if (o.idx == location)
                return answer;
        }
        else
        {
            q.push(o);
        }
    }
}