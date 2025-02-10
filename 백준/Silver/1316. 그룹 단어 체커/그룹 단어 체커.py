N = int(input())
count = N

for _ in range(N):
    get = input()
    for i in range(0, len(get)-1):
        if get[i] == get[i+1]:
            pass
        elif get[i] in get[i+1:]: 
            count -= 1
            break
print(count)

