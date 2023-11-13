N = input()

dic = ['c=', 'c-', 'd-', 'lj', 'nj', 's=', 'z=', 'dz=']
ans = 0
i = 0

while(i < len(N)):
    for j in range(len(dic)):
        if (len(dic[j]) - 1 + i < len(N)):
            if (N[i:i+len(dic[j])] == dic[j]):
                i += len(dic[j]) - 1
                break
    ans += 1
    i += 1
print(ans)