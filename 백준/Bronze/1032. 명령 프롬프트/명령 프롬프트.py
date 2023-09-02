import sys
input = sys.stdin.readline

n = int(input())
res = list(input().rstrip())
for i in range(n-1):
    a = list(input().rstrip())
    for j in range(len(a)):
        if res[j] != a[j]:
            res[j] = '?'
            
print(''.join(res))