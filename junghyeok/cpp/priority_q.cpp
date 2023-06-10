#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main(){

    priority_queue<pair<int, int> > q;
    q.push(make_pair(1,1));
    q.push(make_pair(1,2));
    q.push(make_pair(2,3));
    q.push(make_pair(3,2));

    printf("%d\n", q.top().first);
    printf("%d\n", q.top().second);
    
    return 0;
}