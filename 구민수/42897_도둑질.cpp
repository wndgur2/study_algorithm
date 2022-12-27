#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money)
{
    vector<vector<int>> dp(3, vector<int>(money.size()));
    dp[0][0] = money[0];
    dp[1][1] = money[1];
    dp[2][2] = money[2];
    if (money.size() != 3)
    {
        dp[0][2] = dp[0][0] + money[2];
    }
    for (int i = 3; i < money.size(); ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            dp[j][i] = money[i] + max(dp[j][i - 2], dp[j][i - 3]);
        }
    }
    return max(max(max(dp[0][money.size() - 2], dp[0][money.size() - 3]), max(dp[1][money.size() - 1], dp[1][money.size() - 2])), max(dp[2][money.size() - 1], dp[2][money.size() - 2]));
}