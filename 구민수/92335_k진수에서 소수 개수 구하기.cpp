#include <string>
#include <cmath>
#include <stack>
using namespace std;
bool isPrime(long long num)
{
    if (num == 1)
        return false;
    for (long long i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
int solution(int n, int k)
{
    stack<char> s;
    string number = "";
    int answer = 0;
    while (n)
    {
        char cur = n % k + '0';
        if (cur == '0')
        {
            while (!s.empty())
            {
                number += s.top();
                s.pop();
            }
            if (!number.empty())
            {
                if (isPrime(stoll(number)))
                    ++answer;
                number = "";
            }
        }
        else
            s.push(cur);
        n /= k;
    }
    while (!s.empty())
    {
        number += s.top();
        s.pop();
    }
    if (!number.empty() && isPrime(stoll(number)))
        ++answer;
    return answer;
}