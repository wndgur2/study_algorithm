#include <iostream>
#include <vector>


using namespace std;

int d[100001];
vector<vector<int>> adj;

int dp(int cur, int pre)
{
	if (d[cur]) return d[cur];

	int ans = 1;

	for (int i = 0; i < adj[cur].size(); i++)
	{
		if (adj[cur][i] != pre)
		{
			ans += dp(adj[cur][i], cur);
		}
	}

	d[cur] = ans;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, R, Q;
	cin >> N >> R >> Q;

	adj.resize(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dp(R, 0);
	for (int i = 0; i < Q; i++)
	{
		int k;
		cin >> k;
		cout << d[k] <<"\n";
	}

	return 0;
}

/*
요구사항 :
루트가 존재하는 트리가 주어 졌을 때,
정점 U를 루트로 하는 서브트리에 속한 정점의 수를 출력해라

N-1번의 입력을 받는다. 트리의 간선의 정보가 주어진다.
쿼리가 주어진다. 쿼리는 노드의 번호를 뜻하고, 그 노드를 루트로하는 서브 트리의 속하는
노드 개수를 리턴한다.
	
데이터 :
int N : 정점의 수 ( 2~10만)
int R : 루트의 번호 (1~10만)
int Q : 쿼리의 수 ( 1~ 10만)


시간복잡도 :

	
아이디어 :
노드의 개수는 최대 100만개, 그리고 쿼리의 개수도 최대가 100만개이다.
그렇기 때문에 쿼리를 할때마다 서브트리를 찾는 연산을 하는 것은 비효율적일 것이다.
그래서 처음 계산 할때 미리 다해놓고 이를 배열에 저장하고 필요할 때 맞춰서 까먹게끔 하는 것이 좋은 방법이다.
	
*/