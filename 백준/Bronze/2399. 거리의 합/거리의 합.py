N = int(input())
lst = list(map(int, input().split()))
cnt=0
for i in range(N):
    for j in range(N):
        cnt+=abs(lst[i]-lst[j])
print(cnt)