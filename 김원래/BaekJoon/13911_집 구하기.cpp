#include <iostream>
#include <vector>
#include <time.h>
#include <queue>
#define INF 2147483647


using namespace std;

enum STATUS{
	EMPTY,
	STARBUCKS,
	MACDONALD
};

struct comp {
	bool operator()(pair<int,int> a, pair<int,int> b)
	{
		return a.second > b.second;
	}
};

int V, E, M, x, S, y, answer = INF;
vector<vector<pair<int,int>>> adj;
vector<STATUS> status;
priority_queue<pair<int, int>, vector<pair<int,int>>, comp> m_pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, comp> s_pq;

vector<int> m_costs;
vector<int> s_costs;

void dikstra(priority_queue<pair<int, int>, vector<pair<int, int>>, comp>& pq, vector<int>& costs, const int& maximum)
{
	while (!pq.empty())
	{
		int cur_idx = pq.top().first;
		int cur_cost = pq.top().second;
		pq.pop();

		for (int i = 0; i < adj[cur_idx].size(); ++i)
		{
			int next_cost = cur_cost + adj[cur_idx][i].second;
			int next_idx = adj[cur_idx][i].first;

			if (next_cost < costs[next_idx] && next_cost < maximum+1)
			{
				costs[next_idx] = next_cost;
				pq.push(make_pair(next_idx, next_cost));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> V >> E;
	adj.resize(V+1);
	status.resize(V+1, STATUS::EMPTY);
	m_costs.resize(V + 1, INF);
	s_costs.resize(V + 1, INF);


	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}

	cin >> M >> x;

	for (int i = 0; i < M; ++i)
	{
		int idx;
		cin >> idx;
		m_pq.push(make_pair(idx,0));
		m_costs[idx] = 0;
		status[idx] = STATUS::MACDONALD;
	}

	cin >> S >> y;

	for (int i = 0; i < S; ++i)
	{
		int idx;
		cin >> idx;
		s_pq.push(make_pair(idx, 0));
		s_costs[idx] = 0;
		status[idx] = STATUS::STARBUCKS;
	}

	dikstra(m_pq, m_costs, x);
	dikstra(s_pq, s_costs, y);
	
	for (int i = 1; i < V + 1; ++i)
	{
		int m_cost = m_costs[i];
		int s_cost = s_costs[i];

		if (m_cost > x | s_cost > y | m_cost==0 | s_cost==0) continue;

		int sum = m_cost + s_cost;
		if (answer > sum) answer = sum;
	}

	if (answer == INF) cout << -1;
	else cout << answer;

	/*clock_t start, finish;
	double duration;
	start = clock();
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	std::cout << duration << "초" << "\n";*/




	return 0;
}

/*
요구사항 :
상혁이가 집을 사려고 한다.
다음 조건을 만족해야 한다.
1. 맥세권 : 맥도날드와 집 사이의 최단거리가 x이하인 집이다
2. 스세권 : 스타벅스와 집 사이의 최단거리가 y이하인 집이다.
3. 맥세권과 스세권을 만족하는 집 중 최단거리의 합이 최소인 집

최단거리 경로 알고리즘 -> 다익스트라



데이터 :
int V : 정점의 개수(3~1만)
int E : 도로의 개수(0~30만)
int M : 맥도날드 수
int x : 맥세권 조건(1~1억)
int S : 스타벅스 수
int y : 스세권 조건(1~1억)
vector<vector<pair<int,int>>> adj : 연결된 정점과 해당 정점으로 가는 비용이 저장됨
vector<STATUS> status : 정점 별로 빈공간인지 스타벅스인지 맥도날드인지 저장됨
priority_queue<pair<int,int>> pq : 다익스트라 알고리즘에서 먼저 계산 할 녀석을 올리기 위한 heap


시간복잡도 :


아이디어 :
2차원 vector로 인접행렬을 만들어 준다. 다익스트라 알고리즘을 사용하여
특정한 위치에서의 STARBUCKS의 최솟값, MACDONALD의 최솟값을 구한다.


*/