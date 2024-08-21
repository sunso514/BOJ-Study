N = int(input())
X = H = 0
while X <= N:
    H += 1
    X +=(H*2-1)**2-4*(H*(H-1)//2)
if X > N: H -= 1
print(H)