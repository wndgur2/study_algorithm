#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int maxDp[102][102], minDp[102][102];
int solution(vector<string> arr)
{
    int len = 0;
    bool minus = false;
    int num;
    for (string s : arr)
    {
        if (s == "-")
        {
            minDp[len][len] = num;
            maxDp[len][len++] = num;
            minus = true;
        }
        else if (s == "+")
        {
            minDp[len][len] = num;
            maxDp[len][len++] = num;
        }
        else
        {
            num = stoi(s);
            if (minus)
            {
                num *= -1;
                minus = false;
            }
        }
    }
    minDp[len][len] = num;
    maxDp[len][len++] = num;
    for (int i = 1; i < len; ++i) // 범위
    {
        for (int j = 0; j < len - i; ++j) // 위치
        {
            int minVal = 1000001, maxVal = -1000001;
            for (int k = 0; k < i; ++k) // 위치의 범위
            {
                if (k == 0 && minDp[j][j + k] < 0)
                {
                    int minM = minDp[j][j + k] - minDp[j + k + 1][j + i];
                    int minMaxM = minDp[j][j + k] - maxDp[j + k + 1][j + i];
                    minVal = min(minM, minVal);
                    maxVal = max(minM, maxVal);
                    minVal = min(minMaxM, minVal);
                    maxVal = max(minMaxM, maxVal);
                }
                if (k == 0 && maxDp[j][j + k] < 0)
                {
                    int maxM = maxDp[j][j + k] - maxDp[j + k + 1][j + i];
                    int maxMinM = maxDp[j][j + k] - minDp[j + k + 1][j + i];
                    minVal = min(maxM, minVal);
                    maxVal = max(maxM, maxVal);
                    minVal = min(maxMinM, minVal);
                    maxVal = max(maxMinM, maxVal);
                }
                int minP = minDp[j][j + k] + minDp[j + k + 1][j + i];
                int maxP = maxDp[j][j + k] + maxDp[j + k + 1][j + i];
                minVal = min(minP, minVal);
                maxVal = max(maxP, maxVal);
            }
            minDp[j][j + i] = minVal;
            maxDp[j][j + i] = maxVal;
        }
    }
    return maxDp[0][len - 1];
}