from collections import deque
from dataclasses import dataclass


@dataclass
class Vote:
    num: int = 0
    count: int = 1


def check_vt():  # 3번 규칙
    mins = 101
    ind = 1
    for i in range(len(deq)):
        if mins > deq[i].count:
            ind = i
            mins = deq[i].count
    deq.remove(deq[ind])


def check_jb(a): # 중복이라면 카운트를 증가
    for i in range(len(deq)):
        if a == deq[i].num:
            deq[i].count += 1
            return True
    return False


deq = deque()
N, C = int(input()), int(input())
lists = list(map(int, input().split()))

for i in range(C):
    if not check_jb(lists[i]):
        ls = Vote()
        ls.num = lists[i]
        if len(deq) >= N:
            check_vt()
        deq.append(ls)

        
ans = []
for i in range(len(deq)):
    ans.append(deq[i].num)
ans.sort()

for i in range(len(ans)):
    print(ans[i], end=' ')
