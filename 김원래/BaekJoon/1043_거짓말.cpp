#include <iostream>
#include <vector>
#include <time.h>


using namespace std;

int N, M;
vector<int> factPeople;
vector<int> factParties;
vector<vector<int>> relativeUsers;
vector<vector<int>> relativeParties;

void dfs(int num)
{
	for (int i = 0; i < relativeUsers[num].size(); ++i)
	{
		if (factParties[relativeUsers[num][i]] == 0)
		{
			factParties[relativeUsers[num][i]] = 1;
			int PartyNum = relativeUsers[num][i];
			for (int j = 0; j < relativeParties[PartyNum].size(); ++j)
			{
				dfs(relativeParties[PartyNum][j]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> N >> M;

	factParties = vector<int>(M + 1, 0);
	relativeUsers = vector<vector<int>>(N + 1, vector<int>());
	relativeParties = vector<vector<int>>(M + 1, vector<int>());

	int factPersonCnt;
	cin >> factPersonCnt;

	for (int i = 1; i < factPersonCnt+1; ++i)
	{
		int num;
		cin >> num;
		factPeople.push_back(num);
	}

	for (int i = 1; i < M + 1; ++i)
	{
		int candidatesCnt;
		cin >> candidatesCnt;
		for (int j = 0; j < candidatesCnt; ++j)
		{
			int num;
			cin >> num;
			relativeUsers[num].push_back(i);
			relativeParties[i].push_back(num);
		}
	}

	for (int i = 0; i < factPeople.size(); ++i)
	{
		dfs(factPeople[i]);
	}

	int ans = 0;


	for (int i = 1; i < factParties.size(); ++i)
	{
		if (factParties[i] == 0) ++ans;
	}

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
지민이는 가장 좋아하는 이야기를 한다.
그 이야기는 진실 이거나 엄청나게 과장 돼 있다.
되도록이면 과장해서 얘기한다.
하지만 지민이는 거짓말쟁이 이기는 싫다.
몇몇 사람들은 이야기의 진실을 알고 있다.
따라서 이야기의 진실을 아는 사람이 있는 경우에 지민이는 진실만을 말해야 한다.
어떤 사람이 다른 파티에서 진실을 듣고 지민이에게 과장된 이야기를 듣게 되면 지민이는 거짓말쟁이가 된다.
지민이가 거짓말 쟁이가 되지 않게 해야한다.

사람의 수 N이 주어진다.
그리고 그이야기의 진실을 아는 사람이 주어진다.
각 파티에 오는 사람들의 번호가 주어진다.
지민이는 모든 파티에 참가해야 한다.
지민이가 거짓말 쟁이로 알려지지 않으려면, 과장된 이야기를 할 수 있는 파티 개수의 최댓값을 구하여라.


데이터 :




시간복잡도 :



아이디어 :
처음 주어진 진실을 아는 사람과 연관된 파티에 대해서 dfs를 돈다. 이때 다시 이 파티와 연관된 사람들에 대해서 for문을 돌면서 dfs를 돌게끔 해준다.
그렇게 모든 party에 대해서 진실을 말해야 하는 경우를 기록하고, 마지막으로 거짓말을 말해도 되는 경우에 대해서 개수를 세서 결과를 도출했다.

*/