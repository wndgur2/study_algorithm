#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>


using namespace std;

int N, M;
vector<int> Rides;
vector<int> ExistRidesTime;
vector<int> RidesTimeCnt;


// 현재 해야 하는 것이 주어진 시간에 대해서 그 시간에 몇개의 놀이기구를 탈 수 있는가?

pair<long long, long long> Search(long long start, long long end)
{
	long long mid = (start + end) / 2;
	long long Cnt = M;

	if (Cnt >= N) return make_pair(N, 0);

	for (int i = 0; i < ExistRidesTime.size(); ++i)
	{
		Cnt += (mid / ExistRidesTime[i]) * RidesTimeCnt[ExistRidesTime[i]];
	}

	if (Cnt > N)
	{
		long long CompMid = mid;
		while (true)
		{
			long long CompCnt = M;
			for (int i = 0; i < ExistRidesTime.size(); ++i)
			{
				CompCnt += (CompMid / ExistRidesTime[i]) * RidesTimeCnt[ExistRidesTime[i]];
			}
			if (Cnt > CompCnt)
			{
				if (CompCnt < N)
				{
					return make_pair(Cnt ,CompMid+1);
				}
				break;
			}
			--CompMid;
		}

		return Search(start, mid - 1);
	}
	else if (Cnt < N)
	{
		return Search(mid + 1, end);
	}
	else
	{
		while (true)
		{
			long long CompCnt = M;
			for (int i = 0; i < ExistRidesTime.size(); ++i)
			{
				CompCnt += (mid / ExistRidesTime[i]) * RidesTimeCnt[ExistRidesTime[i]];
			}
			if (Cnt > CompCnt) break;
			--mid;
		}
		return make_pair(Cnt,mid+1);
	}
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> N >> M;
	Rides = vector<int>(10001, 0);
	RidesTimeCnt = vector<int>(31, 0);

	for (int i = 1; i < M+1; ++i)
	{
		int num;
		cin >> num;
		if (RidesTimeCnt[num] == 0) ExistRidesTime.push_back(num);
		++RidesTimeCnt[num];
		Rides[i] = num;
	}

	long long Time = 60'000'000'000;
	
	pair<long long, long long> Last = Search(0, Time);
	if (Last.second == 0) return N;


	for (int i = M; i > 0; --i)
	{
		if (Rides[i] > 0)
		{
			if ((Last.second % Rides[i]) == 0)
			{
				if (Last.first == N)
				{
					cout << i;
					return 0;
				}
				else
				{
					--Last.first;
				}
			}
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
N명이 아이들이 한 줄로 서서 1인승 놀이기구를 기다리고 있다.
M종류의 1인승 놀이기구가 있다. 1~M까지 번호가 매개져 있다.

모든 놀이기구는 각각 운행 시간이 정해져 있다.
운행 시간이 지나면 탑승하고 있던 아이는 내리게 된다.
놀이기구가 비어 있으면 현재 줄에서 가장 앞에 서 있는 아이가 빈 놀이기구에 탑승한다.
여러개의 놀이기구가 동시에 비어 있으면, 더 작은 번호가 적힌 놀이기구를 먼저 탑승한다.



데이터 :
int N : 어린이 수(1~20억)
int M : 놀이기구 수(1~1만)



시간복잡도 :


아이디어 :
운행시간을 기준으로 운행시간에 해당하는 놀이기구의 Cnt를 센다.
그리고 현재시간 

*/