#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;
struct numObj
{
    int count;
    string number;
    int mask;
};

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers)
{
    unordered_map<int, bool> check;
    int answer = 0;
    queue<numObj> numQ;
    numQ.push({0, "", 0});
    while (!numQ.empty())
    {
        numObj num = numQ.front();
        numQ.pop();
        if (num.count == numbers.length())
        {
            if (num.number != "" && !check[stoi(num.number)] && isPrime(stoi(num.number)))
            {
                answer++;
                check[stoi(num.number)] = true;
            }
        }
        else
        {
            for (int i = 0; i < numbers.length(); i++)
            {
                if (!(num.mask & (1 << i)))
                    numQ.push({num.count + 1, num.number + numbers[i], (num.mask | (1 << i))});
            }
            numQ.push({num.count + 1, num.number, num.mask});
        }
    }
    return answer;
}