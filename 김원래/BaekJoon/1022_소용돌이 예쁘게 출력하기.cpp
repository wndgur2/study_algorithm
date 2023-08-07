#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

using namespace std;

int r1, c1, r2, c2;

struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator() (const std::pair<T1, T2>& pair) const {
		return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
	}
};

unordered_map<pair<int, int>, int, pair_hash> Rets;

enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> r1 >> c1 >> r2 >> c2;

	if (0 >= r1 && 0 >= c1 && 0 <= r2 && 0 <= c2)
	{
		Rets.insert(make_pair(make_pair(0, 0), 1));
	}

	if (0 >= r1 && 1 >= c1 && 0 <= r2 && 1 <= c2)
	{
		Rets.insert(make_pair(make_pair(0, 1), 2));
	}

	int direc = ::LEFT;
	int x = 1;
	int y = -1;
	int value = 3;
	int maxX = x;
	int minX = -1;
	int minY = y;
	int maxY = 1;

	while (x < 5001 && y < 5001)
	{

		if (y >= r1 && x >= c1 && y <= r2 && x <= c2)
		{
			Rets.insert(make_pair(make_pair(y, x), value));
		}
		++value;

		if (x == 5000 && y == 5000) break;

		switch (direc) {
		case ::UP :
			if (y == minY)
			{
				direc = ::LEFT;
				x = x - 1;
			}
			else --y;
			break;
		case :: DOWN :
			if (y == maxY)
			{
				direc = ::RIGHT;
				x = x + 1;
			}
			else ++y;
			break;
		case :: LEFT :
			if (x == minX)
			{
				direc = ::DOWN;
				y = y + 1;
			}
			else --x;
			break;
		case :: RIGHT :
			if (x > maxX)
			{
				++maxX;
				--minX;
				++maxY;
				--minY;
				direc = ::UP;
				y = y - 1;
			}
			else ++x;
			break;
		}
	}

	int max_val = 0;
	vector<vector<int>> res;

	for (int i = r1; i <= r2; ++i)
	{
		vector<int> v;

		for (int j = c1; j <= c2; ++j)
		{
			auto iter = *(Rets.find(make_pair(i, j)));
			v.push_back(iter.second);
		}

		for (int k = 0; k < v.size(); ++k)
		{
			max_val = max(v[k], max_val);
		}

		res.push_back(v);
	}

	int len = 1;

	while (max_val / 10 > 0)
	{
		max_val /= 10;
		++len;
	}

	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		{
			cout << setw(len) << res[i][j] << " ";
		}
		cout << '\n';
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
(0,0) 위치에 1을 쓴다. (0,1)에 2를 쓴다. 여기서부터 소용돌이는 반시계 방향으로 돈다.
입력은 네개가 주어진다. 

데이터 :
int C_IDX = 5001, -1값도 있는 인덱스 값을 맞춰주기 위한 상수
vector<vector<int>> cyclone = 값을 만들기 위해서 채우는 배열
int r1 c1 = 출력 시작점
int r2 c2 = 출력 마지막점

시간복잡도 :


아이디어 :
일단 배열의 인덱스가 -5000까지 사용되기 때문에 배열 자체를 커스터마이징 할 필요가 있다.
근데 이 문제를 보게 되면 행과 열이 2개씩 증가하는 것을 알 수 있다. 따라서 -5001 ~ 5001 까지를
표현 할 수 있게 배열을 구성하는게 좋아보인다.
(0,0) = (5000,5000)으로 사용된다. 즉 (0,0) ~ (10002,10002) 까지의 인덱스가 사용된다.
1, 3, 5, 7, 9, 11 ... 
1. (5000,5000)에 1을 넣는다. (5000,5001)에 2을 넣는다.
2. 반시계 방향으로 돌면서 값을 채워 넣는다. (경우의 수에 따라서 값 채워넣기) 


경우의수
1. 오른쪽으로 가던 중 위가 빈 경우 = 위로
2. 오른쪽으로 가던 중 위가 막힌 경우 = 오른쪽으로
3. 왼쪽으로 가던 중 아래가 빈 경우 = 아래로
4. 왼쪽으로 가던 중 아래가 막힌 경우 = 왼쪽으로
5. 위로 가던 중 왼쪽이 빈 경우 = 왼쪽으로
6. 위로 가던 중 왼쪽이 막힌 경우 = 위로
7. 아래로 가던 중 오른쪽이 빈 경우 = 오른쪽으로
8. 아래로 가던 중 오른쪽이 막힌 경우 = 아래로
*/