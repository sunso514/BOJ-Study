N = int(input())
lst = list(map(int, input().split()))

minv = 100001

for i in range(N):
    minv = min(minv, lst[i])
    print(minv, end=" ")
    minv += 1



