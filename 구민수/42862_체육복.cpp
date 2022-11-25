/*
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    sort(lost.begin(), lost.end());
    int answer = n;
    bool res[31] = {
        false,
    },
         los[31] = {
             false,
         };
    for (int i = 0; i < lost.size(); ++i)
    {
        los[lost[i]] = true;
    }
    for (int i = 0; i < reserve.size(); ++i)
    {
        if (los[reserve[i]])
            los[reserve[i]] = false;
        else
            res[reserve[i]] = true;
    }
    for (int i = 0; i < lost.size(); ++i)
    {
        int j = lost[i];
        if (los[j])
        {
            if (res[j - 1])
            {
                res[j - 1] = false;
            }
            else if (res[j + 1])
            {
                res[j + 1] = false;
            }
            else
            {
                --answer;
            }
        }
    }
    return answer;
}
*/
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    bool res[31] = {
        false,
    },
         los[31] = {
             false,
         };
    for (int i = 0; i < lost.size(); ++i)
    {
        los[lost[i]] = true;
    }
    for (int i = 0; i < reserve.size(); ++i)
    {
        if (los[reserve[i]])
            los[reserve[i]] = false;
        else
            res[reserve[i]] = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (los[i])
        {
            if (res[i - 1])
            {
                res[i - 1] = false;
                ++answer;
            }
            else if (res[i + 1])
            {
                res[i + 1] = false;
                ++answer;
            }
        }
        else
        {
            ++answer;
        }
    }
    return answer;
}