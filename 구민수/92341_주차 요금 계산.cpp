#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

int stringToTime(string number)
{
    string hour = number.substr(0, 2), min = number.substr(3, 2);
    return stoi(hour) * 60 + stoi(min);
}
vector<int> solution(vector<int> fees, vector<string> records)
{
    map<string, int> sum;
    map<string, pair<int, string>> state;
    vector<int> answer;
    for (string record : records)
    {
        stringstream ss(record);
        string time, id, trigger;
        ss >> time >> id >> trigger;
        pair<int, string> cur = {stringToTime(time), trigger};
        if (trigger == "OUT")
        {
            sum[id] += cur.first - state[id].first;
        }
        state[id] = cur;
    }
    for (auto s : state)
    {
        if (s.second.second == "IN")
            sum[s.first] += 1439 - s.second.first;
    }
    for (auto s : sum)
    {
        int time = s.second - fees[0];
        int fee = fees[1];
        if (time > 0)
        {
            fee += time / fees[2] * fees[3];
            if (time % fees[2])
                fee += fees[3];
        }
        answer.push_back(fee);
    }
    return answer;
}