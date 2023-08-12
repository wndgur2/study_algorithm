#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <queue>

using namespace std;

enum HOUSE
{
	EMPTY,
	WALL
};

enum PIPE
{
	GARO,
	SERO,
	DAEGAK
};

struct Status
{
	int x;
	int y;
	enum PIPE p;
};

int N;
vector<vector<int>> house;
queue<Status> q;
int Count = 0;

int flag[3][3] = { {1, 0, 1},{0, 1, 1},{1, 1, 1} };
int dx[3] = { 1, 0, 1 };
int dy[3] = { 0, 1, 1 };

bool check(int x, int y, PIPE transform)
{
	switch (transform)
	{
	case PIPE::GARO :
		if (house[y][x + 1] == 1) return false;
		return true;
		break;
	case PIPE::SERO :
		if (house[y + 1][x] == 1) return false;
		return true;
		break;
	case PIPE::DAEGAK :
		if (house[y + 1][x] == 1) return false;
		if (house[y][x + 1] == 1) return false;
		if (house[y + 1][x + 1] == 1) return false;
		return true;
		break;
	}
}

void bfs()
{
	while (!q.empty())
	{
		Status cur = q.front();
		q.pop();
		
		for (int i = 0; i < 3; ++i)
		{
			if (flag[cur.p][i] == 1)
			{
				int nextX = cur.x + dx[i];
				int nextY = cur.y + dy[i];
				if (nextX < 1 || nextY < 1 || nextX > N || nextY > N ||
					!check(cur.x, cur.y, (PIPE)i)) continue;

				if (nextX == N && nextY == N) ++Count;
				else {
					Status next;
					next.p = (PIPE)i;
					next.x = nextX;
					next.y = nextY;
					q.push(next);
				}
			}
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> N;

	house.resize(N + 1, vector<int>(N + 1));
	
	for (int i = 1; i < N + 1; ++i)
	{
		for (int j = 1; j < N + 1; ++j)
		{
			cin >> house[i][j];
		}
	}

	Status start;
	start.x = 2;
	start.y = 1;
	start.p = PIPE::GARO;

	q.push(start);

	bfs();

	cout << Count;

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
유현이가 새 집에 이사를 갔다. 이사를 간 집은 NxN 배열로 나타낼 수 있다.
배열의 각 칸은 벽이거나 빈칸이다.

집 수리를 위해서 파이프를 하나 옮겨야 한다.
파이프는 2개의 연속된 칸을 차지 한다.
파이프는 회전 시킬 수 있고, 가로, 세로, 왼쪽 대각선 세가지의 방향으로 틀 수 있다.

파이프를 옮겨야 하는데, 파이프는 빈 칸만을 움직 일 수 있다.

파이프는 밀 때 최대 45도까지 밀 수 있다.

데이터 :

시간복잡도 :

아이디어 :
요구사항의 그림을 살펴보게 되면,
가로 일 때는 가로(1, 0) , 대각선(1, 1)
세로 일 때는 세로(0, 1) , 대각선(1, 1)
대각선 일 때는 가로(1, 0) , 세로(0, 1) , 대각선(1, 1)
상태와 상관없이 이동하는 좌표값이 같은 것을 알 수 있다.
이러한 값들을 상수로 저장을 하고, BFS를 돌면서 이동 한 곳에 벽이 있는지를 확인하는
조건을 확인하여 모든 경우의 수를 확인한다.

*/