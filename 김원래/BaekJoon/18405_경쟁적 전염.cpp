#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct status
{
	int level;
	int virus;
	int x;
	int y;

	status(int virus, int x, int y, int level) : virus(virus),x(x),y(y), level(level) { }
};

struct compare {
	bool operator()(const status& s1, const status&s2) {
		if (s1.level != s2.level)
		{
			return s1.level < s2.level;
		}
		else
		{
			return s1.virus < s2.virus;
		}
		
	}
};

priority_queue<status, vector<status>, compare> q;
vector<vector<int>> visit;
vector<vector<int>> map;
int N, K, S, RX, RY;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 , 0 };

void bfs()
{
	while (!q.empty())
	{
		int virus = q.top().virus;
		int x = q.top().x;
		int y = q.top().y;
		int level = q.top().level;
		q.pop();

		if (level == S) return;

		
		visit[y][x] = 1;

		for (int i = 0; i < 4; i++)
		{
			int _dx = x + dx[i];
			int _dy = y + dy[i];

			if (_dx < 1 || _dx > N || _dy < 1 || _dy > N) continue;

			if (!visit[_dy][_dx])
			{
				if (map[_dy][_dx])
				{
					if (virus < map[_dy][_dx])
					{
						map[_dy][_dx] = virus;
						q.push(status(virus, _dx, _dy,level+1));
					}
				}
				else
				{
					map[_dy][_dx] = virus;
					q.push(status(virus, _dx, _dy,level+1));
				}
			}
		}

	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	visit.resize(201);
	map.resize(201);
	
	for (int i = 1; i < N+1; i++)
	{
		visit[i].resize(201, 0);
		map[i].resize(201, 0);
	}



	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			int input;
			cin >> input;
			if (input)
			{
				map[i][j] = input;
				visit[i][j] = 1;
				q.push(status(input, j, i,0));
			}
		}
	}
	cin >> S >> RY >> RX;

	bfs();


	cout << map[RY][RX];
	

	return 0;
}

/*
요구사항 :
NxN 크기의 시험관이 있다. 특정한 위치에는 바이러스가 존재 할 수 있다.
모든 바이러스는 1~K번 까지의 바이러스 종류 중 하나이다.
이 바이러스는 1초마다 상하좌우 방향으로 증식해 나간다.
단, 매 초마다 번호가 번호가 낮은 종류의 바이러스 부터 먼저 증식한다.
특정한 칸에 이미 바이러스가 존재하면 들어 갈 수 없다.
S초가 지난 후에 (X,Y)에 존재하는 바이러스 종류를 출력해봐라
만약 S초가 지난 후에 (X,Y)에 바이러스가 없다면 0을 출력하라.


데이터 :
int N : 정사각형 배열의 크기(1~200)
int K : 바이러스 종류의 번호(1~1000)
int S : 초 수

시간복잡도 :
시간복잡도를 정확히 계산하는 것은 어렵지만, 모든 칸을 채우기 위한 방법인 200*200에서 
같은 레벨에서의 visit을 발생하지 않기 때문에 위의 경우보다는 시간복잡도가 크지만
많이 차이는 나지 않을 것이라 생각이 든다.


아이디어 :
이 문제에서 낮은 번호의 바이러스가 먼저 증식하게 하고 있는데,
진짜 이 경우를 구현하기 보다 현재 증식하려는 번호가 옆 플라스크의 있는 바이러스보다
큰지 작은지를 비교해서 덮어 씌워주게끔 하는게 더 좋다고 생각이 든다.
하지만 이 경우 같은 레벨 대에서만 이러한 연산을 하게끔 해야 하므로, push를 할때까 아닌 pop을 할때
visit을 등록해야 할 것으로 보인다.



*/