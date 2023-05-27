#include <string>
#include <vector>
using namespace std;
int min(int num1, int num2)
{
    return num1 > num2 ? num2 : num1;
}
int max(int num1, int num2)
{
    return num1 < num2 ? num2 : num1;
}
int solution(int alp, int cop, vector<vector<int>> problems)
{
    vector<vector<int>> dp(151, vector<int>(151, 301));
    int maxA = alp, maxC = cop;
    problems.push_back({0, 0, 1, 0, 1});
    problems.push_back({0, 0, 0, 1, 1});
    for (vector<int> problem : problems)
    {
        maxA = max(maxA, problem[0]);
        maxC = max(maxC, problem[1]);
    }
    dp[alp][cop] = 0;
    for (int i = alp; i <= 150; ++i)
        for (int j = cop; j <= 150; ++j)
        {
            if (i == maxA && j == maxC) // 도착했다면
                return dp[i][j];
            for (vector<int> problem : problems)
            {
                int reqA = problem[0], reqC = problem[1], getA = problem[2], getC = problem[3], time = problem[4];
                if (reqA > i || reqC > j) // 요구 사항을 못 넘는다면
                    continue;
                int k = min(i + getA, maxA), l = min(j + getC, maxC);
                dp[k][l] = min(dp[k][l],  dp[i][j] + time);
            }
        }
}