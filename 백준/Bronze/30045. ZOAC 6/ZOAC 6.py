

n = int(input())
strs = [input() for i in range(n)]
ans = 0
for i in strs:
    if '01' in i or 'OI' in i:
        ans += 1
print(ans)