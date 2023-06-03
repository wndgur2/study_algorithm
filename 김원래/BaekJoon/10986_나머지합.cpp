#include <iostream>
#include <vector>
#include <time.h>

using namespace std;


int N, M, x;
long long cnt[1001];
long long sum, ans;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		sum += x;
		cnt[sum % M]++;
	}

	for (int i = 0; i <= 1000; i++)
	{
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}

	cout << cnt[0] + ans;



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
수 N개가 주어진다. 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하여라


데이터 :


시간복잡도 :


아이디어 :


*/