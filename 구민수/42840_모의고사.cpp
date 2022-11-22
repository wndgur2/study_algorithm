#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<int> choice[3] = {{1, 2, 3, 4, 5},
                             {2, 1, 2, 3, 2, 4, 2, 5},
                             {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    int score[3] = {
        0,
    };
    int highScore = 0;

    for (int i = 0; i < answers.size(); ++i)
    {
        int ans = answers[i];
        for (int j = 0; j < 3; ++j)
        {
            int k = i % choice[j].size();
            if (choice[j][k] == ans)
                score[j]++;
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        if (score[i] > highScore)
        {
            answer.clear();
            highScore = score[i];
            answer.push_back(i + 1);
        }
        else if (score[i] == highScore)
        {
            answer.push_back(i + 1);
        }
    }
    return answer;
}