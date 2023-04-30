#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>
#include <string>
#include <utility>
#define S 1
#define U 2
#define E 3

using namespace std;

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1, T2>& p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);

		// Mainly for demonstration purposes, i.e. works but is overly simple
		// In the real world, use sth. like boost.hash_combine
		return h1 ^ h2;
	}
};



struct Player
{
	int HP;
	bool is_U = false;
	int U_HP = 0;
	int Usan = 0;
};


struct Position
{
	int x;
	int y;
	int cnt = 0;
};

int map[503][503];
unordered_map<pair<int, int>, int, pair_hash> check[10];
queue<Position> q;
queue<Player> player;
int N, H, D;

int start_x;
int start_y;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void bfs()
{
	while (!q.empty())
	{
		Position pos = q.front();
		q.pop();
		int x = pos.x;
		int y = pos.y;
		int cnt = pos.cnt;

		Player stat = player.front();
		player.pop();


		if (stat.HP == 0) continue;
		if (map[y][x] == U)
		{
			stat.is_U = true;
			stat.U_HP = D;
			stat.Usan++;
			map[y][x] = 0;
		}

		if (map[y][x] == E)
		{
			cout << cnt;
			return;
		}
		else
		{
			if (stat.is_U)
			{
				stat.U_HP--;
				if (stat.U_HP == 0) stat.is_U = false;
			}
			else
			{
				stat.HP--;
				if (stat.HP == 0) continue;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int _dx = x + dx[i];
			int _dy = y + dy[i];


			if (_dx > 0 && _dx < N + 1 && _dy > 0 && _dy < N + 1)
			{
				pair<int, int> chk_key = make_pair(_dx, _dy);
				if (check[stat.Usan].find(chk_key) != check[stat.Usan].end()) continue;
				else
				{
					check[stat.Usan].insert(make_pair(chk_key,1));
				}

				Position next = pos;
				next.x = _dx;
				next.y = _dy;
				next.cnt += 1;
				q.push(next);
				player.push(stat);
			}
		}
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> H >> D;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			char input;
			cin >> input;
			if (input == 'S')
			{
				start_x = j;
				start_y = i;
				map[i][j] = S;
			}
			else if (input == 'U')
			{
				map[i][j] = U;
			}
			else if (input == 'E')
			{
				map[i][j] = E;
			}
		}
	}

	Player p;
	p.HP = H+1;
	Position start_p;
	start_p.x = start_x;
	start_p.y = start_y;
	q.push(start_p);
	player.push(p);

	bfs();


	return 0;
}

/*
요구사항 :
가로 세로 길이가 N인 정사각형 격자가 있다.
두 곳을 제외한 모든 곳에 체력을 1씩 감소 시키는 비가 내린다.
죽음의 비가 내리지 않는 곳은 현 재위치와 안전지대라는 곳이다.
안전지대로 이동을 해야한다.
격자에는 비를 잠시 막아주는 우산이 K개 존재한다.
우산에는 내구도 D가 존재한다.
우산이 비를 맞으면 내구도가 1씩 감소한다.
내구도가 0이 되는 순간 우산은 사라진다.
주어지는 우산의 내구도는 모두 D로 동일하다.

격자에서 이동을 할 때 다음과 같이 이동한다.
1. 상하좌우로 이동한다. 격자 밖으로는 못나간다.
2. 이동한 곳이 안전지대라면 반복을 종료한다.
3. 이동한 곳에 우산이 있다면 우산을 든다. 우산이 들려 있다면 가지고 있는 우산을 버리고 새로운 우산으로 바꾼다.
4. 우산을 가지고 있다면 내구도1 감소, 아니면 체력이 1 감소한다.
5. 우산의 내구도가 0이되면 들고 있는 우산이 사라진다.
6. 체력이 0이되면 죽는다.

현재 있는 위치에서 안전지대로 얼마나 빠르게 이동할 수 있는지 구하자.

데이터 :
int N : 정사각형 격자의 크기 / 4~500
int H : 현재 체력 / 1 ~ 10000
int D : 우산의 내구도 / 1 ~ 5000
우산의 개수 : 0~10
char S : 현재 위치
char E : 안전 지대
char U : 우산 위치

시간복잡도 :
재귀함수의 최악을 생각 했을 때, 500^4 가 나온다. 이 결과를 다한다해도 2초 정도가 걸릴 것이다.
여기서 시간 제한을 1.5초로 두었기 때문에 중간에 HP가 0이 된다거나 하는 부분을 줄이면
충분히 시간복잡도를 해결 할 수 있을 것으로 보인다.

아이디어 :
먼저 가장 먼저 생각난 방법은 BFS를 이용한 방법이다.
격자안에 상태를 집어넣어주고, 그 이후에 시작점을 시작으로 상하좌우를 확인하면 된다고 생각을 했다.
여기서 상하좌우를 확인하기 전에 먼저 확인 해야 할 것이 player의 HP값이다.
그 값이 0이라면 움직일수없다. 따라서 bfs를 종료해야 한다. 그리고 HP를 확인했다면 다음 확인 할 것은
is_U 이다 우산을 들고 있는지를 확인한다. 그리고 다음 확인 할 것은 우산의 내구도이다. U_HP를 확인한다.
U_HP값이 0이라면 우산은 들고 있지 않는 것으로 해야 하므로 is_U를 false로 변경한다. 


*/