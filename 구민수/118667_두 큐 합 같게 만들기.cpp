#include <string>
#include <vector>
using namespace std;
typedef unsigned long long ull;
int solution(vector<int> queue1, vector<int> queue2)
{
    vector<vector<int>> q(2, (vector<int>()));
    q[0] = queue1;
    q[1] = queue2;
    vector<ull> sum(2);
    ull target;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < queue1.size(); ++j)
            sum[i] += q[i][j];
    target = sum[0] + sum[1];
    if (target % 2)
        return -1;
    target /= 2;
    int cur = sum[0] > sum[1] ? 0 : 1;
    int other = (cur + 1) % 2;
    for (int i = 0, j = 0, answer = 0; (i < queue1.size()) || (j < queue1.size()); ++answer)
    {
        if (sum[cur] == target)
        {
            return answer;
        }
        else if (sum[cur] > target)
        {
            sum[cur] -= q[cur][i];
            q[other].push_back(q[cur][i++]);
        }
        else
        {
            sum[cur] += q[other][j++];
        }
    }
    return -1;
}