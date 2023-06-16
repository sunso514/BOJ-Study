import operator
from collections import deque
from dataclasses import dataclass
import sys
input = sys.stdin.readline

N, K = map(int, input().split())

def check_can(goal):
    need_upgrade = []
    for i in range(N):
        if lst[i] < goal:
            need_upgrade.append(lst[i])
        else:
            break
    #print("Help me please ",sum(need_upgrade), goal*len(need_upgrade))
    #print("Help me please ", need_upgrade, goal)
    if sum(need_upgrade) + K >= goal * len(need_upgrade):
        return True
    return False
lst = []
for i in range(N):
    lst.append(int(input()))
lst.sort()

left = lst[0]
right = lst[len(lst)-1] + K+1
mid = left + right // 2

while(left + 1 <= mid):
    #print("Debug",mid)1 1000
    if check_can(mid) == True:
        left = mid
    else:
        right = mid
    mid = (left + right) // 2
print(mid)

