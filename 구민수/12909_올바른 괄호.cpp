#include <string>

using namespace std;

bool solution(string s)
{
    int left = 0, right = 0;
    bool answer = true;
    for (char c : s)
    {
        if ('(' == c)
        {
            ++left;
        }
        else
        {
            ++right;
            if (right > left)
                return false;
        }
    }
    if (right != left)
        return false;
    return true;
}