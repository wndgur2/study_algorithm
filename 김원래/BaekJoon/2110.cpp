#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

int N, C;
vector<int> pos;


int search(int l, int r)
{
	int result;

	while (l <= r)
	{
		int mid = (l + r) / 2;
		int cnt = 1;
		int prev = pos[0];
		for (int i = 1; i < N; ++i)
		{
			if (pos[i] - prev >= mid)
			{
				prev = pos[i];
				++cnt;
			}
		}

		if (cnt >= C)
		{
			l = mid + 1;
			result = mid;
		}
		else
		{
			r = mid - 1;
		}
	}

	return result;
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);


	cin >> N >> C;
	pos.resize(N);

	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		pos[i] = x;
	}

	sort(pos.begin(), pos.end());

	int left = 0;
	int right = pos[N - 1];
	
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
집 N개가 수직선 위에 있다.
각각의 집의 좌표는 x1~xN이다.
도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공우기 C개를 설치 하려고 한다.
최대한 많은 곳에서 와이파이를 사용하게 하려고 한다.
한집에 공유기는 하나만 설치 가능 하다.
가장 인접한 두 공유기 사이의 사리를 가능한 크게 하여 설치 하려고 합니다.

C개의 공유기를 N개의 집에 적당히 설치해서 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성 하시오.


데이터 :
int N : (2~20만) 집 개수
int C : (2~N) 공유기 개수
vector<int> pos : (각 요소는 0~10억) 집의 좌표들


시간복잡도 :


아이디어 :
가중치 그래프로 데이터를 표현 할 수 있다. 그렇다면 문제는 


*/