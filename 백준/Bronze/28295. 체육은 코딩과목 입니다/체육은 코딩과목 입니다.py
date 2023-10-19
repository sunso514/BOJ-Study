N = 0
for i in range (0,10) :
    N = (N + int(input())) % 4
ans = "NESW"
print(ans[N])

