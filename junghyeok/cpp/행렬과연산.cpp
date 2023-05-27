#include <string>
#include <vector>
#include <deque>

using namespace std;

void shiftrow(deque<deque<int> > &rc, deque<int> &firstCol, deque<int> &lastCol) {
    firstCol.push_front(firstCol.back());
    firstCol.pop_back();
    lastCol.push_front(lastCol.back());
    lastCol.pop_back();

    if(rc.front().size() == 0) return;
    deque<int> lastRow = rc.back();
    rc.pop_back();
    rc.push_front(lastRow);
}

void rotate(deque<deque<int> > &rc, deque<int> &firstCol, deque<int> &lastCol) {
    int first = firstCol.front();
    int last = lastCol.back();
    firstCol.pop_front();
    lastCol.pop_back();

    if(rc.front().size() == 0){
        firstCol.push_back(last);
        lastCol.push_front(first);
        return;
    }

    firstCol.push_back(rc.back().front());
    lastCol.push_front(rc.front().back());
    rc.front().pop_back();
    rc.back().pop_front();
    rc.front().push_front(first);
    rc.back().push_back(last);
}

vector<vector<int> > solution(vector<vector<int> > rc, vector<string> operations) {
    deque<deque<int> > dq;
    deque<int> firstCol;
    deque<int> lastCol;
    int n = rc.size();
    
    for(int i = 0; i < n; i++) {
        deque<int> row(rc.back().begin()+1, rc.back().end()-1);
        dq.push_front(row);
        firstCol.push_front(rc.back().front());
        lastCol.push_front(rc.back().back());
        rc.pop_back();
    }
    for(string op : operations) {
        if (op.back() == 'w') {
            shiftrow(dq, firstCol, lastCol);
        } else{
            rotate(dq, firstCol, lastCol);
        }
    }
    vector<vector<int> > answer;
    for(int i = 0; i < n; i++) {
        vector<int> row;
        row.push_back(firstCol.front());
        firstCol.pop_front();
        row.insert(row.end(), dq.front().begin(), dq.front().end());
        dq.pop_front();
        row.push_back(lastCol.front());
        lastCol.pop_front();
        answer.push_back(row);
    }
    return answer;
}

int main(){
    vector<vector<int> > rc = {{1, 1,1,1,1}, {2, 2,2,2,2}, {3, 3,3,3,3}};
    vector<string> operations = {"w", "R"};
    vector<vector<int> > answer = solution(rc, operations);
    for (vector<int> row : answer) {
        for (int num : row) {
            printf("%d ", num);
        }
        printf("\n");
    }
    return 0;
}