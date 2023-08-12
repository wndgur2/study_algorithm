#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

struct Node
{
	int parent;
	int level;
	Node(int parent, int level)
	{
		this->parent = parent;
		this->level = level;
	}
};

int N,M;
vector<Node> tree;
vector<vector<int>> nodes;


void make_tree(int x)
{
	for (int i = 0; i < nodes[x].size(); ++i)
	{
		if (tree[nodes[x][i]].level == 0)
		{
			tree[nodes[x][i]].level = tree[x].level + 1;
			tree[nodes[x][i]].parent = x;
			make_tree(nodes[x][i]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> N;
	tree.resize(N + 1, Node(0, 0));
	nodes.resize(N + 1, vector<int>());
	tree[1].level = 1;
	tree[1].parent = 1;

	for (int i = 0; i < N-1; ++i)
	{
		int a, b;
		cin >> a >> b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}

	make_tree(1);

	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		int aLevel = tree[a].level;
		int bLevel = tree[b].level;

		if (aLevel > bLevel)
		{
			int Cnt = aLevel - bLevel;
			while (Cnt--)
			{
				a = tree[a].parent;
			}
		}
		else if (aLevel < bLevel)
		{
			int Cnt = bLevel - aLevel;
			while (Cnt--)
			{
				b = tree[b].parent;
			}
		}

		while (a != b)
		{
			a = tree[a].parent;
			b = tree[b].parent;
		}

		cout << a << '\n';
	}


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
트리가 주어진다. 
루트는 1번이다. 
각 노드는 1~N까지의 번호를 가지고 있다.
두 노드의 쌍이 주어졌을 때 두 노드의 가장 가까운 공통 조상이 몇번인지 출력하라


데이터 :
int N, M : N은 노드의 수 (2 ~ 5만) M은 결과 값을 내는 입력 쌍(1 ~ 1만)
vector<Node> tree : tree를 만들기 위한 배열



시간복잡도 :
5만 x 1만 약 5억줄의 연산이 있을 것이라고 생각이 들고, 그 것은 시간제한 3초를 넘지 않을 것이다.

아이디어 :
먼저 N을 기준으로 입력 받은 것을 토대로 tree를 만들어 준다.
M과 관련된 두 개의 입력을 받았을 때, 양 쪽의 tree 중에서 level 값이 낮은 것을 기준으로,
양쪽의 level을 맞춰준다. 그리고 tree를 타고 올라가면서 노드의 값이 같은지를 확인한다.

*/