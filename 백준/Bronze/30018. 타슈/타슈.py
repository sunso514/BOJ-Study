n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = 0
for i in range(0, n) : ans += abs(a[i]-b[i]) 
print(ans//2)