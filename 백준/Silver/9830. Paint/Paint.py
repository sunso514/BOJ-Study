import operator
from collections import deque
from dataclasses import dataclass


@dataclass(order=True)
class Paint:
    price: int = 0
    inc: int = 0


N = int(input())

lst = [Paint() for i in range(N)]
price = list(map(int, input().split()))
inc = list(map(int, input().split()))
for i in range(N):
    lst[i].price = price[i]
    lst[i].inc = inc[i]

lst.sort(key=operator.attrgetter('inc'), reverse=True)
ans = 0
for i in range(N):
    ans += lst[i].price+lst[i].inc*i
print(ans)
