#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int i, int j)
{
    return i > j;
}
int solution(vector<int> citations)
{
    sort(citations.begin(), citations.end(), compare);
    for (int i = 0; i < citations.size(); ++i)
    {
        if (citations[i] <= i)
            return i;
    }
    return citations.size();
}