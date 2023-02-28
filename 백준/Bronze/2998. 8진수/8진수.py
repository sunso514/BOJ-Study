a = input()

squ = []

while len(a) > 3:
    length = len(a)
    str = a[length-3]+a[length-2]+a[length-1]
    num = 0
    for i in range(3):
        if int(str[2-i]) == 1:
            num += pow(2, i)
    squ.append(num)
    a = a[:-3]

if len(a) > 0:
    num = 0
    for i in range(len(a)):
        if int(a[len(a)-1-i]) == 1:
            num += pow(2, i)
    squ.append(num)

res = 0
for i in range(len(squ)):
    res += pow(10, i) * squ[i]

print(res)
    
    
