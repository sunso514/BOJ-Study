N = int(input())
lst = []
maxv = 0
for i in range(N):
    a = list(input().split())
    a.reverse()
    maxv = max(maxv, int(a[0]))
    lst.append(a)
lst.sort()

for i in range(N):
    if (int(lst[i][0]) == maxv):
        print(lst[i][1])
        exit()