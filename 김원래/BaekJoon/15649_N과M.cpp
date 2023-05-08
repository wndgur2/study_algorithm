#include <iostream>
#include <vector>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };


void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i;
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	dfs(0);

	return 0;
}

/*
요구사항 :
자연수 N과 M이 주어졌을 때 길이가 M인 수열을 구하는 프로그램을 작성하여라
1부터 N까지 자연 수 중에서 중복 없이 M개를 고르는 수열

	
데이터 :
int N : (1~8)  
int M : (1~N) 수열의 길이

시간복잡도 :
M과 N의 숫자가 작기 때문에 고려를 하지않고 진행을 했다.

아이디어 :
N에 포함되는 수 예를 들어 1이라고 할때, 1이 포함된 경우 그리고 포함되지 않은 경우로 하여
DFS를 돈다. 그리고 현재 확인한 값에서 값을 하나 늘려주고, 다시 DFS를 돌게 한다.
이렇게 해서 포함되지 않는 경우는 카운팅 하지 않고 포함된 경우에 한하여
값이 m이 되면은 값을 출력하고 더이상 DFS 연산을 하지 않게 한다.


*/