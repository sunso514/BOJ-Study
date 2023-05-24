N = int(input())
lst = list(map(int, input().split()))
lst.sort(reverse=True)

bob = 0
alis = 0
for i in range(0, N, 2):
    alis += lst[i]
for i in range(1, N, 2):
    bob += lst[i]

print(alis, bob)