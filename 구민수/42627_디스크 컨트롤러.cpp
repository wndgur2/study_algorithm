#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Job
{
    int start;
    int work;
    bool operator<(const Job j) const
    {
        return work > j.work;
    };
};
int solution(vector<vector<int>> jobs)
{
    priority_queue<Job> jobPQ;
    int answer = 0, time = 0, len = jobs.size();
    sort(jobs.begin(), jobs.end());
    while (!jobs.empty() || !jobPQ.empty())
    {
        if (!jobPQ.empty())
        {
            Job j = jobPQ.top();
            jobPQ.pop();
            time += j.work;
            answer += time - j.start;
        }
        while (!jobs.empty())
        {
            if (jobs.front()[0] > time)
            {
                if (jobPQ.empty())
                {
                    time = jobs.front()[0];
                }
                break;
            }
            else
            {
                jobPQ.push({jobs.front()[0], jobs.front()[1]});
                jobs.erase(jobs.begin());
            }
        }
    }
    return int(answer / len);
}