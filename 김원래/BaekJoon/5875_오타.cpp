#include <iostream>
#include <vector>
#include <time.h>


using namespace std;

string str;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
	
	vector<int> d(100001);
	
	vector<int> Down_OneStackCntIdxes;

	cin >> str;

	int lastIdx = str.size() - 1;

	int stackCnt = 0;
	int closeCnt = 0;
	int openCnt = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(')
		{
			++openCnt;
			++stackCnt;
			d[i] = stackCnt;
			if (stackCnt < 2) Down_OneStackCntIdxes.push_back(i);
		}
		else
		{
			++closeCnt;
			--stackCnt;
			d[i] = stackCnt;
			if (stackCnt < 2) Down_OneStackCntIdxes.push_back(i);
		}
	}

	char changeCh;
	int operStackCnt;
	if (closeCnt > openCnt) {
		operStackCnt = 2;
		changeCh = ')';
	}
	else {
		changeCh = '(';
		operStackCnt = -2;
	}

	int answer = 0;

	for (int i = 1; i < str.size()-1; ++i)
	{
		if (str[i] == changeCh)
		{
			bool flag = true;

			for (int j = 0; j < Down_OneStackCntIdxes.size(); ++j)
			{
				if (Down_OneStackCntIdxes[j] < i)
				{
					if (d[Down_OneStackCntIdxes[j]] < 0)
					{
						flag = false;
						break;
					}
				}
				else
				{
					if (d[Down_OneStackCntIdxes[j]] + operStackCnt < 0) {
						flag = false;
						break;
					}
				}
			}
			
			if (d[lastIdx] + operStackCnt != 0) flag = false;
			if (flag == true) ++answer;
		}
	}

	if (str[0] == ')') answer = 1;
	if (str[str.size() - 1] == '(') answer = 1;
	if (str.size() % 2 == 1) answer = 0;

	
	std::cout << answer;
	
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
올바른 괄호쌍을 좋아하는 키파는 최근에 노트북을 샀다.
여는 괄호와 닫는 괄호가 서로 잘못 입력하지 않았는지 걱정이 된다.
키파를 도와 올바른 괄호쌍이 되도록 고쳐주자.

최대 한 번의 오타를 냈다.

올바른 괄호쌍
1. ()는 올바른 괄호쌍이다.
2. (A)또한 올바른 괄호쌍이다.
3. AB또한 올바른 괄호 쌍이다.

입력으로 괄호쌍이 주어진다. 이 괄호쌍에서 하나의 문자만 고쳐서 올바른 괄호쌍이 될 수 있는 경우의 수를 출력하라.
하나의 문자만 고친다는 것은 지운다는 의미는 아닐 것이다.
이 중에서 하나를 무조건 고쳐야 한다.


데이터 :



시간복잡도 :
nlogN 안에 해결해야 한다.


아이디어 :
)를 채우는 스택을 하나 둔다. 
d라는 배열에 현 위치까지 계산 했을 때 스택에 들어가 있는 ) 개수를 넣어준다.
(이게 나오면 스택값을 하나 올리고, ) 이게 나오면 스택값을 하나 내린다.
그렇게 해서 d배열에 스택Cnt가 들어가게 된다. 이때 스택Cnt값이 1이하인 경우에는 또 다른 배열에 이를 저장해준다.
이 배열에 있는 값들만을 나중에 비교를 해서 현재 오타가 난 곳을 바꾸어도 되는지를 확인한다.




*/