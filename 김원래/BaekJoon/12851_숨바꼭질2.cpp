#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int N, K;
vector<int> visit;
queue<pair<int, int>> q;
int min_cost;
int cnt = 0;



void bfs()
{
	while (!q.empty())
	{
		int cur_idx = q.front().first;
		int cur_cost = q.front().second;
		q.pop();
		visit[cur_idx] = 1;

		if (cur_idx == K)
		{
			min_cost = cur_cost;
			cnt += 1;
			return;
		}

		int next_idx, next_cost;

		for (int i = 0; i < 3; i++)
		{
			if (i == 0) next_idx = cur_idx * 2;
			else if (i == 1) next_idx = cur_idx + 1;
			else next_idx = cur_idx - 1;
		
			if (next_idx < 0 || next_idx > 100000) continue;
			if (visit[next_idx] == 1) continue;

			next_cost = cur_cost + 1;
			
			q.push(make_pair(next_idx, next_cost));
			
		}

		
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	visit.resize(100001, 0);

	cin >> N >> K;

	q.push(make_pair(N,0));
	visit[N] = 1;


	bfs();

	while (!q.empty())
	{
		int cur_idx = q.front().first;
		int cur_cost = q.front().second;
		q.pop();
		if (cur_idx == K && cur_cost == min_cost) cnt++;
	}

	cout << min_cost << "\n" << cnt;
	
	return 0;
}

/*
요구사항 :
전에 풀었던 문제와 같다. 하지만 여기서 순간이동을 할 때 0초 걸리던 것이 1초 걸리는 것으로 바뀌었다.
그리고 전에는 최소로 가는 시간을 구했다면 지금은 최소로 가는 방법의 수도 구해주어야 한다.

데이터 :


시간복잡도 :
bfs를 이용하기 때문에 시간복잡도를 생각하는 것이 중요하다. 최악의 경우라고 하면 모든 경우를 다 확인 해본 경우로 봣을때 30만번의 작업이 이루어질 것으로 보인다.
이 계산은 모든 정점 개수 10만개에 3가지의 경우의 수를 행하는 경우이다. 사실 이러한 일까지도 일어나지 않기 때문에 이보다 작을 것이라고 예상 할 수 있다.


아이디어 :
기존의 다익스트라 알고리즘을 사용하는 방식을 따르면서, 만약에 현재 입력 돼 있는 값과 같은 방식으로 가는 경우에는 cnt 값을 1만큼 증가 시킨다.
그러기 위해서 현재 최적값을 저장하고 있는 vector를 pair값을 담게끔 만들어준다.
이렇게 만들어주게 되면, 빼먹는 방법이 생겨나게 된다. 그래서 모든 방법을 탐색하는 BFS 방법을 사용해야 한다.
다익스트라 알고리즘을 사용 시에는 모든 방법을 탐색하지 않는다는 것을 기억하자.
기존의 bfs를 이용 할 때는 push 할 때 visit 값을 변경해주어 같은 level에 있는 연산자들이 visit에 등록한 정점에 못가게 했어야 했다.
하지만 위의 경우 모든 방법에 대해서 알아내야 하기 때문에 같은 level에 있는 연산자 까지도 계산을 해주어야 하기 때문에 pop을 한 이후에 visit을 등록 해주어야 한다.
내가 짠 코드에서는 최적의 방법을 찾아마자 bfs를 return하기 때문에 q안에 남아있는 것들을 계산해야 cnt 값을 구할 수 있다.


*/