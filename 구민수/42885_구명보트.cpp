#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0, left = 0, right = people.size() - 1;
    sort(people.begin(), people.end());
    while (left <= right)
    {
        answer++;
        int weight = people[right];
        right--;
        int nextWeight = people[left];
        if (nextWeight + weight <= limit)
        {
            left++;
        }
    }
    return answer;
}