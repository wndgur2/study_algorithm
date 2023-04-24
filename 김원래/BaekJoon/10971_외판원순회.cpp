#include <iostream>
#include <vector>

using namespace std;
int N;
int W[11][11];
int visit[11];
int minval = 2147483647;

void dfs(int start, int cur, int cnt, int sum)
{
	cnt++;
	for (int i = 1; i < N + 1; i++)
	{
		if (visit[i] == 0 && W[cur][i])
		{
			visit[i] = 1;
			sum += W[cur][i];
			dfs(start, i, cnt, sum);
			visit[i] = 0;
			sum -= W[cur][i];
		}
	}

	if (cnt == N)
	{
		if (W[cur][start])
		{
			sum += W[cur][start];
			if (minval > sum) minval = sum;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int input[11];
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			cin >> input[j];
			W[i][j] = input[j];
		}
		
	}

	for (int i = 1; i < N + 1; i++)
	{
		visit[i] = 1;
		dfs(i, i, 0, 0);
		visit[i] = 0;
	}


	cout << minval;

	

	return 0;
}

/*
요구사항 :
외판원 순회 문제
1~N번까지 번호가 매겨진 도시들이 있다.
도시들 사이에는 길이 있다. ( 길이 없을 수도 있다 )
N개의 도시를 모두 거쳐 다시 원래의 도시로 돌아오는 순회여행 경로를 계획한다.
한번 갔던 도시는 다시 갈 수 없다.
가장 적은 비용을 들이는 여행 계획을 짜보자
= 하나의 그래프로 표현이 가능하다.
도시간에 이동하는 비용행렬이 주어진다. W[i][j]는 i에서 j도시로가는데 들어가는 비용
W[i][j]와 W[j][i]이 값은 같지 않다.
W[i][i]는 0이다.
도시 i에서 j로 가지 못하는 경우 비용은 0으로 표현한다.
	
데이터 :
int N : 도시의 수 ( 1 ~ 10 )
int W[i][j] : i도시에서 j도시로 가는데 들어가는 비용


시간복잡도 :
N = 10 이므로 DFS로 완전탐색을 해도 될것이라고 생각이 든다.

아이디어 :
모든 경우를 DFS로 확인한다. 가는 방향 비용이 0인 경우에는 바로 return한다.
모든 경우를 다 확인하게 되면 시간초과가 발생한다.
시간초과를 해결 할 방법을 찾아야 한다.
*/