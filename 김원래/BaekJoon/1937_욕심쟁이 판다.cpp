#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> forest;
vector<vector<int>> visit;
int dx[4] = {0,0,-1,1};
int dy[4] = { -1,1,0,0 };
int max_Count = 0;
vector<vector<int>> dp;

int dfs(int x, int y)
{
	if (dp[y][x] != 0) return dp[y][x];
	else dp[y][x] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX < 1 || nextY < 1 || nextX > N || nextY > N) continue;
		
		if (forest[nextY][nextX] > forest[y][x])
		{
			dp[y][x] = max(dp[y][x], dfs(nextX, nextY) + 1);
		}
	}

	return dp[y][x];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
	
	cin >> N;
	forest.resize(N + 1, vector<int>(N + 1, 0));
	visit.resize(N + 1, vector<int>(N + 1, 0));
	dp.resize(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> forest[i][j];
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
				dfs(j,i);
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			max_Count = max(max_Count, dp[i][j]);
		}
	}

	cout << max_Count;


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
NxN 크기의 배열이 주어진다.
이 배열 내부에 한 점에서부터 시작한다.
한 점에서 행동을 마치면 상하좌우로 이동한다.

상하좌우로 이동하되, 이동을 하기 위해서는 현재 위치보다 더 큰 숫자여야 한다.

해결해야 하는 것은 두가지이다.
1. 어디서 출발 할 것인가?
2. 최대한 많은 칸을 이동하고 싶다.

움직일 수 있는 최대의 칸을 출력하라.

데이터 :
int N : 배열의 크기 (1~500)


시간복잡도 :


아이디어 :
DFS를 이용한 백트래킹 문제라고 생각이 들었다. 그런데 N값이 최대 500이라는 점으로 볼 때,
DFS를 돌게 되면, 시간초과가 날 것이라는 생각이 들었다.
그래도 일단 해봐야 겠다.

*/