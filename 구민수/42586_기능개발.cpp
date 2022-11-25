#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int curDay = ceil((100 - progresses[0]) / (double)speeds[0]), count = 1;
    for (int i = 1; i < progresses.size(); ++i)
    {
        int day = ceil((100 - progresses[i]) / (double)speeds[i]);

        if (day <= curDay)
        {
            count++;
        }
        else
        {
            answer.push_back(count);
            curDay = day;
            count = 1;
        }
    }
    answer.push_back(count);
    return answer;
}