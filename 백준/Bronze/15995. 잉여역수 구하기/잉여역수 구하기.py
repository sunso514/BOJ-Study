A,M = map(int, input().split())
for i in range(1, 10001):
    if A*i%M==1:
        print(i)
        break