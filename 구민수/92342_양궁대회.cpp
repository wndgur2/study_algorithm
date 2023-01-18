#include <vector>
using namespace std;
int maxNum = 0;
vector<int> maxArr;
bool isLess(vector<int> &cur)
{
    if (maxArr.empty())
        return true;
    for (int i = 10; i >= 0; --i)
    {
        if (cur[i] > maxArr[i])
            return true;
        else if (cur[i] < maxArr[i])
        {
            return false;
        }
    }
    return false;
}

void dfs(vector<int> &info, vector<int> &cur, int idx, int chance, int mySum, int enemySum)
{
    if (idx == 11)
    {
        cur[idx - 1] = chance;
        int sumGap = mySum - enemySum;
        if (sumGap >= maxNum)
        {
            if (sumGap == maxNum && isLess(cur) || sumGap > maxNum)
                maxArr = vector<int>(cur);
            maxNum = sumGap;
        }
        return;
    }
    if (info[idx] < chance)
    {
        cur[idx] = info[idx] + 1;
        dfs(info, cur, idx + 1, chance - (info[idx] + 1), mySum + (10 - idx), (info[idx] ? enemySum - (10 - idx) : enemySum));
        cur[idx] = 0;
    }
    dfs(info, cur, idx + 1, chance, mySum, enemySum);
}

vector<int> solution(int n, vector<int> info)
{
    int enemySum = 0;
    for (int i = 0; i < 10; i++)
    {
        if (info[i])
            enemySum += 10 - i;
    }
    vector<int> answer(11);
    dfs(info, answer, 0, n, 0, enemySum);
    if (maxNum == 0)
        return vector<int>(1, -1);
    return maxArr;
}