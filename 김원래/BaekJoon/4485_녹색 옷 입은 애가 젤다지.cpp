#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647

using namespace std;

int N;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0, 0 };

struct status
{
	int cost;
	int y;
	int x;

	status(int cost, int x, int y) : cost(cost), x(x), y(y) { }
};

struct compare
{
	bool operator()(const status& s1, const status& s2)
	{
		return s1.cost > s2.cost;
	}
};

vector<int> result;
priority_queue<status, vector<status>, compare> pq;



void dijkstra(vector<vector<int>>&& matrix, vector<vector<int>>&& optimal)
{
	while (!pq.empty())
	{
		int cost = pq.top().cost;
		int x = pq.top().x;
		int y = pq.top().y;
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x < 0 || next_x > N - 1 || next_y < 0 || next_y > N - 1) continue;
			
			int next_cost = cost + matrix[next_y][next_x];

			if (optimal[next_y][next_x] > next_cost)
			{
				optimal[next_y][next_x] = next_cost;
				pq.push(status(next_cost, next_x, next_y));
			}
		}
	}
	result.push_back(optimal[N - 1][N - 1]);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		
		vector<vector<int>> matrix(N);
		vector<vector<int>> optimal(N);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int input; 
				cin >> input;
				matrix[i].push_back(input);
				optimal[i].push_back(INF);
			}
		}

		optimal[0][0] = matrix[0][0];
		pq.push(status(matrix[0][0], 0, 0));
		dijkstra(static_cast<vector<vector<int>>&&>(matrix), static_cast<vector<vector<int>>&&>(optimal));
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << "Problem " << i + 1 << ": " << result[i] << "\n";
	}


	
	

	return 0;
}

/*
요구사항 :
도둑루피 = 소지한 루피가 줄어든다.
도둑루피만 가득한 NxN 크기의 동굴의 제일 왼쪽에 있다.
(0,0)에서 (N-1,N-1)까지 이동해야 한다.
이때 각 칸마다 도둑루피가 있어서 이동 시마다 소지금을 잃는다.
링크는 잃은 금액을 최소로 하여 동굴 건너편까지 이동해야 한다.
이동은 상하좌우로 가능하다.
링크가 잃을 수 밖에 없는최소 금액은??
N을 계속 입력 받고 그만 진행 하고 싶으면 0을 입력 받는다.

데이터 :
int N : 격자크기 (2~125)
int lose : 각 격자에 들어가 있는 검은루피가 소지금을 줄어들게 하는 양 (0~9)

시간복잡도 :

아이디어 :


*/