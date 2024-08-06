cnt = 1
while 1:
    a = int(input())
    if a == 0:
        break
    b = 3 * a
    c = (b+1)//2 if b %2 else b//2
    d = 3 * c
    e = d // 9
    if a == 2*e:
        print(f"{cnt}. even {e}")
    else:
        print(f"{cnt}. odd {e}")
    cnt += 1