#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

enum
{
	STOP,
	EMPTY
};

int N, M;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int board[32][32];
int min_Count = 2147483647;
int empty_Count = 0;

void dfs(int cur_board[][32], int x, int y, int count, int cur_emptyCount)
{
	int flag_Cnt = 0;
	for (int i = 0; i < 4; ++i)
	{
		int _cur_emptyCount = cur_emptyCount;
		

		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX < 1 || nextY < 1 || nextX > M || nextY > N || cur_board[nextY][nextX] == ::STOP) {
			++flag_Cnt;
			continue;
		}

		
		while (nextX >= 1 && nextY >= 1 && nextX <= M && nextY <= N && cur_board[nextY][nextX] != ::STOP)
		{
			cur_board[nextY][nextX] = ::STOP;
			++_cur_emptyCount;

			nextX += dx[i];
			nextY += dy[i];
		}

		nextX -= dx[i];
		nextY -= dy[i];

		dfs(cur_board, nextX, nextY, count + 1, _cur_emptyCount);

		while (true)
		{
			if (nextX == x && nextY == y) break;
			cur_board[nextY][nextX] = ::EMPTY;
			nextX -= dx[i];
			nextY -= dy[i];
		}
	}

 	if (flag_Cnt == 4)
	{
		bool flag = true;
		
		if (cur_emptyCount == empty_Count && min_Count > count) min_Count = count;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
	
	int Order = 0;
	while (cin >> N >> M) {
		++Order;
		
		for (int i = 1; i <= N; ++i)
		{
			string stats;
			cin >> stats;
			for (int j = 0; j < M; ++j)
			{
				if (stats[j] == '.')
				{
					board[i][j+1] = ::EMPTY;
					++empty_Count;
				}
				else
				{
					board[i][j+1] = ::STOP;
				}
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				if (board[i][j] == ::EMPTY) {
					board[i][j] = ::STOP;
					dfs(board, j, i, 0, 1);
					board[i][j] = ::EMPTY;
				}
			}
		}

		if (min_Count == 2147483647) cout <<"Case " <<Order<<": " << -1 << '\n';
		else  cout << "Case " << Order << ": " << min_Count << '\n';
		min_Count = 2147483647;
		empty_Count = 0;
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
배열이 주어진다. 배열 내부의 각 칸은 빈칸 또는 장애물이다.
배열 한 곳에 공이 하나 놓여있다.
공은 상하좌우로 움직일 수 있다.
공은 장애물, 배열의 경계, 이미 공이 지나갔던 칸을 만나면 멈춘다.
게임은 공이 더이상 움질일 수 없을 때 끝난다.
모든 빈 칸을 공이 방문한 적이 있어야 한다.
모든 칸을 방문하기 위한 이동 횟수의 최솟값을 구하여라.

데이터 :
int N, M : N은 세로크기이다. (1~30) M은 가로 크기이다.(1~30)
vector<vector<int>> board : 보드판
vector<vector<int>> visit 

시간복잡도 :


아이디어 :
일단 종료조건이 주어져 있지 않아서, while문을 돌면서 해야 할 것 같다.
board판에 입력을 받고, enum으로 EMPTY와 OBSTACLE을 채워준다.
이 문제의 경우 공의 위치가 주어지지 않는다.
그렇기 때문에 처음 공의 위치 또한 사용자가 잡아야 한다.
다행인 점은 데이터의 크기가 최대 30x30이라는 점이다.
모든 빈칸에 대해서 공을 넣어봐야 한다.
그리고 그 곳을 시작으로 DFS를 상하좌우에 대해서 가능한 부분에서 실행한다.
DFS를 돌면서 visit배열을 채워 나간다.
*/