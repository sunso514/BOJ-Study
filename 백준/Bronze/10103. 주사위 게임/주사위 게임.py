N = int(input())
x = y = 100
for i in range(N):
    a, b = map(int, input().split())
    if a > b:
        y -= a
    elif a < b:
        x -= b
print(x)
print(y)