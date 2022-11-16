/*
#include <vector>
#include <string>
typedef unsigned long long ll;
#define HASH_SIZE (1 << 22)
#define DIV (HASH_SIZE - 1)

using namespace std;
int getKey(string str)
{
    ll key = 5381;

    for (int i = 0; str[i]; ++i)
    {
        key = (((key << 5) + key) + (str[i]))%DIV;
    }

    return (int)(key & DIV);
}
int solution(vector<int> nums)
{
    bool check[HASH_SIZE];
    int answer = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        int hashKey = getKey(to_string(nums[i]));
        if (!check[hashKey])
        {
            check[hashKey] = true;
            answer++;
        }
    }
    return nums.size() / 2 <= answer ? int(nums.size() / 2) : answer;
}
*/
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> choice;
    for (int i = 0; i < nums.size(); ++i)
    {
        choice.insert(nums[i]);
    }
    return nums.size() / 2 <= choice.size() ? nums.size() / 2 : choice.size();
}