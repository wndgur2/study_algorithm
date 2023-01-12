#include <vector>
#include <algorithm>
using namespace std;
int solution(int distance, vector<int> rocks, int n)
{
    int answer = 0, high, mid, low = 0;
    sort(rocks.begin(), rocks.end());
    high = rocks[rocks.size() - 1];
    rocks.push_back(distance);
    while (low <= high)
    {
        mid = (low + high) / 2;
        int cnt = 0, rockPos = 0;
        for (int i = 0; i < rocks.size(); ++i)
            if (rocks[i] - rockPos < mid)
                ++cnt;
            else
                rockPos = rocks[i];
        if (cnt > n)
        {
            high = mid - 1;
        }
        else
        {
            if (answer < mid)
                answer = mid;
            low = mid + 1;
        }
    }
    return answer;
}