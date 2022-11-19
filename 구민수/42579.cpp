#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct Song
{
    int index;
    int play;
    bool operator<(const Song s) const
    {
        if (play < s.play)
        {
            return true;
        }
        else if (play == s.play)
        {
            return index > s.index;
        }
        return false;
    }
};
struct Genre
{
    string genre;
    int play;
    bool operator<(const Genre g) const
    {
        return play < g.play;
    }
};
vector<int> solution(vector<string> genres, vector<int> plays)
{
    unordered_map<string, int> countGenre;
    unordered_map<string, priority_queue<Song>> songMap;
    priority_queue<Genre> genrePQ;
    vector<int> answer;
    for (int i = 0; i < plays.size(); ++i)
    {
        countGenre[genres[i]] += plays[i];
        songMap[genres[i]].push({i, plays[i]});
    }
    for (auto c : countGenre)
    {
        genrePQ.push({c.first, c.second});
    }
    while (!genrePQ.empty())
    {
        Genre g = genrePQ.top();
        genrePQ.pop();
        for (int i = 0; i < 2; ++i)
        {
            answer.push_back(songMap[g.genre].top().index);
            songMap[g.genre].pop();
            if (songMap[g.genre].empty())
                break;
        }
    }
    return answer;
}