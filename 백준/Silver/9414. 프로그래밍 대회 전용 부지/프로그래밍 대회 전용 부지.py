import operator
from collections import deque
from dataclasses import dataclass

N = int(input())

for _ in range(N):
    tmpls = []
    money = 5000000
    while(True):
        pr = int(input())
        if pr == 0:
            break
        tmpls.append(pr)
    tmpls.sort(reverse=True)
    for i in range(len(tmpls)):
        tmp = 2*pow(tmpls[i], i+1)
        money -= tmp
    if money < 0:
        print("Too expensive")
    else:
        print(5000000-money)




