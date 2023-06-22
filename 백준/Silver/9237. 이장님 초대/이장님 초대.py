import operator
from collections import deque
from dataclasses import dataclass
import sys
input = sys.stdin.readline

N = int(input())

lst = list(map(int, input().split()))

lst.sort(reverse=True)

res = 0
for i in range(N):
    res = max(res, lst[i]+i+1)

print(res+1)
