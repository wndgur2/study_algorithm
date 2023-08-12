#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

int parents[100001];

vector<pair<int, int>> v[3];

vector<pair<int, pair<int, int>>> planets;

int N;


int Find(int child)
{
	if (parents[child] == child) return child;

	return parents[child] = Find(parents[child]);
}

void Union(int a, int b)
{
	int aParent = Find(a);
	int bParent = Find(b);

	if (aParent == bParent) return;

	if (aParent < bParent) parents[bParent] = aParent;
	else if (aParent > bParent) parents[aParent] = bParent;
}



bool isCycle(int a, int b)
{
	if (Find(a) == Find(b)) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		v[0].push_back(make_pair(x, i));
		v[1].push_back(make_pair(y, i));
		v[2].push_back(make_pair(z, i));
	}

	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	sort(v[2].begin(), v[2].end());

	for (int i = 0; i < N-1; ++i)
	{
		planets.push_back(make_pair(abs(v[0][i + 1].first - v[0][i].first), make_pair(v[0][i].second, v[0][i + 1].second)));
		planets.push_back(make_pair(abs(v[1][i + 1].first - v[1][i].first), make_pair(v[1][i].second, v[1][i + 1].second)));
		planets.push_back(make_pair(abs(v[2][i + 1].first - v[2][i].first), make_pair(v[2][i].second, v[2][i + 1].second)));
	}
	
	sort(planets.begin(), planets.end());

	for (int i = 0; i < N; ++i)
	{
		parents[i] = i;
	}

	long long totalCost = 0;

	for (int i = 0; i < planets.size(); ++i)
	{
		int cost, firstIdx, secondIdx;
		cost = planets[i].first;
		firstIdx = planets[i].second.first;
		secondIdx = planets[i].second.second;

		if (isCycle(firstIdx, secondIdx) == true) continue;

		totalCost += cost;
		Union(firstIdx, secondIdx);
	}

	cout << totalCost;

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
왕국을 만들었다.
왕국은 N개의 행성으로 이루어져 있다.
행성을 연결하는 터널을 만들려고 한다.
행성은 3차원 좌표위의 한 점이다.

예시로 두행성 A(x1,y1,z1) , B(x2,y2,z2)를 터널로 연결하기 위해 드는 비용은
min(abs(x1-x2) ... )이다.

터널을 N-1개 건설해서 모든 행성이 서로 연결되게 하려한다.
모든 행성을 터널로 연결하는데 필요한 최소 비용을 구하여라.

데이터 :
int N : 행성의 개수 ( 1~ 10만 )
vector<vector<vector<int>>> planets : 행성의 x,y,z좌표 (-10억 ~ 10억 )


시간복잡도 :


아이디어 :
연결을 할 때 최소비용으로 연결을 하기 위해서는 나랑 가장 가까운 행성과 연결을 하는것이 좋다.
그런데 이 경우 하나의 그래프가 되지 않는 경우도 발생한다.
다익스트라 알고리즘을 사용하면 될까?


*/