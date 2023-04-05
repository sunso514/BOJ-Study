a, b = map(int, input().split())
p = list(map(int, input().split()))
pty = a * b
for i in p:
    print(i - pty, end=' ')