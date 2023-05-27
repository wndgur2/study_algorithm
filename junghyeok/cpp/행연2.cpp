#include <string>
#include <vector>
#include <deque>

using namespace std;

void shiftrow(deque<deque<int> > &rc, deque<int> &firstCol, deque<int> &lastCol) {
    firstCol.push_front(firstCol.back());
    firstCol.pop_back();
    lastCol.push_front(lastCol.back());
    lastCol.pop_back();
}

void rotate(deque<deque<int> > &rc, deque<int> &firstCol, deque<int> &lastCol, int idx) {
    int n = rc.size();
    int m = rc[0].size();
    if (m == 0) {
        lastCol.push_front(firstCol.front());
        firstCol.pop_front();

        firstCol.push_back(lastCol.back());
        lastCol.pop_back();
        return;
    }

    rc[idx].push_front(firstCol.front());
    firstCol.pop_front();

    lastCol.push_front(rc[idx].back());
    rc[idx].pop_back();

    rc[(idx - 1 + n) % n].push_back(lastCol.back());
    lastCol.pop_back();

    firstCol.push_back(rc[(idx - 1 + n) % n].front());
    rc[(idx - 1 + n) % n].pop_front();
}

vector<vector<int> > solution(vector<vector<int> > rc, vector<string> operations) {
    deque<deque<int> > dq;
    deque<int> firstCol;
    deque<int> lastCol;

    int n = rc.size();
    int m = rc[0].size();
    vector<vector<int>> answer(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        firstCol.push_back(rc[i][0]);
        lastCol.push_back(rc[i][m - 1]);
    }
    for (int i = 0; i < n; i++) {
        deque<int> tmp;
        for (int j = 1; j < m - 1; j++) {
            tmp.push_back(rc[i][j]);
        }
        dq.push_back(tmp);
    }
    int idx = 0;
    for(string op : operations) {
        if (op.back() == 'w') {
            shiftrow(dq, firstCol, lastCol);
            idx = (idx - 1 + n) % n;
        } else{
            rotate(dq, firstCol, lastCol, idx);
        }
    }

    for (int i = 0; i < n; i++) {
        dq[(idx + i) % n].push_front(firstCol.front());
        firstCol.pop_front();
        dq[(idx + i) % n].push_back(lastCol.front());
        lastCol.pop_front();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            answer[i][j] = dq[(idx + i) % n][j];
        }
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