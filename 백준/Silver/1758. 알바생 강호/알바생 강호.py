
N = int(input())
lst = []
answer = 0


for i in range(N):
    lst.append(int(input()))
lst.sort(reverse=True)

for i in range(N):
    tmp = lst[i]-i
    if tmp > 0:
        answer += tmp
print(answer)