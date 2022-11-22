#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    int size = brown + yellow;
    for (int i = 3; i * i <= size; ++i)
    {
        if (!(size % i))
        {
            int w = (size / i), yW = (w)-2, yH = i - 2;
            if (yW * yH == yellow)
            {
                return {w, i};
            }
        }
    }
}