#include <string>
#include <vector>

using namespace std;

int ptr1=0, ptr2=0, cnt=0;
long sum1=0, sum2=0;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    int init_size = queue1.size();
    
    for(int i=0;i<queue1.size();i++)
    {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    
    while(true)
    {
        if(sum1 == sum2)
        {
            answer = cnt;
            break;
        }
        
        if(sum1 > sum2)
        {
            if(ptr1 >= queue1.size() || ptr1 >= 2*init_size) break;
            sum2+=queue1[ptr1];
            sum1-=queue1[ptr1];
            queue2.push_back(queue1[ptr1]);
            ptr1++;
            cnt++;
        }
        else
        {
            if(ptr2 >= queue2.size() || ptr2 >= 2*init_size) break;
            sum1+=queue2[ptr2];
            sum2-=queue2[ptr2];
            queue1.push_back(queue2[ptr2]);
            ptr2++;
            cnt++;
        }
            
    }
    
    
    return answer;
}

/*

요구사항
길이가 같은 두개의 큐가 주어진다. 하나의 큐를 골라 원소를 추출하고 추출된 원소를 다른 큐에 집어넣는 작업을 통해서
각 큐의 원소 합이 같도록 만드는 것이 목표이다.
이 때 필요한 작업의 최소 횟수를 구하고자 합니다. 한 번의 pop과 한번의 insert를 합쳐서 작업을 1회 수행 한 것으로 간주한다.
만약에 어떤 방법으로도 각 큐의 원소 합을 같게 만들 수 없는 경우에는 -1을 return 합니다.

데이터
vector<int> queue1,queue2 : int형 데이터 원소가 들어가 있는 큐이다. 최대 원소 30만개
queue의 원소 : 각 원소들은 1~10억의 수를 갖는다 -> 합을 long로 계산 하는 것이 바람직하다.
int ptr1 : queue1 포인트
int ptr2 : queue2 포인트
long sum1 : queue1 합
long sum2 : queue2 합
int cnt : 연산 횟수

시간복잡도
밑에 작성한 아이디어로라면 최대 60만번의 for문을 돌게 되므로 문제없이 시간복잡도를 통과할 것으로 보인다.

아이디어
전체 합이 큰 queue쪽에서 합이 작은 queue쪽으로 pop -> insert를 해줍니다.
양쪽 queue의 point 두개를 둡니다.
그리고 point를 통해서 양쪽 queue에서 pop->insert 할 차례인 지점을 point로 집어줍니다.
그리고 pop->insert 발생 시 point를 이동해줍니다.
그리고 pop한 value를 다른 한쪽의 queue에 value를 추가합니다.
pop->insert를 하려고 하는데 point가 queue의 size를 넘어가게 될 시 -1을 return 하도록합니다.
또한, 두번의 사이클 이상을 돌게되는 경우에 대해서도 -1을 return 하도록 합니다.
이 queue의 값들을 주고 받는 과정은 사이클이 계속 돌아가게 된다.
그렇기 때문에 이 사이클이 끝나는 지점을 찾아야 하는데, 그것이 바로 두번째 사이클을 돌게 되는 경우이다.
예를들어서,
1,2,3 / 4,5,6 이 있다면
왼쪽 큐의 입장에서 4,5,6을 다 받고, 1,2,3을 상대에게 내 준 후 다시 1,2,3을 받는 경우까지가 두번째 사이클인 것이다.


*/