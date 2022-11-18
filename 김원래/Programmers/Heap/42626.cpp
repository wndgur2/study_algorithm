#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0;i<scoville.size();i++)
    {
        q.push(scoville[i]);
    }
    
    while(q.size() > 1)
    {
        if(q.top() < K)
        {
            int a = q.top();
            q.pop();
            
            int b = q.top();
            q.pop();
            
            int c = a+(b*2);
            q.push(c);
            answer++;
        }
        
        else return answer;
        
    }
    
    if(q.top() < K) return -1;
    return answer;
}

//음식의 스코빌 지수를 K이상으로 만들고 싶어한다.
//모든 음식의 스코빌 지수를 K이상으로 만들기 위해
//스코빌 지수가 가장 낮은 두개의 음식을 아래와 같이 특별한 방법으로 섞어 새로운 음식으로 만들려고한ㄷ.
//섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두번쨰로 맵지 않은 음식의 스코빌 지수 *2)
