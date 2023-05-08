#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int sum[101];
int d[101][51];

int areaSum(int num, int area)
{
	if (area == 0) return 0;
	if (num < 2 * area - 1) return -987654321;
	if (d[num][area] != -1)return d[num][area];

	d[num][area] = areaSum(num - 1, area);

	for (int i = num; i >= 1; i--)
	{
		d[num][area] = max(d[num][area], sum[num] - sum[i - 1] + areaSum(i - 2, area - 1));
	}

	return d[num][area];
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < 101; i++)
	{
		memset(d[i], -1, sizeof(d[i]));
	}

	for (int i = 1; i < N+1; i++)
	{
		int x;
		cin >> x;
		sum[i] = sum[i - 1] + x;
	}

	cout << areaSum(N, M);

	return 0;
}

/*
요구사항 :
N크기의 배열이 주어졌을 때 거기에 M크기의 구간을 선택해서 구간에 속한 수들의 총합이 최대가 되게끔 한다.
조건이 있는데,
1. 각 구간은 한 개 이상의 연속된 수들로 이루어진다.
2. 서로 다른 두 구간끼리 겹쳐있거나 인접해 있어서는 안된다.
3. 정확히 M개의 구간이 있어야 한다. M개 미만이어서는 안된다.
	
데이터 :
int N : (1~100)
int M : (1~N/2)

시간복잡도 :
	
아이디어 :
a ~ b 까지의 구간의 합은 맨 처음 인덱스부터 b까지의 합과 맨 처음부터 a전까지의 합을 빼야 한다.
이를 표현 하면 a~b = sum[b] - sum[a-1] 이를 이용하여 구간의 합을 구한다.
그리고 그 구간에서 새로운 구간을 더해야 한다.
그런데 어떤 구간 a~b까지의 구간의 합을 구했다 했을 때,
요구사항에서 적은 조건 2번에 의해서 다음 더하는 구간은 한칸을 건너뛰고 수행을 해야한다.

이를 표현하기 위한 dp 배열이 필요하다.
dp 배열은 dp[num][area] 로 되어 있으며 num은 확인한 구간의 마지막 인덱스를 의미한다.
area는 범위의 개수를 나타낸다.
예를 들어서 dp[50][2] 의 경우 50번 인덱스까지 확인을 하고, 해당 인덱스 까지의 범위중 두개를 선택하여
더한 결과의 최댓값을 dp[50][2]에 저장한다.

이를 계산하기 위해서는 재귀적으로 문제를 해결해야 한다.
dp 배열을 채울 때, 인덱스가 낮은 부분부터 채워 가야한다.

그래서 num 값이 1일때부터 해서 num이 n일 때까지 이를 진행한다.


*/