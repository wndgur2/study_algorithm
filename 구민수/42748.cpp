#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    for (vector<int> c : commands)
    {
        vector<int> nums;
        nums.insert(nums.begin(), array.begin() + c[0] - 1, array.begin() + c[1]);
        sort(nums.begin(), nums.end());
        answer.push_back(nums[c[2] - 1]);
    }
    return answer;
}