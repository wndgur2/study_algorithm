#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

vector<vector<int>> adj;
int d[1000001][2];

int dp(int cur, int pre, int is_adaptor)
{
	int ans = 0;
	if (d[cur][is_adaptor] != -1) return d[cur][is_adaptor];
	if (is_adaptor == 0)
	{
		for (int i = 0; i < adj[cur].size(); i++)
		{
			if (adj[cur][i] == pre) continue;
			ans += dp(adj[cur][i], cur, 1);
		}
		
	}
	else
	{
		ans += 1;
		for (int i = 0; i < adj[cur].size(); i++)
		{
			if (adj[cur][i] == pre) continue;
			ans += min(dp(adj[cur][i], cur, 1), dp(adj[cur][i], cur, 0));
		}
	}
	d[cur][is_adaptor] = ans;

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
	adj.resize(N+1);
	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << min(dp(1, 0, 0), dp(1, 0, 1));

	return 0;
}

/*
	요구사항 :
	SNS에서의 친구 구조를 그래프로 나타낸다 할 때,
	그래프의 노드는 사람, 간선은 사람간의 연결관계를 보여준다.
	여기서 사람은 얼리어답터 일 수 있고, 아닐 수도 있다.
	얼리어답터가 아닌 사람은 자신의 친구들이 모두 얼리어답터 일때, 내용을 수용한다.
	가능한 한 최소의 수의 얼리 어답터를 확보하여 모든 사람이 아이디어를 수용하게 만드는 문제이다.
	그래프는 끊어지지 않았고, 사이클 또한 없는 트리구조로 되어 있다.

	예를 들어 8명의 사람으로 이루어진 친과 관계 트리가 있다 할 때,
	2,3,4번 노드가 표현하는 사람들이 얼리 어답터라면, 얼리 어답터가 아닌
	사람들은 자신의 모든 친구가 얼리 어답터이기 때문에 새로운 아이디어를 받아들인다.
	
	데이터 :
	int n : 친구 관계 정점 수 (2~100만)
	int u,v : 친구 관계 간선
	vector<vector<int>> adj : 트리를 표현
	int d : dp를 위해서 이미 계산한 데이터에 대해서는 저장하기 위한 배열


	시간복잡도 :
	DFS를 이용하기 때문에 이미 계산한 데이터는 메모리에 저장을 해두고 사용해야 한다.
	
	아이디어 :
	트리를 표현하는 adj 배열을 하나 선언해준다. 트리는 사이클이 없는 그래프와 같다. 그렇기 때문에 그래프처럼 만들면 된다.
	이 문제에서 먼저 완전탐색을 하는 방법에 대해서 생각을 해본다.
	DFS를 통해서 완전 탐색을 할 수 있다. 각 노드의 대해서 해당 노드가 얼리어답터인 경우와 아닌 경우 두가지의 경우를 모두 확인을 하면 된다.
	그리고 주어진 자료가 사이클이 없는 트리이기 때문에 아무 한 노드를 root라고 생각을 하고 풀면 결국엔 모든 답이 다 같게 나올 것이다.
	하나의 노드를 딱 집어 root라고 만들고 난 이후에는 트리를 살펴 볼 때 위에는 살펴보지 않고 아래만을 살펴보면 된다.
	그 말은 즉 이미 방문한 노드는 재차 방문 할 필요가 없다는 것을 의미한다. 이를 위해서 나는 pre라는 파라미터를 두어 부모노드에 대해서는 재차 방문을 하지 않게 했다.
	이렇게 하면 아래 방향으로만 확인을 할 것이기 때문이다.
	그리고 이 문제의 경우 어차피 아래로 향하는 부분만을 확인하기 때문에 DP를 사용하나 안하나 *2 정도의 차이가 나지 않을까 하고,
	DP를 뺴고 풀었는데 시간초과가 나왔다. 그렇게 생각했던 이유는 DP를 사용해봐야 DP 함수를 두번밖에 사용안하기 때문에 앞에거를 계산하고 뒤에거에 계산 정도에밖에 사용하지 않으니까 라고 생각을 했다.
	근데 하나의 작업 자체가 워낙 오래 걸리다보니까 상수만큼 시간이 곱해지는 것만으로도 영향이 있었던 것으로 보인다.
	
*/