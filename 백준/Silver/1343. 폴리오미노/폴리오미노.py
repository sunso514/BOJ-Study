N = input()

ans = []
streak = 0
for i in range(len(N)):
    if N[i] == 'X':
        if streak >= 0:
            streak += 1
        else:
            ans.append(streak)
            streak = 1
    else:
        if streak < 0:
            streak -= 1
        else:
            ans.append(streak)
            streak = -1
ans.append(streak)

res = ""

for i in range(len(ans)):
    if ans[i] > 0:
        tmp = ans[i]
        if tmp % 2 != 0:
            print(-1)
            exit()
        else:
            while tmp >= 4:
                res += "AAAA"
                tmp -= 4
            while tmp >= 2:
                res += "BB"
                tmp -= 2
    else:
        tmp = abs(ans[i])
        res += "."*tmp
print(res)
