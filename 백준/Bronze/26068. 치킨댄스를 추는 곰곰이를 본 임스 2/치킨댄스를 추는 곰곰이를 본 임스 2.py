N = int(input())
g = 0
for _ in range(N) :
    p = input()
    if int(p[2:]) <= 90 :
        g += 1
print(g)