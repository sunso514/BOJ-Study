import sys
input = sys.stdin.readline

N, M = map(int,input().split())
lists = [i+1 for i in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    tmp = lists[b-1]
    lists[b-1] = lists[a-1]
    lists[a-1] = tmp

for i in range(N):
    print(lists[i], end= " ")
