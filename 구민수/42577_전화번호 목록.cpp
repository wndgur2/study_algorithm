/*
실패
#include <string>
#include <vector>
#include <queue>
#define HASH_SIZE (1 << 20)
#define DIV (HASH_SIZE - 1)

using namespace std;
int getKey(int hash, char ch)
{
    hash = (hash << 4) + ch;
    return (int)(hash & DIV);
}

bool solution(vector<string> phone_book)
{
    bool answer = true;
    for (int i = 0; i < phone_book.size(); ++i)
    {
        int hash = 401;
        queue<pair<int, int>> otherPairQ;
        for (int j = i + 1; j < phone_book.size(); ++j)
        {
            otherPairQ.push({j, 401});
        }
        for (int j = 0; j < phone_book[i].length(); ++j)
        {
            hash = getKey(hash, phone_book[i][j]);
            int QL = otherPairQ.size();
            for (int k = 0; k < QL; ++k)
            {
                pair<int, int> otherPair = otherPairQ.front();
                otherPairQ.pop();
                otherPair.second = getKey(otherPair.second, phone_book[otherPair.first][j]);
                if (otherPair.second == hash)
                {
                    otherPairQ.push(otherPair);
                    if (phone_book[otherPair.first].length() == j + 1)
                        return false;
                }
            }
        }
        if (otherPairQ.size() > 0)
            return false;
    }
    return answer;
}
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book)
{
    unordered_map<string, bool> unMap;
    for (int i = 0; i < phone_book.size(); ++i)
    {
        unMap[phone_book[i]] = true;
    }
    for (int i = 0; i < phone_book.size(); ++i)
    {
        for (int j = 1; j < phone_book[i].length(); ++j)
        {
            if (unMap[phone_book[i].substr(0, j)])
                return false;
        }
    }
    return true;
}
