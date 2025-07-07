N = int(input())
mx, mn = 1, 500000
for _ in range(N):
    T, B = map(int, input().split())
    mx = max(mx, T)
    mn = min(mn, B)
print((mx * mn) % 7 + 1)