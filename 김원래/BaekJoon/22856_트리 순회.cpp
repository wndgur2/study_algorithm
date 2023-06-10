#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

vector<vector<int>> adj;
vector<int> visit;
vector<int> roots;
int N, last_node;

int middle_circuit(int n)
{
	if (adj[n][1] == -1) return n;
	return middle_circuit(adj[n][1]);
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> N;

	adj.resize(N + 1);
	visit.resize(N + 1,0);
	roots.resize(N + 1);
	for (int i = 1; i < N + 1; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(b);
		adj[a].push_back(c);
		if(b != -1) roots[b] = a;
		if(c != -1) roots[c] = a;

	}

	last_node = middle_circuit(1);

	int cnt = 0;
	int cur_idx = 1;

	while (true)
	{
		if (adj[cur_idx][0] != -1 && visit[adj[cur_idx][0]] == 0)
		{
			++cnt;
			cur_idx = adj[cur_idx][0];
			visit[cur_idx] = 1;

		}
		else if (adj[cur_idx][1] != -1 && visit[adj[cur_idx][1]] == 0)
		{
			++cnt;
			cur_idx = adj[cur_idx][1];
			visit[cur_idx] = 1;
			
		}
		else if (cur_idx == last_node) break;
		else
		{
			++cnt;
			cur_idx = roots[cur_idx];
		}
	}

	cout << cnt;

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
노드가 N개인 이진트리가 있다.
유사 중위 순회
1. 왼쪽 자식 노드 존재하고 방문x -> 방문
2. 오른쪽 자식 노드 존재하고 방문x -> 방문
3. 유사 중위 순회의 끝 -> 종료
4. 부모 노드가 존재 -> 부모 노드로이동


데이터 :


시간복잡도 :
N=1일때 1, N=2일 때 2, N=3 일 때 4, N=3 일때 왼쪽으로 늘어진 경우 3
부모노드는 최대 2개의 자식노드를 갖는다. -> 자식노드에서 부모노드로 돌아 올 수 있다.
이를 4라는 시간이 걸린다 하면,
그리고 그 자식노드 또한 최대 2개의 자식 노드를 갖는다.
또 그 밑에서 4라는 시간이 걸린다.
현재 N이 최대 10만 이기 때문에 대략 40만의 시간이 걸린다. 모든 경우를 살펴봐도 문제가 되지
않을 것이다.


아이디어 :
첫번째로 중위순회의 결과로 나오는 마지막 노드가 무엇인지 알아야 한다.
이를 위해서 중위순회를 먼저 진행을 하고 마지막 노드 번호를 가져온다.
1,2,3,4를 확인하고 돌게끔 만들어 준다.


*/