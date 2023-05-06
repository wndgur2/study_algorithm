#include <iostream>
using namespace std;
// N과 M
void dfs(n, m, nums){
    if(m==0){
        for(int i=0; i<nums.size(); i++){
            cout << nums[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=1; i<=n; i++){
        if(nums.size()==0 || nums[nums.size()-1] < i){
            nums.push_back(i);
            dfs(n, m-1, nums);
            nums.pop_back();
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums;
    dfs(n, m, nums);
    return 0;   
}