#include <string>
#include <vector>

using namespace std;

bool check[8];
int dfs(int k, int count, vector<vector<int>> &dungeons)
{
    int maxCount = count;
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!check[i] && k >= dungeons[i][0] && k >= dungeons[i][1])
        {
            check[i] = true;
            int bVal = dfs(k - dungeons[i][1], count + 1, dungeons);
            check[i] = false;
            if (bVal > maxCount)
                maxCount = bVal;
        }
    }
    return maxCount;
}
int solution(int k, vector<vector<int>> dungeons)
{
    return dfs(k, 0, dungeons);
}