#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

char indicators[8] = {'R','T','C','F','J','M','A','N'};
int score[8] = {0, 3, 2, 1, 0, 1, 2, 3};
unordered_map<char,int> res;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    
    for(int i=0;i<8;i++)
    {
        res.insert(make_pair(indicators[i],0));
    }
    
    for(int i=0;i<survey.size();i++)
    {
        int score_idx = choices[i];
        if(score_idx > 4)
        {
            res[survey[i][1]] += score[score_idx];
        }
        else
        {
            res[survey[i][0]] += score[score_idx];
        }
    }
    
    for(int i=0;i<8;i=i+2)
    {
        if(res[indicators[i]] < res[indicators[i+1]])
        {
            answer.push_back(indicators[i+1]);
        }
        else
        {
            answer.push_back(indicators[i]);
        }
    }
    
    return answer;
}

/*

요구사항
MBTI테스트의 설문지와 같은 것을 만들려고 한다.
검사지의 질문은 n가지이며, 각 질문은 7개의 선택지가 있습니다.
7개의 선택지는 3 2 1 0 1 2 3의 점수를 부여하는데, 앞쪽 세개와 뒤쪽 세개는 점수를 주는 쪽이 다르다. MBTI에서 상반된 쪽에 점수를 줍니다.
상반된 두 지표에 대해서 점수가 같게 나오면 사전순으로 빠른 성격 유형을 검사자의 성격 유형으로 판단한다.

데이터
int selections[7] : 7개의 선택지
vector<string> survey : 질문마다 판단하는 지표
vector<int> choices : 검사자가 위의 survey를 선택한 선택지
unordered_map<char, int> res : 검사 지표들의 누적 점수를 기록합니다.

시간복잡도
시간복잡도를 고려 할 필요는 없어 보인다.

아이디어
16가지의 지표를 가지고 있는 map을 만들어서 값을 0으로 초기화 한다. 그리고 survey의 요소를 확인한다.
요소를 확인을 했다면 choices의 값을 확인하여 choices의 값에 해당하는 점수를 map의 지표에 더해준다.
마지막으로 R,T / C,F / J,M / A,N의 key값을 비교하고, 큰 값을 가지고 있는 경우에 대해서 그 값을 answer에 push해준다.
만약에 key값이 같다면 둘의 key중에서 사전순으로 더 높은 것을 골라준다.

*/