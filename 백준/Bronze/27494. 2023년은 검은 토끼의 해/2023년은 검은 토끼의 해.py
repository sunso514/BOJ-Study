def checkmyo(a):
    order = ['2', '0', '2', '3']
    res = str(a)
    count = 0
    for i in range(0, len(res), 1):
        if res[i] == order[count]:
            count += 1
            if count == 4:
                return True
    return False

gint = int(input())
res = 0
if gint < 2023:
    print (0)
    exit()
for i in range(2023, gint+1, 1):
    if checkmyo(i) == True:
        res += 1

print(res)



