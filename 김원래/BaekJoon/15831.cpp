#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

int N, B, W;
vector<int> B_Counts, W_Counts;
string rocks;

int search(int l, int r)
{
	int res = 0;

	while (l <= r)
	{
		int mid = (l + r) / 2;
		int cur = 1;
		bool flag = false;

		for (int i = 0; i <= N-mid; ++i)
		{
			int _W = W_Counts[mid + i] - W_Counts[cur + i];
			int _B = B_Counts[mid + i] - B_Counts[cur + i];

			if (_W >= W && _B <= B)
			{
				l = mid + 1;
				flag = true;
				res = mid;
				break;
			}
		}
		if (flag == false)
		{
			r = mid - 1;
		}
	}

	return res;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);


	cin >> N >> B >> W;

	string str;
	cin >> str;
	rocks = str;

	W_Counts.resize(N + 1, 0);
	B_Counts.resize(N + 1, 0);

	for (int i = 1; i < rocks.size() + 1; ++i)
	{
		if (rocks[i - 1] == 'W')
		{
			W_Counts[i] = W_Counts[i - 1] + 1;
			B_Counts[i] = B_Counts[i - 1];
		}
		else
		{
			W_Counts[i] = W_Counts[i - 1];
			B_Counts[i] = B_Counts[i - 1] + 1;
		}
	}

	int left = 1;
	int right = N;
	int ans = search(left, right);
	
	cout << ans;

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
검은색과 흰색 조약돌이 놓여 있다.
총 N개의 조약돌이 있다. 1~N번까지 차례로 번호가 붙혀져 있다.

준표는 임의의 지점에서 산책을 시작한다.
원하는 지점에서 산책로를 빠져나와 집으로 돌아간다.
산책한 구간의 모든 조약돌을 줍는다.
준표는 최대한 긴 구간을 산책 하려한다.
하지만 아래의 조건을 만족해야 한다.
1. 까만 조약돌 B개 이하로 줍는다.
2. 흰색 조약돌 W개 이상을 줍는다.

만약 위 조건을 만족하는 구간이 없다면 준표는 바로 집으로 돌아간다.
이때 준표와 미미가 산책할 수 있는 구간 중 가장 긴 구간의 길이를 구하여라.

데이터 :
int N : 조약돌 개수
int B : 검은색 조약돌 개수는 이거 이하
int W : 하얀색 조약돌 개수는 이거 이상


시간복잡도 :


아이디어 :
가중치 그래프로 데이터를 표현 할 수 있다. 그렇다면 문제는 


*/