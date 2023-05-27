#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647

using namespace std;

priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int N;
int K;

vector<int> res;


void check(int cost, int cur_idx)
{
	int next_idx = cur_idx*2;
	if (!(next_idx < 0 || next_idx > 100000))
	{
		if (res[next_idx] > cost)
		{
			res[next_idx] = cost;
			pq.push(make_pair(cost, next_idx));
		}
	}

	next_idx = cur_idx + 1;
	if (!(next_idx < 0 || next_idx > 100000));
	{
		if (res[next_idx] > cost + 1)
		{
			res[next_idx] = cost + 1;
			pq.push(make_pair(cost + 1, next_idx));
		}
	}


	next_idx = cur_idx - 1;
	if (!(next_idx < 0 || next_idx > 100000))
	{
		if (res[next_idx] > cost + 1)
		{
			res[next_idx] = cost + 1;
			pq.push(make_pair(cost + 1, next_idx));
		}
	}

}

void solve()
{
	while (!pq.empty())
	{
		pair<int, int> top = pq.top();
		pq.pop();

		int cost = top.first;
		int cur_idx = top.second;

		check(cost, cur_idx);
	}
}

int main()
{
	res.resize(100001, INF);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	cin >> K;
	res[N] = 0;
	pq.push(make_pair(res[N], N));

	solve();

	cout << res[K];

	return 0;
}

/*
요구사항 :
수빈이는 동생과 숨바꼭질을 하고 있다.
수빈이가 현재 점 N에 있고, 동생은 점 K에 있다.
수빈이는 걷거나 순간이동을 할 수 있다.
만약 수빈이의 위치가 X일때, 걷는다면 1초 후에 X-1또는 X+1로 이동가능하다.
순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동이 가능하다.
수빈이와 동생의 위치가 주어졌을때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇
초 후인지 구하는 프로그램을 작성하라

움직이는건 술래인 수빈이만 일 것이다.
최대한 순간이동을 하여 목적지에 가까워 지는 것이 바람직하다.

데이터 :
int N : 수빈의 위치(0~10만)
int K : 동생의 위치(0~10만)
int res[10만] : 간선으로 가는 길의 최소 비용
priority_queue<pair<int,int>> : <정점의비용, 정점의번호>

시간복잡도 :
현재 정점의 개수가 N이다. 이에 대하여 다익스트라 알고리즘을 적용하게 되면, 시간복잡도는 ElogV = ElogN = 20만*300 (대략)

아이디어 :
일단 점에 대해서 접근 할 수 있는 공간 자체가 10만개가 있을 것이다.
이 10만개에 대해서 지금 현재 위치에서 할 수 있는 최선을 다하면서 문제를 해결해나간다.
처음 위치에서의 2의 배우는 0초가 걸릴 것이다. 현재 이 그래프의 경우 움직일 수 있는 지점이
왼쪽인덱스 아니면 오른쪽 인덱스 이기 때문에 이에 대해서만 확인을 해준다.
현재 위치에 대해서 왼쪽 인덱스 현재의 비용과 현재 인덱스에서+1 한 값과의 비교를 통해서 어떤 값이
더 작은지를 확인한다. 이 때 현재 입력한 값이 전 값보다 최단거리라면 이를 heap구조에 추가를 한다.
그 다음 최소 heap에서 요소를 하나 꺼내서 위와 같은 일을 반복해준다. 이 일을 heap이 빌 때까지 해준다.
그리고 결과적으로 동생의 위치에서의 값을 출력하면 답이 나온다.

*/