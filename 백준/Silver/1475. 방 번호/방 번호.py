N = input()
lst = [0] * 10
for i in range(len(N)):
    nm = int(N[i])
    if nm == 6 or nm == 9:
        if lst[6] <= lst[9] : lst[6] += 1
        else : lst[9] += 1
    else : lst[nm] += 1
        
 
print(max(lst))