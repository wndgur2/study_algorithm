import sys
from collections import deque

input = sys.stdin.readline
dx = [-1,1,0,0]
dy = [0,0,-1,1]

n,h,d = map(int, input().split())
board = []

sx=sy=-1

for x in range(n):
    board.append(list(input().strip()))
    if sx==-1:
        for y in range(n):
            if board[x][y] == 'S':
                sx, sy = x,y     # 시작 위치 기록

def solv():
    visited = [[0]*n for _ in range(n)]
    q = deque([(sx,sy,h,0,0)])  # 시작 x y, 체력, 내구도, 비용
    visited[sx][sy] = h

    while q:
        x, y, now_h, now_d, cnt = q.pop()

        for dir in range(4):
            nx = x + dx[dir]
            ny = y + dy[dir]

            if point_validator(nx,ny):
                if board[nx][ny] == 'E': # 최종점에 도달했을 때,
                    print(cnt+1)         # 이동 경로 수 출력
                    return

                nxt_h = now_h
                nxt_d = now_d

                if board[nx][ny] == 'U':
                    nxt_d = d   # 우산 내구도 할당 

                if nxt_d == 0:  # 내구도가 0
                    nxt_h -= 1  # 체력 1 감소
                else:
                    nxt_d -= 1  # 내구도 감소

                if nxt_h == 0:  # 체력 0 이면 리셋
                    continue

                if visited[nx][ny] < nxt_h: # 체력을 기록해놓고, 다음에 방문했을 때, 해당 칸보다 체력이 높아야 이동이 가능하도록 설정
                    visited[nx][ny] = nxt_h # 체력 기록
                    q.appendleft((nx, ny ,nxt_h, nxt_d, cnt+1)) # q에 넣기

    print(-1)

def point_validator(x,y):   # 상하좌우로 움직일 때, n 범위 넘어가지 않도록
    if x < 0 or y < 0 or x >= n or y >= n:
        return False
    return True

solv()