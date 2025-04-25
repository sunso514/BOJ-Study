dc = {}
for _ in range(7):
    s, n = input().split()
    dc[s] = int(n)
print(max(dc, key=dc.get))