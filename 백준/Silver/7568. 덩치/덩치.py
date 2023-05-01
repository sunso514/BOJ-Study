import sys
input = sys.stdin.readline

N = int(input())
lists = []

for _ in range(N):
    w, h = map(int, input().split())
    lists.append((w, h))

for i in lists:
    c = 1
    for j in lists:
        if i[0] < j[0] and i[1] < j[1]:
                c += 1
    print(c, end = " ")

