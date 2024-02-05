N = int(input())
ans = 0
if N <= 198:
    for i in range(1, 100):
        for j in range(1, 100):
            if i+j == N:
                ans += 1
                    
print(ans)