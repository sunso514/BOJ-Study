a, b = map(int,input().split())
N = 0
M = 0
for i in range(1, a+1):
  if a % i == 0:
    N += 1
  if N == b:
    M = i
    break
print(M)