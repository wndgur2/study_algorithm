#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dx[] = {10, 20, 30, 40};
int retAmount = 0, retMoney = 0;
void dfs(int idx, vector<vector<int>> users, vector<int> emoticons)
{
    if (idx < emoticons.size())
    {
        for (int i = 0; i < 4; ++i)
        {
            for (vector<int> &user : users)
            {
                if (user[0] <= dx[i])
                {
                    int price = emoticons[idx] * (100 - dx[i]) / 100;
                    user[2] += price;
                }
            }
            dfs(idx + 1, users, emoticons);
            for (vector<int> &user : users)
            {
                if (user[0] <= dx[i])
                {
                    int price = emoticons[idx] * (100 - dx[i]) / 100;
                    user[2] -= price;
                }
            }
        }
    }
    else if (idx == emoticons.size())
    {
        int curAmount = 0, curMoney = 0;
        for (vector<int> &user : users)
        {
            if (user[1] <= user[2])
                ++curAmount;
            else
                curMoney += user[2];
        }
        if (curAmount > retAmount)
        {
            retAmount = curAmount;
            retMoney = curMoney;
        }
        else if (curAmount == retAmount && curMoney > retMoney)
        {
            retMoney = curMoney;
        }
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    for (int i = 0; i < users.size(); ++i)
    {
        users[i].push_back(0);
    }
    dfs(0, users, emoticons);

    return {retAmount, retMoney};
}