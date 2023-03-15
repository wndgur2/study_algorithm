#include <string>
#include <vector>
using namespace std;
pair<int, int> getLenIdx(vector<int> &v, int cap, int _idx)
{
    int idx = _idx, len = 0;
    while (idx >= 0 && !v[idx])
    {
        --idx;
    }
    if (idx < 0)
        return {-1, 0};
    else
    {
        len = idx + 1;
    }
    while (idx >= 0 && cap)
    {
        if (v[idx] <= cap)
        {
            cap -= v[idx];
            v[idx] = 0;
            --idx;
        }
        else
        {
            v[idx] -= cap;
            cap = 0;
        }
    }
    return {idx, len};
}
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    int deliIdx = n - 1, pickIdx = n - 1;
    while (deliIdx >= 0 || pickIdx >= 0)
    {
        auto deli = getLenIdx(deliveries, cap, deliIdx);
        deliIdx = deli.first;
        auto pick = getLenIdx(pickups, cap, pickIdx);
        pickIdx = pick.first;
        answer += (deli.second > pick.second ? deli.second : pick.second) << 1;
    }
    return answer;
}