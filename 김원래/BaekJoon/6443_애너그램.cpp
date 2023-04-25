#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct pos
{
	int visit[20] = { 0 };
	string s = "";
};


int N;
int visit[20];
queue<pos> q;
vector<string> res;

void bfs(string str)
{
	while (!q.empty())
	{
		pos origin = q.front();
		q.pop();
		if (origin.s.size() == str.size())
		{
			res.push_back(origin.s);
			continue;
		}
		int alpha_visit[26] = { 0 };
		for (int i = 0; i < str.size(); i++)
		{
			pos cur = origin;
			
			if (cur.visit[i] == 0 && alpha_visit[str[i] - 97] == 0 )
			{
				alpha_visit[str[i] - 97] = 1;
				cur.visit[i] = 1;
				cur.s += str[i];
				q.push(cur);
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		pos start;
		q.push(start);
		bfs(input);
		sort(res.begin(), res.end());
		for (auto iter = res.begin(); iter != res.end(); iter++)
		{
			cout << *(iter) << "\n";
		}
		res.clear();
	}
	
	return 0;
}

/*
요구사항 :
애너그램
abc가 입력되면 abc,acb,bac,bca,cab,cba가 출력이 된다.
입력받은 단어내에 몇몇 철자가 중복 될 수 있다. 같은 단어가 여러 번 만들어지면 한 번만 출력해야 한다.

데이터 :
int N : 단어의 개수

시간복잡도 :
dfs를 통해서 모든 경우를 확인하게 되면 시간초과가 발생한다. 중복 연산이 발생하는 경우를 제외시켜야 한다.

아이디어 :
처음 dfs를 이용하여 모든 값을 구하고 그 이후에 set에 저장을 하는 방식으로 하였는데, 시간초과가 발생하였다.
그래서 시간을 줄이기 위하여 입력받은 단어내에 같은 철자가 반복되는 경우에 한하여 해당번에 2번 이상하지 않아도 된다는 것을 알 수 있었다.
위의 말이 무슨 소리냐면 예를들어 aaba가 입력으로 주어 졌을 때, 첫번째 문자가 a또는 b인 경우만 있다는 것이다. 그래서 a, a, b, a를 확인 할 필요 없이 a,b만 확인하면 된다.
이렇게 생각을 해보니 dfs보다 bfs로 접근하는 것이 쉽다고 생각이 됐고, bfs를 통해서 같은 레벨을 queue에 추가하는 for문을 돌 때,
이미 연산한 알파벳이 있는지를 확인하여 그 연산에 대해서는 큐에 추가하지 않도록 했다.

*/