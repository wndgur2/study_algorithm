#include <iostream>
#include <vector>

using namespace std;

/*
    관악산 기슭에는 보름달을 기다리는 달빛 여우가 한 마리 살고 있다.
    달빛 여우가 보름달의 달빛을 받으면 아름다운 구미호로 변신할 수 있다.
    하지만 보름달을 기다리는 건 달빛 여우뿐만이 아니다.
    달빛을 받아서 멋진 늑대인간이 되고 싶어 하는 달빛 늑대도 한 마리 살고 있다.
    
    관악산에는 1번부터 N번까지의 번호가 붙은 N개의 나무 그루터기가 있고, 그루터기들 사이에는 M개의 오솔길이 나 있다.
    오솔길은 어떤 방향으로든 지나갈 수 있으며, 어떤 두 그루터기 사이에 두 개 이상의 오솔길이 나 있는 경우는 없다.
    달빛 여우와 달빛 늑대는 1번 나무 그루터기에서 살고 있다.

    보름달이 뜨면 나무 그루터기들 중 하나가 달빛을 받아 밝게 빛나게 된다.
    그러면 달빛 여우와 달빛 늑대는 먼저 달빛을 독차지하기 위해 최대한 빨리 오솔길을 따라서 그 그루터기로 달려가야 한다.
    이때 달빛 여우는 늘 일정한 속도로 달려가는 반면, 달빛 늑대는 달빛 여우보다 더 빠르게 달릴 수 있지만 체력이 부족하기 때문에 다른 전략을 사용한다.
    달빛 늑대는 출발할 때 오솔길 하나를 달빛 여우의 두 배의 속도로 달려가고, 그 뒤로는 오솔길 하나를 달빛 여우의 절반의 속도로 걸어가며 체력을 회복하고 나서
    다음 오솔길을 다시 달빛 여우의 두 배의 속도로 달려가는 것을 반복한다.
    달빛 여우와 달빛 늑대는 각자 가장 빠르게 달빛이 비치는 그루터기까지 다다를 수 있는 경로로 이동한다.
    따라서 둘의 이동 경로가 서로 다를 수도 있다.

    출제자는 관악산의 모든 동물을 사랑하지만, 이번에는 달빛 여우를 조금 더 사랑해 주기로 했다.
    
    ! 그래서 달빛 여우가 달빛 늑대보다 먼저 도착할 수 있는 그루터기에 달빛을 비춰 주려고 한다.
    
    이런 그루터기가 몇 개나 있는지 알아보자.
    
    그루터기N, 오솔길M(2 ≤ N ≤ 4,000, 1 ≤ M ≤ 100,000)
*/

int nodeN;
vector<vector<pair<int, int>>> cost;
vector<pair<int, int>> wolfCostMap; //뛰어서 도착한 시간, 걸어서 도착한 시간.
vector<int> foxCostMap;

void setWolfCostMap(){
    int i, c;
    vector<pair<int, bool>> nearNodeIdxs = {{0, true}}; // int, bool >> run/walk

    while(nearNodeIdxs.size() > 0){
        int currentNodeIndex = nearNodeIdxs.back().first;
        bool run = nearNodeIdxs.back().second;
        nearNodeIdxs.pop_back();
        
        for(pair<int, int> costForNode: cost[currentNodeIndex]){
            i = costForNode.first;
            c = costForNode.second;
            if(run){
                int newCost = wolfCostMap[currentNodeIndex].second + c/2;

                if(wolfCostMap[i].first > newCost){
                    wolfCostMap[i].first = newCost;
                    nearNodeIdxs.push_back(make_pair(i, !run));
                }
            }
            else{
                int newCost = wolfCostMap[currentNodeIndex].first + c*2;

                if(wolfCostMap[i].second > newCost){
                    wolfCostMap[i].second = newCost;
                    nearNodeIdxs.push_back(make_pair(i, !run));
                }
            }
        }
    }
}

void setFoxCostMap(){
    int i, c;
    vector<int> nearNodeIdxs = {0};

    while(nearNodeIdxs.size() > 0){
        int currentNodeIndex = nearNodeIdxs.back();
        nearNodeIdxs.pop_back();
        for(pair<int, int> costForNode: cost[currentNodeIndex]){
            i = costForNode.first;
            c = costForNode.second;
            int newCost = foxCostMap[currentNodeIndex] + c;
            if(foxCostMap[i] > newCost){
                foxCostMap[i] = newCost;
                nearNodeIdxs.push_back(i);
            }
        }
    }
}

int main(){
    int linkN, a, b, d, i;

    cin >> nodeN >> linkN;

    cost = vector<vector<pair<int, int>>> (nodeN, vector<pair<int, int>> (0));
    wolfCostMap = vector<pair<int, int>> (nodeN, make_pair(200000, 200000));
    foxCostMap = vector<int> (nodeN, 200000);
    wolfCostMap[0].first = 0;
    wolfCostMap[0].second = 0;
    foxCostMap[0] = 0;

    while(linkN--){
        cin >> a >> b >> d;
        cost[a-1].push_back(make_pair(b-1, d*2));
        cost[b-1].push_back(make_pair(a-1, d*2)); // 짝수로 맞춰야 늑대가 뛸 때 시간이 정수임
    }

    // 여우가 늑대보다 먼저 도착할 수 있는 노드가 몇 개 있을까?

    // 여우와 늑대, 각각의 최소시간 맵을 구한다.
    setWolfCostMap();
    setFoxCostMap();

    int nodeCloserToFoxN = 0;
    for(i=1; i<nodeN; ++i){
        int wolfCurrentCost = wolfCostMap[i].first < wolfCostMap[i].second? wolfCostMap[i].first: wolfCostMap[i].second;
        if(foxCostMap[i] < wolfCurrentCost)
            ++nodeCloserToFoxN;
    }

    // 비용 출력
    // cout << "wolf" << endl;
    // for(pair<int, int> c: wolfCostMap){
    //     if(c.first < c.second)
    //         cout << c.first << ' ';
    //     else
    //         cout << c.second << ' ';
    // }

    // cout << endl << "fox" << endl;
    // for(int c: foxCostMap) cout << c << ' ';

    cout << nodeCloserToFoxN << endl;

    return 0;
}