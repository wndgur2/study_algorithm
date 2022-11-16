#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int time = 0, count = 0, wSum = 0;
    queue<int> bridgeQ;
    while (count != truck_weights.size())
    {
        if (bridge_length == bridgeQ.size())
        {
            wSum -= bridgeQ.front();
            bridgeQ.pop();
        }

        if (wSum + truck_weights[count] > weight)
        {
            bridgeQ.push(0);
        }
        else
        {
            bridgeQ.push(truck_weights[count]);
            wSum += truck_weights[count];
            count++;
        }
        time++;
    }
    int answer = time + bridge_length;
    return answer;
}