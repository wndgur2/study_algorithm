#include <iostream>
#include <vector>
#include <time.h>
#define INF 2147483647


using namespace std;

vector<vector<int>> sums;
int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);


	cin >> N >> M;

	sums.resize(N + 1);
	sums[0].resize(M + 1, 0);
	for (int i = 1; i < N + 1; i++)
	{
		sums[i].resize(M + 1, 0);
		int input;
		for (int j = 1; j < M + 1; j++)
		{
			cin >> input;
			sums[i][j] = sums[i][j - 1] + sums[i - 1][j] - sums[i - 1][j - 1] + input;
		}
	}

	int res = -INF;

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{

			for (int k = 0; k <= i; k++)
			{
				for (int m = 0; m <= j; m++)
				{
					int part_sum = sums[i][j] - sums[k][j] - sums[i][m] + sums[k][m];
					if (part_sum > res) res = part_sum;
				}
			}
		}
	}

	cout << res;


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
N*M 행렬을 그린다.
각 칸에 -10000~10000 사이의 값을 쓴다.
행렬의 부분행렬을 그려 그 안에 적힌 정수의 합을 구하는 게임이다.
정수의 합이 최대가 되는 부분행렬을 구하여라.


데이터 :
int N : 행 (2~199)
int N : 열 (2~199)


시간복잡도 :
NxN의 시간이 든다. 여기서는 4000x4000 = 16000000의 시간이 걸릴 것이다.

아이디어 :
NxM matrix을 만들어서 (i,j) 인덱스에 (0,0) ~ (i,j) 까지 더한 값을 넣어준다.
그리고 그렇게 만들어진 matrix를 2중 for문을 돌면서 A - B의 값을 계산한다.
그렇게 해서 최종적으로 최대 값을 구한다.


*/