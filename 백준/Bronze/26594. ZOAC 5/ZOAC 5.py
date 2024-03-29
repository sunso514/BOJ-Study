w = input()
ans = 1
for i in range(len(w)-1) :
    if w[i] == w[i+1] :
        ans += 1
    else :
        break
print(ans)