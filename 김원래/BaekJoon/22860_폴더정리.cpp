#include <iostream>
#include <vector>
#include <time.h>
#include <unordered_map>
#include <sstream>

using namespace std;


int N, M, Q;
int kinds =0, nums=0;
unordered_map<string, vector<string>> map;
unordered_map<string, int> visit;


vector<string> split(string input, char delimiter) {
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push_back(temp);
	}

	return answer;
}

void search(string obj)
{
	auto iter = map.find(obj);
	vector<string> v = (*iter).second;

	for (int i = 0; i < v.size(); i++)
	{
		if (map.find(v[i]) == map.end())
		{
			if (visit.find(v[i]) == visit.end())
			{
				kinds++;
				visit.insert(make_pair(v[i], 1));
			}

		}


		if (map.find(v[i]) == map.end()) nums++;
		else
		{
			search(v[i]);
		}
		
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	map.insert(make_pair("main", vector<string>()));

	cin >> N >> M;

	for (int i = 0; i < N + M; i++)
	{
		string P, F;
		int C;

		cin >> P >> F >> C;

		if (map.find(P) == map.end())
		{
			map.insert(make_pair(P, vector<string>()));
		}

		auto iter = map.find(P);
		(*iter).second.push_back(F);

		if (C) {
			if (map.find(F) == map.end())
			{
				map.insert(make_pair(F, vector<string>()));
			}
		}
	}

	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		string str;
		cin >> str;

		vector<string> v = split(str, '/');

		string obj = v[v.size() - 1];

		search(obj);
		visit.clear();

		cout << kinds << " " << nums << "\n";

		kinds = 0; nums = 0;
		
	}


	

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
Folder - File 구조에서
파일 이름이 같은 경우 동일한 파일이다.
한 폴더 안에는 같은 이름의 파일이 두 개 이상 존재 할 수 없다.
main 하위 디렉토리에 같은 이름의 폴더가 두개 이상 존재 할 수 없다.
폴더 정리를 하기 위해 main 폴더 하위에 있는 파일들을 확인하려고 한다.
주어지는 쿼리에 대해 폴더와 파일의 정보를 알려주는 프로그램을 만들어보자.

입력은 P, F, C 순으로 받으며, 이 값은 P는 상위 폴더 F는 폴더 또는 파일 C는
F가 폴더인지 파일인지를 나타내는데 1이면 폴더 0이면 파일이다.
두번째 줄부터 N+M+1번까지 줄까지 디렉토리 구조가 주어진다.
N+M+2번째 줄에는 쿼리의 개수 Q를 입력 받고,
Q개의 쿼리를 입력 받는다.
main 부터 폴더의 경로 정보가 들어온다.
예를들어 main 폴더 안에 FolderB에 대한 쿼리가 들어온다면, FolderB의 경로인
main/FolderB로 주어진다. 반드시 폴더가 존재하는 경로로 주어짐을 보장한다.
쿼리에 순서대로 한 줄씩 폴더 하위에 있는 파일의 종류의 개수와 총 파일 개수를 출력한다.

데이터 :


시간복잡도 :
1000개의 폴더와 1000개의 파일을 가지고 있는 main 디렉터리의 경우
최대 2000번의 DFS를 돌게 된다. 최대 N+M이 2000 이기 때문에
2000*2000 = 4000000의 시간이 걸린다.

아이디어 :
트리 구조로 디렉토리들을 표현한다. 트리 구조는 vector를 value로 갖는 unordered_map을 이용한다.
value에 들어가는 vector는 string을 template으로 갖고 각각의 원소는 unordered_map의 key가 된다.



*/