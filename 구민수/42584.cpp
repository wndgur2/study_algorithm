#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<int> indexStack;
    for (int i = 0; i < prices.size(); ++i)
    {
        while (!indexStack.empty() && prices[indexStack.top()] > prices[i])
        {
            answer[indexStack.top()] = i - indexStack.top();
            indexStack.pop();
        }
        indexStack.push(i);
    }
    while (!indexStack.empty())
    {
        answer[indexStack.top()] = prices.size() - indexStack.top() - 1;
        indexStack.pop();
    }
    return answer;
}