#include <vector>
#include <set>
using namespace std;
int solution(int N, int number)
{
    if (N == number)
        return 1;
    set<int> dp[8];
    int NN = 0;
    for (int i = 0; i < 8; ++i)
    {
        NN = NN * 10 + N;
        dp[i].insert(NN);
    }
    for (int i = 1; i < 8; ++i)
    {
        for (int j = 0; j < i; ++j)
            for (int k : dp[j])
                for (int l : dp[i - j - 1])
                {
                    dp[i].insert(k * l);
                    dp[i].insert(k + l);
                    dp[i].insert(k - l);
                    if (l != 0)
                        dp[i].insert(k / l);
                }
        if (dp[i].find(number) != dp[i].end())
            return i + 1;
    }
    return -1;
}