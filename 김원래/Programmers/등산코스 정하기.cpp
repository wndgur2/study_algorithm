#include <string>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <iostream>

using namespace std;

struct fromto{
    int arrival;
    int cost;
};


vector<vector<fromto>> graph;
vector<char> places;
vector<int> gates;

int min_intensity=2147483647;
int min_vertex=0;

int intensity[50001];

void search()
{
    memset(intensity, -1, sizeof(intensity));
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // 여기에는 가려고하는 정점에 cost와 정점이 저장됨. 여기서 cost값을 비교하여 cost가 작은 것 부터 처리 하게끔 해줍니다.
    
    for(int i=0;i<gates.size();i++)
    {
        intensity[gates[i]] = 0;
        pq.push(make_pair(0, gates[i]));
    }
    
    
    while(!pq.empty())
    {   
        int cost = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();
        
        
        if(cost > intensity[vertex]) continue;
        
        if(places[vertex] == 'S')
        {
            
            if(min_intensity == cost)
            {
                if(min_vertex > vertex) min_vertex = vertex;
            }
            
            else if(min_intensity > cost)
            {
                min_intensity = cost;
                min_vertex = vertex;
            }
            
            continue;
        }
        
        for(int i=0;i<graph[vertex].size();i++)
        {
            int next_cost = graph[vertex][i].cost;
            int next_vertex = graph[vertex][i].arrival;
            
            if(intensity[next_vertex] == -1 || (max(cost,next_cost) < intensity[next_vertex]))
            {
                intensity[next_vertex] = max(cost,next_cost);
                pq.push(make_pair(max(cost,next_cost), next_vertex));
            }
        }
    }
    
    
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> _gates, vector<int> summits) {
    vector<int> answer;
    gates = _gates;
    graph.resize(n+1);
    places.resize(n+1,'R');
    
    for(int i=0;i<paths.size();i++)
    {
        fromto node;
        node.arrival = paths[i][1];
        node.cost = paths[i][2];
        graph[paths[i][0]].push_back(node);
        
        node.arrival = paths[i][0];
        graph[paths[i][1]].push_back(node);
    }
    
    for(int i=0;i<gates.size();i++)
    {
        places[gates[i]] = 'G';
    }
    
    for(int i=0;i<summits.size();i++)
    {
        places[summits[i]] = 'S';
    }
    
    search();
    
    answer.push_back(min_vertex);
    answer.push_back(min_intensity);
    
    return answer;
}

/*

요구사항
XX산은 n개의 지점이 존재한다. 각 지점은 1부터 n까지의 번호가 붙어있다. 각 번호가 붙어 있는 곳은 출입구, 쉼터, 산봉우리이다.
각 지점은 양방향 통행이 가능하다.
각 지점을 연결하는 길에는 시간이 적혀있다.
등산 코스를 따라 이동하는 중 쉼터 혹은 산봉우리를 방문할 때마다 휴식을 취할 수 있으며, 휴식 없이 이동해야 하는 시간 중
가장 긴 시간을 해당 등산코스의 intensity라고 한다.
XX산의 출입구 한 곳에서 출발하여 산봉우리 중 한 곳만 방문한 뒤 다시 원래의 출입구로 돌아오는 등산코스를 정하려고 한다.
등산코스에서 출입구는 처음과 끝에 한 번, 산봉우리는 한 번만 포함하여 이동을 하는 방법 중
intensity가 최소가 되도록 등산코스를 짜고 그 등산코스에서 intensity값이 최소가 되는 등산코스를 포함하는 산봉우리와
그 최소가 되는 intensity를 배열에 추가하여 return 해라.


데이터
int n : 지점 수(2~50000)
vector<vector<int>> paths : [i,j,w] i번 지점과 j번 지점을 연결하는 등산로(이 등산로는 j로 가기위한 등산로이다.) w는 걸리는 시간
(1<=i<=j<=n) , (1<=w<=10000000)

vector<int> gates : 출입구들의 번호가 담긴 정수 배열 (1~n)
vector<int> summits : 산봉우리들의 번호가 담긴 정수 배열 (1~n)
선택되지 않은 것들은 쉼터가 되겠죠.

시간복잡도
priority_queue 연산의 시간복잡도는 O(ElogV)이다. 그 이유는 간선에 대해서 push를 진행 할 때마다 logV 시간이 걸리기 때문에,
최대 모든 간선에 대하여 priority_queue 연산을 진행하게 되면 O(ElogV)가 되는 것이다.
그런데 여기서 E=200000, V=50000이 최대기 때문에 이를 계산하면 20만*300 정도이다.

아이디어
1. 먼저 그래프를 만든다. 그래프는 unordred_map으로 i,j로 가는 길이 있다면 key값을 i로하고 value값으로 있는 vector에 j를 추가한다.
2. gates와 summits를 통합하는 배열을 하나 만들어 준다. 여기서 0은 출입구 1은 산봉우리 2는 쉼터로 명명한다.
3. 필요한 데이터는 다 만든 것으로 보이고, 이제 intensity를 최소화하는 경로를 탐색해야 한다. 처음 들어간 출입구를 통해서만 나올 수 있는 점을 기억해야 한다. 각 출입구를 시작으로 하여 bfs를 통하여 vector에 있는 값들을 탐색한다. 여기서 주의 해야 할 점은 처음 출입구를 제외한 새로운 출입구에 대해서는 탐색해서는 안된다. 그리고 처음 출입구로 돌아 왔을 때에는 최대 intensity값과 해당 intensity 값을 갖는 산봉우리의 번호를 저장하는 set을 출력한다. 그리고 bfs에서 튀어 나왔을 때의 intensity값과 현재까지 확인한 최소 intensity값을 비교하여 만약에 갱신한다.
unordred_map을 통하여 check를 만든다. 이 check는 이동했던 경로는 이동 하지 못하게 하는 역할을 한다. 만약에 i,j key가 등록이 돼 있다면, i,j는 이미 확인 한 것이니까 이동을 못한다. i,j와 j,i는 다른 것이다.


처음 bfs를 사용해서 풀이를 하려고 했을 때, 문제가 많이 발생했습니다. 그래서 결론적으로 cost가 주어지는 경우에 대해서
최적의 경로를 찾는 문제의 경우에는 다익스트라 알고리즘을 이용하는 것이 좋다라고 생각이 들었습니다.

다익스트라 알고리즘을 이용한 풀이는 먼저 bfs때와 같이 graph를 만들어 주었습니다. 이 graph는 서로 연결된 vertex간의 관계를 정의한
2차원 배열입니다.
그리고 각 vertex가 어떤 지점인지를 나타내는 places 배열을 만들어 주었습니다.
그리고 search 배열을 통하여 최적의 경로를 탐색합니다. 최적의 경로를 탐색 할 때 priority_queue(최소 힙)을 이용하였습니다.
여기서 최소 힙을 사용해준 이유는 intensity의 값을 구하는 것은 cost가 최소가 되는 경우를 찾는 것과 같습니다. 그렇기 때문에
현재 저장하고 있는 cost가 큰 값들은 의미가 없을 확룰이 높습니다. 따라서 cost가 낮은 것부터 연산을 합니다. 또한 다익스트라 알고리즘의 경우 이러한 최소힙을 사용하여 풀이를 하는 것이 일반적입니다.
그래서 맨 처음 intensity 배열을 만들어 -1로 초기화해줍니다. 이 intensity 배열의 갯수는 전체 vertex의 개수만큼을 할당합니다.
그리고 gates 배열을 돌면서 출입구의 intensity 값을 0으로 초기화 합니다.
이렇게 함으로써 intensity 배열에 -1이 들어가 있는 경우에는 아직 방문해보지 못한 vertex이며 누구든 이 vertex에 대해서 연산을 하게끔 해주고, gates를 0으로 초기화 함으로써 이보다 작은 cost는 나올 수 없기 때문에 gate는 탐색하지 못하게 합니다.
여기서 한가지 의아한 점이 있을 것입니다. gate를 출발하여 gate로 돌아오는 것이 목적인데 gate를 탐색하지 못하게 해도 되는 것인가?
이 의문점에는 양방향 그래프라는 것에 힌트가 있습니다. 한 곳을 찍었을 때의 cost 값을 유지하면서 다시 내려오는 방법에는 왔던 길을 다시 돌아오는 것이 최적일 것입니다. 만약에 다른 길로 가더라 하더라도 cost가 늘어날 뿐 줄어들지는 않습니다. 따라서 가는 길만을 계산하여도 cost값을 계산 할 수 있습니다.
그리고 최소힙에 출발지점을 push합니다. 여기서는 gate가 push 됩니다. push되는 형태는 pair 형태로 (cost, vertex)가 저장되어 push됩니다. 그리고 while문을 pq가 빌때까지 돕니다. pq의 첫번째 원소를 선택하여 현재 경로탐색 까지의 cost와 vertex를 저장합니다.
그리고 현재 cost와 intensity[vertex]의 값을 비교합니다. 만약에 cost값이 더 크다면 continue로 현재 연산을 건너뛰어 줍니다. 그 이유는 이미 더 낮은 cost를 통하여 해당 vertex를 탐색한 경우가 있기 떄문에 현재 연산이 의미가 없기 때문입니다.
그리고 현재 vertex가 산봉우리인지를 확인합니다. 여기서 저는 places배열에 'S'로 산봉우리를 표현했습니다. 만약에 산봉우리가 맞다면 min_intensity, min_vertex 각각을 현재 값과 비교하여 더 작은 값을 min_intensity에 저장합니다. 이 값은 추후에 정답이 됩니다.
그리고 continue를 때려줍니다. 밑에 연산은 graph를 탐색하여 현재 vertex와 연결된 간선에 대한 정보를 pq에 push하는 연산입니다.
하지만 이미 산봉우리의 도착을 했다면, 다음 연산을 통하여 cost가 늘어나거나 유지 될 뿐 줄어들지는 않습니다. 만약에 산봉우리에 도착하는 전체적인 intensity를 구하는 것이라면 이 부분에 continue를 해서는 안될 것입니다. 하지만 현재는 min_intensity를 구하는 것이기 때문에 아무 문제가 없습니다.
이제 산봉우리가 아닌 경우에 대해서를 살펴보면 for문을 통해 연결되어 있는 간선에 대하여 정보를 pq에 push합니다. push를 하기 전 확인 할 것이 있는데, 첫번째는 현재까지 경로상의 cost와 지금 가려고 하는 경로의 cost 상의 최댓값과 intensity 배열안에 다음 가려고하는 vertex의 cost 값을 비교하여 만약에 intensity 배열안의 cost 값이 더 작은 경우에 대해서는 push를 진행하지 않습니다. 연산이 의미가 없기 때문입니다. 그리고 intensity배열에 값이 -1인 경우에는 push를 허용 하게 해주어야 합니다. 현재 visit 배열을 만들어 주지 않고 intensity 배열 내부에서 -1 값으로 방문하지 않은 것을 표현하고 있기 때문에 이 또한 체크를 해주어야 합니다. 현재 가보지 않았다는 것은 무한대 값으로 채워져 있다는 것과 같기 때문입니다.
*/