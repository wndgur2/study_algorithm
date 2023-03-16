#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
string tree;
char part(int left, int right)
{
    if (left == right)
    {
        return tree[left];
    }
    int mid = (left + right) >> 1;
    char lc = part(left, mid - 1);
    char rc = part(mid + 1, right);
    if (lc == 'f' || rc == 'f')
        return 'f';
    if (lc == '1' || rc == '1')
    {
        if (tree[mid] == '0')
            return 'f';
        return '1';
    }
    return tree[mid];
}
vector<int> solution(vector<ll> numbers)
{
    vector<int> answer;
    for (ll number : numbers)
    {
        tree.clear();
        while (number)
        {
            if (number % 2)
                tree.push_back('1');
            else
                tree.push_back('0');
            number >>= 1;
        }
        ll i = 1;
        while (tree.size() > (1 << i) - 1)
        {
            ++i;
        }
        while (tree.size() < (1 << i) - 1)
        {
            tree.push_back('0');
        }
        char ret = part(0, tree.size() - 1);
        if (ret == '1')
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}