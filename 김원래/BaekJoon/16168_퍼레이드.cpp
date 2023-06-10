#include <iostream>
#include <vector>
#include <queue>
#include <time.h>

using namespace std;

int V, E;
vector<int> cnt;

int parent[3001];

int Find(int x)
{
	if (x == parent[x]) return x;
	parent[x] = Find(parent[x]);
	return parent[x];
}

void Union(int x, int y)
{
	int x_parent = Find(x);
	int y_parent = Find(y);

	if (x_parent > y_parent) parent[x] = y_parent;
	else parent[y] = x_parent;
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> V >> E;

	cnt.resize(V + 1, 0);

	

	for (int i = 1; i < V + 1; i++)
	{
		parent[i] = i;
	}

	int p1, p2;

	for (int i = 0; i < E; ++i)
	{
		cin >> p1 >> p2;
		Union(p1, p2);
		++cnt[p1];
		++cnt[p2];
	}

	int odd = 0;
	for (int i = 1; i < V + 1; i++)
	{
		if (cnt[i] % 2 == 1) ++odd;
		if (Find(parent[i]) != 1)
		{
			cout << "NO";
			return 0;
		}
	}
	if (odd == 2 || odd==0) cout << "YES";
	else cout << "NO";

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
퍼레이드 경로는 일정한 지점들과 두 지점을 연결하는 연결 구간으로 이루어져 있다.
종우는 모든 지점을 지나면서 모든 연결 구간들을 지나고 싶어한다.

같은 연결 구간을 두번 이상 지날 수 없다.
단, 같은 지점은 두번 이상 지나도 된다.

같은 연결 구간을 지나지 않고 모든 구간을 지나도록 퍼레이드를 만드는 프로그램을 작성하라

데이터 :
int V : 지점의 개수(1~E)
int E : 연결구간 개수(V~3000)


시간복잡도 :
상수 시간안에 해결된다.


아이디어 :
오일러 경로를 이용하여 문제를 풀 수 있다.
일단 이 문제의 경우 한 붓으로 그려지는 경로가 있는지를 묻는 문제이다.
이 한 붓으로 그려지는 경로라는 것은 오일러 경로가 되는 조건을 만족하는 경로를 의미한다.
오일러 경로를 만족하기 위해서는 첫번째로 하나의 컴포넌트로 길이 이어져 있어야 한다. 이를 Union-Find 알고리즘을 이용하여 구현한다.
두번째는 오일러 경로의 경우 모든 정점에 대하여 홀수 개의 경로를 가진 경로가 0개 또는 2개가 있는 경우에 한해서만 오일러 경로를 만족한다.

*/