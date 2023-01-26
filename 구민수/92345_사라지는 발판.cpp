#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pos;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int dfs(vector<vector<int>> &board, pos p1, pos p2)
{
    if (!board[p1.first][p1.second]) // 내가 밞은 발판이 이미 떠난 발판인지 확인한다.
        return 0;
    int ret = 0;
    for (int i = 0; i < 4; ++i)
    {
        pos next = {p1.first + dy[i], p1.second + dx[i]};
        if (next.first < 0 || next.second < 0 || next.first >= board.size() || next.second >= board[0].size())
            continue;
        if (!board[next.first][next.second])
            continue;
        board[p1.first][p1.second] = 0; // 떠나니까 0이 된다.
        int val = dfs(board, p2, next) + 1;
        board[p1.first][p1.second] = 1;
        if (!(ret % 2) && val % 2)
            ret = val;
        else if (ret % 2 && val % 2)
            ret = min(val, ret);
        else if (!(ret % 2) && !(val % 2))
            ret = max(val, ret);
    }
    return ret;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc)
{
    return dfs(board, {aloc[0], aloc[1]}, {bloc[0], bloc[1]});
}