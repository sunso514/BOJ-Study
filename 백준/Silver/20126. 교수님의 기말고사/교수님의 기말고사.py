import operator
from collections import deque
from dataclasses import dataclass
import sys
input = sys.stdin.readline


@dataclass(order=True)
class tme:
    start: int = 0
    time: int = 0




N, M, S = map(int, input().split())

lst = []

for i in range(N):
    lst.append(tme())
    lst[i].start, lst[i].time = map(int, input().split())

lst.sort()

minv = 0 # 끝난 시점
# 0 일때 다음 타임이 4부터 시작 이면

for i in range(N):
    if minv+M <= lst[i].start:
        print(minv)
        exit()
    else:
        minv = lst[i].start+lst[i].time

if minv + M <= S:
    print(minv)
else:
    print(-1)




