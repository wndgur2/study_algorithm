#include <vector>
#include <queue>
using namespace std;
int solution(vector<int> numbers, int target)
{
    int answer = 0;
    queue<pair<int, int>> bfs;
    bfs.push({0, 0});
    while (!bfs.empty())
    {
        auto cur = bfs.front();
        bfs.pop();
        if (cur.first == numbers.size())
        {
            if (cur.second == target)
                ++answer;
        }
        else
        {
            bfs.push({cur.first + 1, cur.second + numbers[cur.first]});
            bfs.push({cur.first + 1, cur.second - numbers[cur.first]});
        }
    }
    return answer;
}