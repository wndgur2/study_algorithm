#include <string>
#include <vector>
#include <algorithm>

using namespace std;
long long dp[101][101];
int solution(int m, int n, vector<vector<int>> puddles)
{
    for (auto puddle : puddles)
    {
        dp[puddle[1]][puddle[0]] = -1;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (dp[i][1] != -1)
            dp[i][1] = 1;
        else
            break;
    }
    for (int i = 1; i <= m; ++i)
    {
        if (dp[1][i] != -1)
            dp[1][i] = 1;
        else
            break;
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 2; j <= m; ++j)
        {
            if (dp[i][j] != -1)
                dp[i][j] = ((dp[i - 1][j] == -1 ? 0 : dp[i - 1][j]) + (dp[i][j - 1] == -1 ? 0 : dp[i][j - 1])) % 1000000007;
        }
    }
    return dp[n][m];
}