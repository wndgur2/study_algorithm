#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

struct wordObj
{
    int count;
    string word;
};
int solution(string word)
{
    char aeiou[] = {'A', 'E', 'I', 'O', 'U'};
    int answer = 0;
    queue<wordObj> q;
    set<string> dic;
    q.push({0, ""});
    while (!q.empty())
    {
        wordObj obj = q.front();
        q.pop();
        if (obj.count == 5)
        {
            dic.insert(obj.word);
        }
        else
        {
            ++obj.count;
            for (int i = 0; i < 5; ++i)
            {
                q.push({obj.count, obj.word + aeiou[i]});
            }
            q.push({obj.count, obj.word});
        }
    }
    for (string w : dic)
    {
        answer++;
        if (w == word)
            break;
    }
    return answer - 1;
}