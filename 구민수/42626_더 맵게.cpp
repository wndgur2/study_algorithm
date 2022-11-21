#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i : scoville)
    {
        pq.push(i);
    }
    while (!pq.empty())
    {
        if (pq.top() >= K)
            return answer;
        int temp = pq.top();
        pq.pop();
        if (pq.empty())
            return -1;
        temp += (pq.top() * 2);
        pq.pop();
        pq.push(temp);
        ++answer;
    }
    return -1;
}