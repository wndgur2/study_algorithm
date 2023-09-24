#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

int main(){
  int n, i;
  ll inputs;
  vector<int> a;
  a.reserve(3);
  a.emplace_back(1);
  a.emplace_back(2);
  a.emplace_back(3);
  for(int& v: a)
    cout << v << endl;
  return 0;
}