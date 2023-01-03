#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> isVisted;
vector<string> answer;
bool cmp(vector<string> &a, vector<string> &b)
{
    return a[1] < b[1];
}
void dfs(string port, vector<vector<string>> tickets)
{
    answer.push_back(port);
    for (int i = 0; i < tickets.size(); ++i)
    {
        if (isVisted[i])
            continue;
        if (tickets[i][0] == port)
        {
            isVisted[i] = true;
            dfs(tickets[i][1], tickets);
            if (answer.size() == tickets.size() + 1)
                return;
            isVisted[i] = false;
        }
    }
    if (answer.size() == tickets.size() + 1)
        return;
    answer.pop_back();
}
vector<string> solution(vector<vector<string>> tickets)
{
    sort(tickets.begin(), tickets.end(), cmp);
    isVisted = vector<bool>(tickets.size());
    dfs("ICN", tickets);
    return answer;
}