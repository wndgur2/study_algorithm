#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int line=1;
    while(1)
    {
        if(yellow%line==0)
        {
            if((yellow/line+2)*2 + 2*line == brown)
            {
                answer.push_back(yellow/line+2);
                answer.push_back(line+2);
                break;
            }
            else
            {
                line++;
            }
        }
        else
        {
            line++;
        }

    }
    
   
    
    return answer;
}

//중앙에는 노란색이 칠해져있다.
//테두리 한줄은 갈색으로 칠해져있다.
//노란색과 갈색으로 칠해진 격자의 수가 주어짐
//전체 카펫의 크기는 주어지지 않음
//카펫의 가로,세로의 크기를 구해라

//카펫은 가로가 길다. (같을 수도 있다.)

//노랑색이 한줄인경우, 두줄인 경우, 세줄인 경우
//한줄일때 (yellow+2)*2+2
//두줄일때 (yellow/2 + 2)*2+4
//line줄일 때 (yellow/line +2)*2 + 2*line
//세로와 가로가 같거나 가로가 더 클때 line+2 <= yellow/line + 2 