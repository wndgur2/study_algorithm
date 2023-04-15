#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <memory.h>

using namespace std;
vector<int> personality;
vector<vector<int>> adj;
int d[10001][2];


int dp(int cur, int pre, int isBest)
{
	if (d[cur][isBest] != -1) return d[cur][isBest];
	int ans = 0;

	if (isBest == 1)
	{
		ans += personality[cur];
		for (int i = 0; i < adj[cur].size(); i++)
		{
			if (adj[cur][i] == pre) continue;
			ans += dp(adj[cur][i], cur, 0);
		}
	}
	else
	{
		bool flag = false;
		for (int i = 0; i < adj[cur].size(); i++)
		{

			if (adj[cur][i] == pre) continue;
			
			if (dp(adj[cur][i], cur, 1) > dp(adj[cur][i], cur, 0)) flag = true;
			
			ans += max(dp(adj[cur][i], cur, 1), dp(adj[cur][i], cur, 0));
		}

	}

	d[cur][isBest] = ans;
	return ans;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(d, -1, sizeof(d));
	int N;
	cin >> N;
	personality.resize(N + 1);
	adj.resize(N + 1);
	for (int i = 1; i < N+1; i++)
	{
		int tmp;
		cin >> tmp;
		personality[i] = tmp;
	}

	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << max(dp(1, 0, 0), dp(1, 0, 1));

	return 0;
}

/*
요구사항 :
N개의 마을이 있고 이 N개의 마을은 트리구조로 돼있다.
방향성이 없기 때문에 간선이 연결만 돼 있으면 어디로든 이동이 가능하다.
다음 세가지 조건을 만족하는 마을을 우수마을로 선정한다.
1. 우수 마을 끼리는 인접 할 수 없다.
2. 우수마을로 선정되지 못한 마을은 적어도 하나의 우수 마을과 인접해야 한다.
3. 우수 마을로 선정된 마을 주민 수를 최대로 해야한다.
	
데이터 :
int N : 마을 수(1~1만)
vector<int> personality : 마을 별 인구 수
vector<vector<int>> adj : 마을을 트리롤 표현
bool flag : root가 우수마을이 아닌 경우의 자식 노드들이 전부 우수 마을이 아닌 경우를 골라내기 위한 flag이다.

시간복잡도 :
	
아이디어 :
전에 풀었던 문제와 같은 방식으로 풀 수 있을 것이라고 생각이 든다.
각각에 노드가 우수마을인 경우와 아닌 경우로 완전 탐색을 한다.
하나의 노드를 루트라고 가정을 하고 해당 루트가 우수마을 이라면,
자식 노드들은 우수마을이어서는 안된다.

하나의 노드를 루트라고 가정을 하고 해당 루트가 우수마을이 아니라면,
자식 노드들 중 하나 이상이 우수마을 이어야 한다.
그렇기 때문에 자식이 우수마을인 경우와 우수마을이 아닌 경우에 대해서 max 값을 더해야 할 것이다.
그런데 이 경우 모든 자식이 우수마을이 아닌경우가 생길 수가 있기 때문에
flag를 이용해서 모든 자식이 우수 마을이 아닌 경우를 골라낸다.
그리고 어떤 마을에 대해서 우수마을인 경우와 우수 마을이 아닌 경우의 주민 수의 차이를 비교해서
그 차 값이 가장 작은 것을 골라서 경우를 바꿔준다.

*/