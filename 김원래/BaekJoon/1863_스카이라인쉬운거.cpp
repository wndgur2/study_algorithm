#include <iostream>
#include <vector>
#include <time.h>
#include <stack>

using namespace std;


stack<int> stk;
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> n;

	int Count = 0;

	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;

		if (!stk.empty() && stk.top() > y)
		{
			while (!stk.empty() && stk.top() >= y)
			{
				if (stk.top() > y)
				{
					++Count;
				}
				stk.pop();
			}
		}
		stk.push(y);
	}

	while (!stk.empty())
	{
		if (stk.top() != 0)
		{
			++Count;
		}
		stk.pop();
	}

	cout << Count;
	

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
태양이 질 때에 보이는 윤곽을 스카이라인 이라고 하는데,
이 문제의 경우 스카이라인을 나타내는 배열이 주어지고, 이 배열을 통해서
최소 도시의 세워진 건물은 몇 개 일까를 묻고 있다.
세워진 건물을 최소로 하기 위해서는 최대한 큰 직사각형을 만드는 작업을 하면 된다.


데이터 :



시간복잡도 :


아이디어 :
일단 눈에 들어오는 것은 y좌표가 달라지면 새로운 건물이 있을 확률이 생겨난다는 것이다.
그리고 y좌표가 같다하더라도 y좌표가 0이 되는 부분이 있으면 따로 봐야 한다는 점이다.

stack을 이용하여 새로운 직사각형을 그릴 수 있는 상황을 업데이트 해준다.
y값을 stack에 쌓으면서 만약에 현재 stack에 추가 하려는 값이 stack의 top 값보다 작다라고 한다면
현재 추가 하려는 y값과 같거나 작아질 때 까지 stack을 pop하면서 Count값을 늘려준다.

그리고 마지막으로 stack을 모두 비우면서 Count값을 늘려준다.


*/