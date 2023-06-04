import operator
from collections import deque
from dataclasses import dataclass

N = int(input())
st = input()

lst = []
tmp = 0
for i in range(N):
    if st[i] == 'Z':
        tmp += 1
    elif tmp > 0:
        lst.append(tmp)
        tmp = 0
if tmp > 0:
    lst.append(tmp)
res = 0
for i in range(len(lst)):
    res += (lst[i]+2)//3
print(res)