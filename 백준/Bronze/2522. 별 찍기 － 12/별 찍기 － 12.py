ip = int(input())
for i in range(1, ip+1):
    print(' '*(ip-i) + '*'*i)
for i in range(1, ip):
    print(' '*(i) + '*'*(ip-i))