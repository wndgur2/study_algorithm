#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.first > b.first;
}

int solution(vector<int> citations) {
    int answer = 0;
    unordered_map<int,int> map;
    for(int i=0;i<1001;i++)
    {
        if(i < citations.size())
        {
            if(map.end()==map.find(citations[i]))
            {
                map.insert(make_pair(citations[i],1));
            }
            else
            {
                map[citations[i]]++;
            }
        }
        
        
        if(map.end()==map.find(i) && i!=0)
        {
            map.insert(make_pair(i,0));
        }
    }
    
    vector<pair<int,int>> v(map.begin(),map.end());
    sort(v.begin(),v.end(),compare);
    
    for(int i=0;i<v.size();i++)
    {
        if(v[i].first <= v[i].second)
        {
            int flag = 1;
            for(int j=i+1;j<v.size();j++)
            {
                if(v[j].second > v[i].first)
                {
                    flag = 0;
                    v[i+1].second += v[i].second;
                    break;
                }
            }
            if(flag == 1)
            {
                answer = v[i].first;
                break;
            }
        }
        else
        {
            v[i+1].second += v[i].second;
        }
    }
    return answer;
}

//생산성과 영향력을 나타내는 지표 = H-Index
//H-Index = h
//논문 n편중에서 H-index번 이상 이용된 논문이 H-index편 이상이고 나머지 논문이
//H-index번 이하 인용됐다면 H-index의 최댓값이 이 과학자의 H-Index이다.


//논문중에서 인용이 h번 이상된 논문이 h편 이상이다. ex) 2번 인용된 논문이 2편이상이면 H-index가 2인것이다.
//이러한 H-index값이 최대인 경우가 h이다.

//논문의 수는 1000개, n^2까지는 괜찮을듯?
//인용횟수가 0번~1만번, 예를 들어서 하나의 논문에 1만번 인용이 되었는데 근데 그 논문에만 인용이 됐다면 
//H-index =1인것
//인용수가 많으면 좋다. 하지만 이 인용수와 같은 값이 h개만큼 있어야한다.
//map을써서 숫자를 센다. 그리고 map을 vector로 변환하여 sort한다. 큰 수 부터 그리고 두 수가 같거나 더 많은 경우를 찾는다. 그리고 만약에 안됐다. 그러면 현재 값을 뒤에 더해준다.

//나머지 논문이 h번 이하 인용됐는지도 확인해야하는가 ? 
//나머지 논문이 h번 이하라는 것은 무슨 소리인가? 나머지를 다 확인을 해봐야 한다.

//독해력이 문제인가, 질문하기 부분에서 힌트를 얻고 다시 진행을 했다.
//[6, 5, 5, 5, 3, 2, 1, 0], 4 인 테스트케이스에서 문제가 발생을 한다.
//바로 h-index가 꼭 citations 안에 들어간 값이 아닌 경우가 있기 때문이다.