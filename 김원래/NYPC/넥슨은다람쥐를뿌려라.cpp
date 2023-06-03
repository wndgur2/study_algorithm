#include <iostream>
#include <vector>
#include <time.h>
#include <deque>

using namespace std;

vector<vector<char>> matrix;
deque<pair<int, int>> blank;
int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	clock_t start, finish;
	double duration;


	cin >> N;
	start = clock();

	matrix.resize(N+1);

	int idx = 1;

	int mouse = 0, user = 0;

	while (idx < N+1)
	{
		matrix[idx].resize(N+1);


		for (int i = 1; i < N + 1; i++)
		{
			char input;
			cin >> input;

			switch (input) {
				case 'D' :
					mouse++;
					break;
				case 'C' :
					user++;
					break;
				default :
					blank.push_back(make_pair(idx,i));
			}

			matrix[idx][i] = input;
		}

		idx++;
	}

	srand((unsigned int)time(NULL));

	if (mouse < user * 2)
	{
		int needs = user * 2 - mouse;

		for (int i = 0; i < needs; i++)
		{
			int idx = rand() % blank.size();

			int y = blank[idx].first;
			int x = blank[idx].second;

			matrix[y][x] = 'D';

			blank.erase(blank.begin() + idx);
		}

		

	}

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			std::cout << matrix[i][j];
		}

		std::cout << "\n";
	}

	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	std::cout << duration << "초" << "\n";

	return 0;
}

/*
요구사항 :
다람쥐가 적어도 플레이어 수보다 두 배가 되도록 유지한다.
사람이 많을 때도 충분한 양의 다람쥐가 있게끔 하기로 했다.

데이터 :



시간복잡도 :

아이디어 :


*/