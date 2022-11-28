#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes)
{
    int answer = 0;
    int right = -30001;
    sort(routes.begin(), routes.end());
    for (vector<int> r : routes)
    {
        if (right < r[0])
        {
            ++answer;
            right = r[1];
        }
        else
        {
            if (right > r[1])
                right = r[1];
        }
    }
    return answer;
}