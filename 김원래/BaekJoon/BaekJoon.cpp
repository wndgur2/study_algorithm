#include <iostream>
#include <vector>
#include <queue>
#include <time.h>
#include <math.h>
#include <stack>

using namespace std;

int N, R, k, l;
vector<vector<int>> matrix;

// 1 -> 4
// 2 -> 3
// 3 -> 2
// 4 -> 1
// x+3 = y
// x+1 = y
// x-1 = y
// x-3  = y



void first_func()
{
	int y = 1;
	int size = pow(2, l);

	while (y < pow(2, N))
	{
		for (int i = 1; i <pow(2,N)+1; ++i)
		{
			int _size = size / 2;
			for (int j = 0; j < _size; j++)
			{
				int* top = &matrix[y + j][i];
				int* down = &matrix[y + size - 1 - j][i];
				int tmp = *top;
				*top = *down;
				*down = tmp;
			}
		}
		y += size;
	}
}

void second_func()
{
	int x = 1;
	int size = pow(2, l);

	while (x < pow(2, N))
	{
		for (int i = 1; i < pow(2, N) + 1; ++i)
		{
			int _size = size / 2;
			for (int j = 0; j < _size; j++)
			{
				int* top = &matrix[i][x+j];
				int* down = &matrix[i][x + size - 1 - j];
				int tmp = *top;
				*top = *down;
				*down = tmp;
			}
		}
		x += size;
	}
}

void third_func()
{
	int size = pow(2, l);
	vector<vector<int>> tmp_matrix(129, vector<int>(129, 0));
	for (int i = 1; i < pow(2, N) + 1; i += size)
	{
		for (int j = 1; j < pow(2, N) + 1; j += size)
		{
			int dest_x = j + size - 1;
			int dest_y = i;
			for (int k = i; k < i + size; ++k)
			{
				int _dest_y = dest_y;
				for (int m = j; m < j + size; ++m)
				{
					tmp_matrix[_dest_y][dest_x] = matrix[k][m];
					++_dest_y;
				}
				--dest_x;
			}
		}
	}
	matrix = tmp_matrix;
}

void fourth_func()
{
	int size = pow(2, l);
	vector<vector<int>> tmp_matrix(129, vector<int>(129, 0));
	for (int i = 1; i < pow(2, N) + 1; i += size)
	{
		for (int j = 1; j < pow(2, N) + 1; j += size)
		{
			int dest_x = j;
			int dest_y = i+size-1;
			for (int k = i; k < i + size; ++k)
			{
				int _dest_y = dest_y;
				for (int m = j; m < j + size; ++m)
				{
					tmp_matrix[_dest_y][dest_x] = matrix[k][m];
					--_dest_y;
				}
				++dest_x;
			}
		}
	}
	matrix = tmp_matrix;
}

void fifth_func()
{
	int size = pow(2, l);
	vector<vector<int>> tmp_matrix(129, vector<int>(129, 0));
	int cnt = 0;
	for (int i = 1; i < pow(2, N) +1; i += size)
	{
		++cnt;
		for (int j = 1; j < pow(2, N)+1; j += size)
		{
			int dest_y = (pow(2,N) - (pow(2,l) *cnt)) + 1;
			int dest_x = j;
			for (int k = i; k < i + size; ++k)
			{
				for (int m = j; m < j + size; ++m)
				{
					tmp_matrix[dest_y][dest_x++] = matrix[k][m];
				}
				++dest_y;
				dest_x = j;
			}
		}
	}
	matrix = tmp_matrix;
}

void sixth_func()
{
	int size = pow(2, l);
	vector<vector<int>> tmp_matrix(129, vector<int>(129, 0));
	int cnt = 0;
	for (int i = 1; i < pow(2, N) + 1; i += size)
	{
		cnt = 0;
		for (int j = 1; j < pow(2, N)  + 1; j += size)
		{
			++cnt;
			int dest_y = i;
			for (int k = i; k < i + size; ++k)
			{
				int dest_x = (pow(2, N) - (pow(2, l) * cnt)) + 1;
				for (int m = j; m < j + size; ++m)
				{
					tmp_matrix[dest_y][dest_x] = matrix[k][m];
					
					++dest_x;
				}
				++dest_y;
			}
		}
	}
	matrix = tmp_matrix;
}

void seventh_func()
{
	int size = pow(2, l);
	vector<vector<int>> tmp_matrix(129, vector<int>(129, 0));
	int cnt = 0;
	int cnt2 = 0;
	for (int i = 1; i < pow(2, N) +1; i += size)
	{
		cnt++;
		cnt2 = 0;
		for (int j = 1; j < pow(2, N)+1; j += size)
		{
			cnt2++;
			int dest_y = 1 + ((cnt2-1)*size);
			for (int k = i; k < i + size; ++k)
			{
				int dest_x = pow(2, N) - (size * cnt) + 1;
				for (int m = j; m < j + size; ++m)
				{
					tmp_matrix[dest_y][dest_x] = matrix[k][m];
					++dest_x;
				}
				++dest_y;
			}
		}
	}
	matrix = tmp_matrix;
}

void eighth_func()
{
	int size = pow(2, l);
	vector<vector<int>> tmp_matrix(129, vector<int>(129, 0));
	int cnt = 0;
	int cnt2 = 0;
	for (int i = 1; i < pow(2, N)+1; i += size)
	{
		cnt++;
		cnt2 = 0;
		for (int j = 1; j < pow(2, N)+1; j += size)
		{
			cnt2++;
			int dest_y = pow(2, N) - (size * cnt2) + 1;
			for (int k = i; k < i + size; ++k)
			{
				int dest_x = 1 + ((cnt - 1) * size);
				for (int m = j; m < j + size; ++m)
				{
					tmp_matrix[dest_y][dest_x] = matrix[k][m];
					++dest_x;
				}
				++dest_y;
			}
		}
	}
	matrix = tmp_matrix;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> N >> R;

	matrix.resize(129, vector<int>(129, 0));

	for (int i = 1; i < pow(2,N)+1; ++i)
	{
		int elem;
		for (int j = 1; j < pow(2,N) +1 ; j++)
		{
			cin >> elem;
			matrix[i][j] = elem;
		}
	}

	for (int i = 0; i < R; i++)
	{
		int input;
		cin >> input >> l;
		switch(input) {
		case 1 : 
			first_func();
			break;
		case 2 : 
			second_func();
			break;
		case 3 :
			third_func();
			break;
		case 4 :
			fourth_func();
			break;
		case 5 :
			fifth_func();
			break;
		case 6 :
			sixth_func();
			break;
		case 7 :
			seventh_func();
			break;
		case 8: 
			eighth_func();
			break;
		default :
			cout << "잘못된 입력 값 입니다.";
		}
	}

	for (int i = 1; i < pow(2, N) + 1; ++i)
	{
		for (int j = 1; j < pow(2, N) + 1; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	

	/*clock_t start, finish;
	double duration;
	start = clock();
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	std::cout << duration << "초" << "\n";*/




	return 0;
}

/*
요구사항 :
2^N * 2^N배열이 있다.
배열에 연산을 R번 적용한다.
연산은 8가지가 있다.
연산에는 단계 l이 있다.
단계 l은 부분 배열로 나눌 때 사용하는 값이다.
부분 배열의 크기는 2^l * 2^l이 돼야 한다.

연산 1 : 각 부분 배열을 상하 반전 시킨다.
연산 2 : 각 부분 배열을 좌우 반전 시킨다.
연산 3 : 연산은 각 부분 배열을 오른쪽으로 90도 회전시킨다.
연산 4 : 각 부분 배열을 왼쪽으로 90도 회전시킨다.
연산 5 : 배열을 상하 반전 시킨다.
연산 6 : 배열을 좌우 반전 시킨다.
연산 7 : 배열을 오른쪽으로 90도 회전
연산 8 : 배열을 왼쪽으로 90도 회전

데이터 :


시간복잡도 :


아이디어 :


*/