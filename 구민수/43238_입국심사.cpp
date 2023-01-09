#include <vector>
using namespace std;
long long solution(int n, vector<int> times)
{
    long long answer, low = 0, high = 0, mid;
    for (int time : times)
        if (high < time)
            high = time;
    high *= n;
    while (low <= high)
    {
        long long sum = 0;
        mid = (low + high) / 2;
        for (int time : times)
            sum += (mid / time);
        if (sum >= n)
        {
            high = mid - 1;
            answer = mid;
        }
        else
            low = mid + 1;
    }
    return answer;
}