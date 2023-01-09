#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pos;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, H, W;
void getBlocks(vector<vector<int>> &tableVec, vector<vector<pos>> &blockVec, int fill) // 블록을 가져오는 BFS
{
    queue<pos> bfs;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (tableVec[i][j] == fill)
                continue;
            vector<pos> block;
            bfs.push({i, j});
            tableVec[i][j] = fill;
            block.push_back({i, j});
            while (!bfs.empty())
            {
                pos cur = bfs.front();
                bfs.pop();
                for (int i = 0; i < 4; ++i)
                {
                    pos next = {cur.first + dy[i], cur.second + dx[i]};
                    if (next.first < 0 || next.second < 0 || next.first >= H || next.second >= W)
                        continue;
                    if (tableVec[next.first][next.second] == fill)
                        continue;
                    tableVec[next.first][next.second] = fill;
                    bfs.push(next);
                    block.push_back(next);
                }
            }
            blockVec.push_back(block);
        }
    }
}
pos getMinBlock(vector<pos> &block) // 위치 조정을 위한 최솟값
{
    pos min = {51, 51};
    for (pos p : block)
    {
        if (min.first > p.first)
            min.first = p.first;
        if (min.second > p.second)
            min.second = p.second;
    }
    return min;
}
void sortBlock(vector<vector<pos>> &blockVec) // 최솟값으로 빼주어 0으로 맞춘 뒤 정렬
{
    for (int i = 0; i < blockVec.size(); ++i)
    {
        auto block = blockVec[i];
        pos min = getMinBlock(block);
        for (int j = 0; j < block.size(); ++j)
        {
            block[j].first -= min.first;
            block[j].second -= min.second;
        }
        sort(block.begin(), block.end());
        blockVec[i] = block;
    }
}
void rotateBlock(vector<vector<pos>> &blocks) // 회전
{
    for (int i = 0; i < blocks.size(); ++i)
    {
        auto block = blocks[i];
        for (int j = 0; j < block.size(); ++j)
        {
            int temp = block[j].first;
            block[j].first = -block[j].second;
            block[j].second = temp;
        }
        blocks[i] = block;
    }
}
int insertBlock(vector<vector<pos>> &boards, vector<vector<pos>> &blocks) // 동일한 부분을 제거해주며 진행
{
    int ret = 0;
    queue<pos> bfs;
    for (int k = 0; k < 4; ++k)
    {
        sortBlock(blocks);
        for (int i = 0; i < boards.size();)
        {
            bool isFind = false;
            for (int j = 0; j < blocks.size(); ++j)
            {
                if (boards[i] == blocks[j])
                {
                    ret += blocks[j].size();
                    blocks.erase(blocks.begin() + j);
                    isFind = true;
                    break;
                }
            }
            if (isFind)
                boards.erase(boards.begin() + i);
            else
                ++i;
        }
        rotateBlock(blocks);
    }
    return ret;
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    vector<vector<pos>> boards, blocks;
    H = game_board.size();
    W = game_board[0].size();
    getBlocks(table, blocks, 0);
    getBlocks(game_board, boards, 1);
    sortBlock(boards);
    return insertBlock(boards, blocks);
}