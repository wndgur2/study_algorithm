#include <iostream>
#include <vector>
#include <time.h>
#define MAX_SIZE 10000002 

using namespace std;

vector<int> graph;
vector<int> Counts;
int N;


void Init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		graph[i] = i;
		Counts[i] = 1;
	}
}

int Find(int child)
{
	if (graph[child] == child)
	{
		return child;
	}
	else
	{ 
		return graph[child] = Find(graph[child]);
	}
}

void Union(int a, int b)
{

	int x = Find(a);
	int y = Find(b);

	if (x < y)
	{
		graph[y] = x;
		Counts[x] += Counts[y];
		Counts[y] = 0;
	}
	else
	{
		graph[x] = y;
		Counts[y] += Counts[x];
		Counts[x] = 0;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	Counts.resize(MAX_SIZE, 0);
	graph.resize(MAX_SIZE, 0);

	Init();

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		char input1;
		int input2, input3;

		cin >> input1;
		switch (input1)
		{
		case 'I' :
			cin >> input2 >> input3;
			Union(input2, input3);
			break;
		case 'Q' :
			cin >> input2;
			cout << Counts[Find(input2)] <<'\n';
			break;
		}
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
로봇을 만드려고 한다.
1. 상자 안에 여러 로봇의 부품들이 섞여있다.
2. 어떤 부품이 어느 로봇의 부품인지 표시 돼 있지 않다.
3. 호재의 도움을 받아 로봇의 부품을 표시 할 수 있다.
4. 부품은 1 ~ 천만 까지의 정수로 표현한다.
5. 서로 다른 로봇은 공통 부품을 가지지 않는다.

호재는 두가지 지시를 한다.
1. 서로 다른 부품 2개를 말해주며, 두 부품은 같은 로봇의 부품이라는 정보를 준다.
2. 부품 i에 대해서, 지금까지 알아낸 robot(i)의 부품이 몇개냐고 물어본다.

입력은 이렇게 들어온다.
1. 부품 2개가 같은 로봇의 부품인지 알려줄 때 -> I a b
2. 어떤 로봇의 부품이 몇 개 인지를 물어 볼 때에는 Q c의 형태로 들어온다.



데이터 :



시간복잡도 :


아이디어 :
먼저 생각 난 알고리즘은 Union-Find 알고리즘이다. root 값을 가장 작은 정수 값으로 두면서 같은 로봇끼리
묶을 수 있다. 그 이후에 Cnt 값을 구해야 하는데, Cnt 값을 구하기 위해서는 새롭게 들어온 부품인지를 확인 해야한다.
Parent가 바뀌게 되면, 그 경우에 Parent 쪽으로 자신이 가지고 있는 Cnt 값을 넘겨 주어야 한다.
visit 배열도 존재해야한다.



*/