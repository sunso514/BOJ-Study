N = int(input())
wd = str(input())
ck = 0
for i in range(1,N):
    l = wd[:i]
    r = wd[N-i:]
 
    cnt = 0
    for j in range(i):
        if l[j] != r[j]:
            cnt += 1
 
    if cnt == 1:
        ck = 1
        break
 
if ck == 1:
    print('YES')
else:
    print('NO')