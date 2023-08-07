#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

struct Egg
{
	int HP;
	int Damage;
};

int N;
vector<Egg> v;
int max_broken = 0;

void dfs(int grabbed, int broken)
{
	if (broken >= N - 1 || grabbed == N)
	{
		max_broken = max(broken, max_broken);
		return;
	}
	for (int i = 0; i < N; ++i)
	{
		int _grabbed = grabbed;
		int _broken = broken;
		if (i == _grabbed || v[i].HP < 1) continue;
		v[_grabbed].HP = v[_grabbed].HP - v[i].Damage;
		v[i].HP = v[i].HP - v[_grabbed].Damage;
		
		if (v[_grabbed].HP <= 0) ++_broken;
		if (v[i].HP <= 0) ++_broken;
		++_grabbed;

		while (_grabbed < N && v[_grabbed].HP <= 0) ++_grabbed;

		dfs(_grabbed, _broken);

		v[grabbed].HP = v[grabbed].HP + v[i].Damage;
		v[i].HP = v[i].HP + v[grabbed].Damage;


	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
	
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		Egg _egg;
		_egg.HP = a;
		_egg.Damage = b;

		v.push_back(_egg);
	}

	dfs(0, 0);

	/*clock_t start, finish;
	double duration;
	start = clock();
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	std::cout << duration << "초" << "\n";*/

	cout << max_broken;

	return 0;
}

/*
요구사항 :
계란은 내구도가 존재한다.
계란의 내구도는 상대 계란의 무게 만큼 줄어든다.
내구도가 0이하가 되면 깨진다.

일렬로 계란이 놓여있다.
1. 가장 왼쪽의 계란을 든다.
2. 손에 들고 있는 계란으로 깨지지 않은 다른 계란 중에서 하나를 친다. 손에 든 계란을 원래 자리에
내려 놓는다.
3. 가장 최근에 든 계란의 한 칸 오른쪽 계란을 손에 들고 2번 과정을 다시 진행한다.

최대한 많은 계란을 깨려먼 어떻게 해야 하는가?

데이터 :
int N : 계란 수 (1~8)

시간복잡도 :

아이디어 :
일단 N의 수가 엄청 작다. 그래서 완전탐색이 먼저 떠올랐다.
가장 최악의 경우를 생각해보면 내구도가 모두 300 이고 무게가 1 인 경우에 대해서 어림잡아 2400번
부딪히면 다 꺠질 것이다. 실제로는 1200번 이지 않을까 싶다.
여기서 8!을 곱해준다. 그렇게 해주는 이유는 모든 경우의 수를 계삲

*/