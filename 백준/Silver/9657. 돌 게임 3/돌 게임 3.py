N = int(input())
lists = [0]*1001
lists[1] = 1
lists[3] = 1
lists[4] = 1
if N >= 5:
    for i in range (5, N+1):
        if 0 in [lists[i-1],lists[i-3],lists[i-4]]:
            lists[i] = 1
print("SK") if lists[N] else print("CY")
