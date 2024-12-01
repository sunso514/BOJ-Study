n = int(input())
p, q, r, s = map(int, input().split())
a = int(input())
lst = [0] * (n + 1)
for i in range(1, n + 1):
    if i == 1:
        lst[i] = a
        continue
    if i % 2 == 0: lst[i] = (p * lst[(i // 2)]) + q
    else: lst[i] = (r * lst[(i // 2)]) + s    
print(sum(lst))