N, K = map(int, input().split())
K = str(K)
count = 0
now = 0
while(count < N):
    now += 1
    if (K not in str(now)):
        count += 1
print(now)