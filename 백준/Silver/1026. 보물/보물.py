
N = int(input())
num_list_f = sorted(list(map(int, input().split())))
num_list_s = sorted(list(map(int, input().split())), reverse=True)
ans = 0
for i in range(N):
    ans += num_list_s[i] * num_list_f[i]
print(ans)