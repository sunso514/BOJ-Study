a, b = map(int, input().split())
ans = 1
while 1:
    if b * ans - a * ans >= b:
        break
    ans += 1
print(ans)