#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> large;
    vector<int> small;
    for(int i=0;i<sizes.size();i++)
    {
        if(sizes[i][0] >= sizes[i][1])
        {
            large.push_back(sizes[i][0]);
            small.push_back(sizes[i][1]);
        }
        else
        {
            large.push_back(sizes[i][1]);
            small.push_back(sizes[i][0]);
        }
    }
    sort(large.begin(),large.end());
    sort(small.begin(),small.end());
    

    answer = large[large.size()-1] * small[small.size()-1];
    return answer;
}

//지갑의 크기를 정하려고한다.
//다양한 모양과 크기의 명함들을 모두 수납 할 수 있다.
//작아서 들고 다니기 편한 지갑
//명함들의 가로 세로의 길이가 주어짐
//가장 긴 가로와 세로의 크기로 하면 될 것 같으나, 그게아님
//가장 가로가 긴 명함을 세로로도 넣을 수 있다.
//그렇다면 여기서 봐야 할 것은 가장 긴 가로와 세로를 찾고,
//그중에서 큰 것을 선택한다. 그러면 그 큰 크기는 무조건 가로 또는 세로가 되어야 한다.
//그러면 그것을 가로로 딱 정했어.
//결론적으로 원소를 돌면서 가로와 세로의 길이를 비교하고 더 큰것을 하나의 배열에
//그리고 작은 것을 하나의 배열에 넣어준다.
//그리고 각각의 배열의 최댓값을 추출하면 답이되겠군!