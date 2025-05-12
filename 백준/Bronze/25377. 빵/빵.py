ans = 1001
for i in range(int(input())) :
    A, B = map(int, input().split())
    if A <= B: 
        res = min(res, B)
print([ans, -1][ans == 1001])