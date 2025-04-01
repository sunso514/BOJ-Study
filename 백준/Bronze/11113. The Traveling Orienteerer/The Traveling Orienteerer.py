import math
import sys

input = sys.stdin.readline
N = int(input().strip())

pts = []

for _ in range(N):
    x, y = map(float, input().strip().split())
    pts.append((x, y))
    
M = int(input().strip())
for _ in range(M):
    p = int(input().strip())
    ind = list(map(int, input().strip().split()))
    total = 0.0
    for i in range(1, p):
        x1, y1 = pts[ind[i-1]]
        x2, y2 = pts[ind[i]]
        total += math.sqrt((x2-x1) ** 2 + (y2 - y1)**2)
    print(round(total))
