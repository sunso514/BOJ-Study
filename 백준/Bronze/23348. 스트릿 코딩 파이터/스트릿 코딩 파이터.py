lvl = list(map(int, input().split()))

N = int(input())

Gs = []
for _ in range(N):
    G = 0
    for _ in range(3):
        lst = list(map(int, input().split()))
        for k in range(3):
            G += lst[k] * lvl[k]
    Gs.append(G)
    
print(max(Gs))