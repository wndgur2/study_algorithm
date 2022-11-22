#include <string>
#include <vector>
typedef unsigned long long ll;
#define HASH_SIZE (1 << 21)
#define DIV (HASH_SIZE - 1)

using namespace std;
int getKey(string str)
{
    ll key = 5381;

    for (int i = 0; str[i]; ++i)
    {
        key = ((key << 5) + key) + (str[i]);
    }

    return (int)(key & DIV);
}
string solution(vector<string> participant, vector<string> completion)
{
    int count[HASH_SIZE];
    for (int i = 0; i < completion.size(); i++)
    {
        count[getKey(completion[i])]++;
    }
    for (int i = 0; i < participant.size(); i++)
    {
        int hashKey = getKey(participant[i]);
        count[hashKey]--;
        if (count[hashKey] == -1)
        {
            return participant[i];
        }
    }
}