#include <string>
#include <vector>
using namespace std;
int ret = 51;
vector<bool> visted;
void dfs(string cur, string target, vector<string> words, int cnt)
{
    if (cur == target)
    {
        if (ret > cnt)
            ret = cnt;
        return;
    }
    for (int i = 0; i < words.size(); ++i)
    {
        if (visted[i])
            continue;
        int diff = 0;
        for (int j = 0; j < cur.size(); ++j)
        {
            if (cur[j] != words[i][j])
                ++diff;
        }
        if (diff <= 1)
        {
            visted[i] = true;
            dfs(words[i], target, words, cnt + 1);
            visted[i] = false;
        }
    }
}
int solution(string begin, string target, vector<string> words)
{
    visted = vector<bool>(words.size());
    dfs(begin, target, words, 0);
    return ret == 51 ? 0 : ret;
}