import sys

V, E = map(int, sys.stdin.readline().split())
S = int(sys.stdin.readline())

arrows = [[] for _ in range(V)]
d = [3000001 for _ in range(V)]

def bfs(start):
  #self에서 모두에게 가는 최단경로.
  d[start] = 0
  q = [[start, 0]]
  for node, l in q:
    if(d[node] < l):
      continue
    for k, v in arrows[node]:
      if(d[k] > l+v):
        q.append([k, l+v])
        d[k] = l+v

for i in range(E):  
  a, b, v = map(int, sys.stdin.readline().split())
  arrows[a-1].append([b-1, v])

bfs(S-1)

for i in d:
  if(i == 3000001):
    print('INF')
  else:
    print(i)