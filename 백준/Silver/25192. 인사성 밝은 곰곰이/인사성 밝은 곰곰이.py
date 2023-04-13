N = int(input())
dic = {}
count = 0
for i in range(N):
    st = input()
    if (st == "ENTER"):
        dic = {}
    else:
        if st not in dic:
            dic[st] = True
            count += 1
print(count)