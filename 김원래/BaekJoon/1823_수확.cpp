#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

int N;
vector<int> prices;
vector<vector<int>> d;

int dp(int l, int r, int day)
{
	if (l > r) return 0;
	int& res = d[l][r];
	if (res != -1) return d[l][r];
	return res = max((prices[l] * day) + dp(l + 1, r, day + 1), (prices[r] * day) + dp(l, r - 1, day + 1));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> N;
	prices.resize(N + 1);
	d.resize(N + 1, vector<int>(N + 1, -1));

	for (int i = 1; i < N+1; ++i)
	{
		int price;
		cin >> price;
		prices[i] = price;
	}

	cout << dp(1, N, 1);
	

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
한줄로 있는 밭이 있는데, 처음과 끝만 수확이 가능하다.
만약에 N번째의 벼를 수확하려면 (처음과 끝이 아닌) 이 경우 앞에서부터 N번까지의 벼가 망가지게 된다.
벼의 가치는 v(i) * k 이다.

벼의 개수 N과 각 벼의 가치가 주어 졌을 때, 얻을 수 있는 최대 이익을 구하여라.


데이터 :
int N : 벼의 수(1~2000)
vector<int> prices : 벼의 가치 ( 각각의 값은 1~1000)


시간복잡도 :


아이디어 :
가치가 큰 것을 나중에 수확하는 것이 유리하다. 수확을 안하는 것보다는 수확을 하는 것이 좋다.
앞과 뒤를 확인해가면서 더 큰 값을 먼저 처리 한다. 그리고 포인트를 옮긴다.
만약에 값이 같은 경우 다음 포인트가 가라키는 인덱스를 보고 그 값이 더 작은 경우를 선택한다.

*/