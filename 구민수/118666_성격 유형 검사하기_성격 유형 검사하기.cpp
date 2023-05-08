#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
unordered_map<string, pii> um = {{"RT", {0, 0}}, {"TR", {0, 1}}, {"CF", {1, 0}}, {"FC", {1, 1}}, {"JM", {2, 0}}, {"MJ", {2, 1}}, {"AN", {3, 0}}, {"NA", {3, 1}}};
char cm[4][2] = {{'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}};
int sum[4][2];
string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";
    for (int i = 0; i < survey.size(); ++i)
    {
        pii j = um[survey[i]];
        int score = -(choices[i] - 4);
        sum[j.first][j.second] += score;
    }
    for (int i = 0; i < 4; ++i)
        if (sum[i][0] < sum[i][1])
            answer += cm[i][1];
        else
            answer += cm[i][0];
    return answer;
}