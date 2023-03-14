#include <string>
#include <vector>
using namespace std;
int termsToTime[26];
int dateToTime(string date)
{
    string year, month, day;
    year = date.substr(2, 4);
    month = date.substr(5, 7);
    day = date.substr(8, 10);
    return stoi(year) * 336 + stoi(month) * 28 + stoi(day);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    int todayTime = dateToTime(today);
    for (string term : terms)
    {
        string alpha = term.substr(0, 1), num = term.substr(2);
        termsToTime[alpha[0] - 'A'] = stoi(num) * 28;
    }
    for (int i = 0; i < privacies.size(); ++i)
    {
        string privacie = privacies[i];
        int time = dateToTime(privacie);
        int diff = todayTime - time;
        if (termsToTime[privacie[11] - 'A'] <= diff)
            answer.push_back(i + 1);
    }
    return answer;
}