#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
int N, S;
vector<int> numbers;
vector<bool> visit;

void dfs(int cur, int sum, int level)
{
	if (cur != 0) sum += numbers[cur];

	if (sum == S && cur != 0) {
		cnt++;
	}

	if (level == N) return;

	visit[cur] = true;
	level++;
	for (int i = 1; i < N+1 ; i++)
	{
		if (visit[i] == false)
		{
			dfs(i, sum, level);
		}
	}
	visit[cur] = false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	numbers.resize(N + 1);
	visit.assign(N + 1, false);
	for (int i = 1; i < N+1; i++)
	{
		int tmp;
		cin >> tmp;
		numbers[i]=tmp;
	}
	dfs(0, 0, 0);
	cout << cnt;
	return 0;
}

/*
요구사항 :
N개의 정수가 주어 졌을 때, 크기가 양수인 부분수열 중에서
그 수열의 원소를 다 더한 값이 S가 되도록 하는 경우의 수를 구하여라.

	
데이터 :


시간복잡도 :


아이디어 :
입력 N,S를 입력받는다. 
수열은 DFS로 표현 할 수 있다. 그 방법은 하나의 노드에 대하여 자식 노드의 개수를 N개로 설정을 하면 가능하다.
이때 이미 수열에 어떠한 값을 가지고 있다면 그 값은 포함하지 않으면서 list로 값을 저장하면
순열을 표현 할 수 있다.
하지만 이 문제의 경우 수열의 합을 나타내기 때문에 수열에 있는 값들의 순서가 중요하지 않다.
그렇기 때문에 순열을 확인하는 것은 비효율 적이고, 조합을 확인하는 것이 정답이 된다.
조합을 만들기 위해서는 이진 트리를 사용하면 된다.
어떠한 A라는 값이 N의 정수 중 하나로 주어 졌을 때, 수열에 A가 있는 경우 없는 경우로 해서
DFS를 확장 할 수 있다.
DFS를 돌 때마다 수열의 합을 확인하고,그 값이 S인지 확인한다.
수열의 합을 확인 하는 것은 있는 경우에 대해서만이다.
없는 경우에 대해서는 체크해주어서는 안된다.

*/