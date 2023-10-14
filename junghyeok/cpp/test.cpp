#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<vector<vector<int>>> a = {{{}}};
    
    sort(a[0][0].begin(), a[0][0].end());

    // while(a[0][0].size() > 2){
    //     a[0][0].pop_back();
    // }
    for(auto t: a[0][0]){
        cout << t << ' ';
    }
    // cout << a[0][0].back() << endl;

    return 0;
}