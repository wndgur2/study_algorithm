#include <vector>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int prev = -1;
    for (int ele : arr)
    {
        if (ele != prev)
        {
            answer.push_back(ele);
            prev = ele;
        }
    }
    return answer;
}