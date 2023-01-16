#include <string>
#include <vector>
#include <map>
using namespace std;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
map<pair<int, int>, bool> visted;
map<pair<pair<int, int>, pair<int, int>>, bool> edge;
int solution(vector<int> arrows)
{
    int answer = 0;
    pair<int, int> cur = {0, 0};
    visted[cur] = true;
    for (int arrow : arrows)
    {
        for (int i = 0; i < 2; ++i)
        {
            pair<int, int> next = {cur.first + dy[arrow], cur.second + dx[arrow]};
            if (!edge[{cur, next}] && !edge[{next, cur}])
            {
                if (visted[next])
                    ++answer;
            }
            visted[next] = true;
            edge[{cur, next}] = true;
            cur = next;
        }
    }
    return answer;
}