N = int(input())
lst = [int(input()) for _ in range(N)]

l_cnt = r_cnt = 0
l_max = r_max = 0
for n in lst:
    if n > l_max:
        l_max = n
        l_cnt += 1
        
for n in lst[::-1]:
    if n > r_max:
        r_max = n
        r_cnt += 1
print(l_cnt)
print(r_cnt)