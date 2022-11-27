#include <string>
#include <vector>

using namespace std;

int alphaNum(char c)
{
    return (c - 'A') > (c - 'A' - 26) * -1 ? (c - 'A' - 26) * -1 : (c - 'A');
}
int solution(string name)
{
    int answer = 0;
    for (char c : name)
        answer += alphaNum(c);
    int minVal = name.length() - 1; // 오른쪽으로 이동할 값
    for (int i = 0; i < name.length(); ++i)
    {
        int nextI = i + 1;
        while (nextI < name.length() && name[nextI] == 'A')
            ++nextI;
        int right = name.length() - nextI;
        int minLR = i > right ? right : i;
        minVal = minVal > minLR + i + right ? minLR + i + right : minVal;
    }
    return answer + minVal;
}