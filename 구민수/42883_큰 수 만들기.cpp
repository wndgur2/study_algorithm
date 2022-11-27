#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    for (int i = 0; number[i + 1]; ++i)
    {
        if (k == 0)
            break;
        if (number[i] < number[i + 1])
        {
            number.erase(i, 1);
            i = -1;
            k--;
        }
    }
    number.erase(number.length() - k, k);
    return number;
}