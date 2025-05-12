ans = 1001
for i in range(int(input())) :
    A, B = map(int, input().split())
    if A <= B: 
        ans = min(ans, B)
print([ans, -1][ans == 1001])