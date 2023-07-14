#include <iostream>
#include <vector>

using namespace std;

int charsToNumber(vector<char> &numbers){
    string s = "";

    for(char c: numbers)
        s += c;

    return stoi(s);
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<char> numbers (n);
    vector<int> maxNumbers (k, 0);

    for(int i=0; i<n; ++i)
        cin >> numbers[i];
    
    maxNumbers[0] = charsToNumber(numbers);

    findMax(0, 0, numbers, maxNumbers); //! 이거 구현해야함

    cout << maxNumbers[k-1] << endl;
    return 0;
}