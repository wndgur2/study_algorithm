#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>


using namespace std;

vector<int> v;

int Get_parent(int node)
{
	if (v[node] == node) return node;
	else return Get_parent(v[node]);
}

void Union(int a, int b)
{
	a = Get_parent(v[a]);
	b = Get_parent(v[b]);

	if (a != b) // a != b가 같은 경우도 제외 해주어야 한다.
	{
		if (a >= b) v[a] = b;
		else v[b] = a;
	}

}


bool isCycle(int a, int b)
{
	if (Get_parent(a) == Get_parent(b)) return true;
	else return false;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	int m;


	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		v.push_back(i);
	}


	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		if (isCycle(a, b))
		{
			cout << i + 1;
			return 0;
		}

		Union(a, b);
		

	}
	
	cout << "0";
	return 0;
}

/*

선 플레이어가 홀수 번째 차레, 후 플레이어가 짝수 번째 차례
0~n-1까지 고유한 번호가 부여된 평면 상의 점 n개가 주어진다.
이 중 어느 세점도 일직선 위에 놓이지 않는다.
매 차례 마다 두 플레이어는 두 점을 선택해서 이를 연결하는 선분을 긋는다.
이전에 그린 선분을 다시 그을 수는 없다. 이미 그린 다른 선분과 교차하는 것은 가능하다.
게임을 진행하다가 처음으로 사이클을 완성하는 순간 게임이 종료된다.

몇 번째 차례에서 사이클이 완성 됐는지, 혹은 아직 게임이 진행 중인지를 판단하는 프로그램을 작성해라

### 시간복잡도
 3 <= m <= 1000000
 3 <= n <= 500000

 시간복잡도 n안에는 해야한다.



### 데이터
int n : 점의 개수
int m : m번째 차례

int answer = 0 or 사이클이 생겨난 차례

### 아이디어
선분을 그릴 때마다 사이클이 있는지를 확인해야 한다.
사이클이 있는지를 판별하기 위해서는 어떻게 해야 하는가?
새로운 (A,B) 간선이 그어졌다 했을 때, B를 제외한 모든 A와 연결된 점에 대하여 B와 연결 됐는지를 확인한다. 방법은 BFS를 사용하여 한다. 이미 visit한 곳은 방문하지 않는다.

*/