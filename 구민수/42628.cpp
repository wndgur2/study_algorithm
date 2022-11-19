#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    priority_queue<int> highPQ;
    priority_queue<int, vector<int>, greater<int>> lowPQ;
    unordered_map<int, int> check;
    int count = 0;
    for (string operation : operations)
    {
        string op = operation.substr(0, 1);
        int num = stoi(operation.substr(2));
        if (op == "I")
        {
            highPQ.push(num);
            lowPQ.push(num);
            check[num]++;
            count++;
        }
        else if (count)
        {
            if (num > 0)
            {
                while (!check[highPQ.top()])
                {
                    highPQ.pop();
                }
                count--;
                check[highPQ.top()]--;
                highPQ.pop();
            }
            else
            {
                while (!check[lowPQ.top()])
                {
                    lowPQ.pop();
                }
                count--;
                check[lowPQ.top()]--;
                lowPQ.pop();
            }
        }
    }
    while (count && !check[highPQ.top()])
    {
        highPQ.pop();
    }
    while (count && !check[lowPQ.top()])
    {
        lowPQ.pop();
    }
    if (count)
    {
        answer.push_back(highPQ.top());
        answer.push_back(lowPQ.top());
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}