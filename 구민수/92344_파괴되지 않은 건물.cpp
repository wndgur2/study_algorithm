#include <vector>
using namespace std;
int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    vector<vector<int>> prefixSum(board.size() + 1, vector<int>(board[0].size() + 1));
    int answer = 0;
    for (auto s : skill)
    {
        if (s[0] == 1)
        {
            s[5] *= -1;
        }
        prefixSum[s[1]][s[2]] += s[5];
        prefixSum[s[1]][s[4] + 1] -= s[5];
        prefixSum[s[3] + 1][s[4] + 1] += s[5];
        prefixSum[s[3] + 1][s[2]] -= s[5];
    }
    for (int i = 0; i < prefixSum.size(); ++i)
        for (int j = 1; j < prefixSum[i].size(); ++j)
        {
            prefixSum[i][j] += prefixSum[i][j - 1];
        }
    for (int i = 1; i < prefixSum.size(); ++i)
        for (int j = 0; j < prefixSum[i].size(); ++j)
        {
            prefixSum[i][j] += prefixSum[i - 1][j];
        }
    for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < board[i].size(); ++j)
        {
            board[i][j] += prefixSum[i][j];
            if (board[i][j] >= 1)
                ++answer;
        }
    return answer;
}