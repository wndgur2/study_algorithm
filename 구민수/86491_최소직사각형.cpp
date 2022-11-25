#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int highW = 0, highH = 0;
    for (vector<int> size : sizes)
    {
        if (size[0] < size[1])
        {
            swap(size[0], size[1]);
        }
        if (highW < size[0])
            highW = size[0];
        if (highH < size[1])
            highH = size[1];
    }
    return highW * highH;
}