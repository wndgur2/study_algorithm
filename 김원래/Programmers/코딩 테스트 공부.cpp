#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int max_alp = 0;
int max_cop = 0;
int dp[200][200];


int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    
    for(int i=0;i<problems.size();i++)
    {
        if(problems[i][0] > max_alp) max_alp=problems[i][0];
        if(problems[i][1] > max_cop) max_cop=problems[i][1];
    }
    
    if(alp >= max_alp && cop >= max_cop) return 0;
    
    for(int i=0;i<max_alp+1;i++)
    {
        for(int j=0;j<max_cop+1;j++)
        {
            dp[i][j] = 2100000000;
        }
    }

    if(alp > max_alp) alp = max_alp;
    if(cop > max_cop) cop = max_cop;
    
    dp[alp][cop] = 0;
    
    for(int i=alp;i<max_alp+1;i++)
    {
        
        for(int j=cop;j<max_cop+1;j++)
        {
            if(j+1 <= max_cop)
            {
                dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
            }
            if(i+1 <= max_alp)
            {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
            }
            
            
            for(int k=0;k<problems.size();k++)
            {
                if(problems[k][0] <= i && problems[k][1] <= j)
                {
                    
                    dp[min(i+problems[k][2], max_alp)][min(j+problems[k][3],max_cop)] = min(dp[min(i+problems[k][2],max_alp)][min(j+problems[k][3],max_cop)], dp[i][j]+problems[k][4]);
                }
            }
        }
    }
    
    answer = dp[max_alp][max_cop];
    
    return answer;
}

/*

요구사항
코딩테스트를 위해서 준비를 하는데 알고리즘에 대한 지식과 코딩 구현 능력을 키우려고 한다.
거기서 이를 각각 알고력, 코딩력이라고 하며 해당 값은 0이상의 정수이다.
특정 문제를 풀기 위해서는 특정 알고력, 코딩력이 필요합니다.
풀지 못하는 문제를 해결하기 위하여 알고력과 코딩력을 높혀야 한다.
알고력을 1높이기 위해서는 1의 시간이 필요하다
코딩력을 1높이기 위해서는 1의 시간이 필요하다
현재 풀 수 있는 문제 중 하나를 풀어 알고력과 코딩력을 높입니다.
각 문제마다 문제를 풀면 올라가는 알고력과 코딩력이 정해져 있습니다.
문제를 하나 푸는데에 문제가 요구하는 시간이 필요합니다. 또한 같은 문제를 여러번 푸는 것도 가능합니다.
주어진 모든 문제를 풀 수 있는 알고력과 코딩력을 얻는 최단시간을 구하시오.

데이터
int alp : 초기 알고력(0~150)
int cop : 초기 코딩력(0~150)
vector<vector<int>> problems : 문제의 대한 정보를 가지고 있음(1 ~ 100)
{알고력 요구사항, 코딩력 요구사항, 증가하는 알고력, 증가하는 코딩력, 푸는데 걸리는시간}


시간복잡도
alp x cop x problems를 3중첩 for문을 통하여 돌아도 100만 정도의 연산이 수행되므로 문제없을 것이라 예상이 된다.

아이디어
dp를 이용한 풀이가 가능하다고 생각이 든다. alp와 cop의 현재 값을 기준으로 2차원 배열을 만들어준다.
예를들어 배열의 (1,2) 인덱스에 3이 들어가 있다면 alp=1 cop=2 만큼 늘리기 위해서는 최소 3시간이 걸린다는 의미이다.
여기서 이 2차원 배열의 최대 인덱스는 (150,150)이다. 그 이유는 alp와 cop는 최대 150까지 값이 존재하기 때문이다.
그리고 이 dp배열을 채울 때 하나 더 생각해야 하는 것은 초기의 alp와 cop의 값이다.
현재 alp와 cop값과 problems의 요구 값들을 비교하여 만약에 비교한 값이 현재 alp와 cop값보다 작은 경우에 한하여
dp를 채우게 해줍니다. dp배열을 모두 채운 이후에,
problems에서 최대로 요구하는 alp와 cop값에 해당하는 dp 배열의 값을 return하면 답이 됩니다.

*/