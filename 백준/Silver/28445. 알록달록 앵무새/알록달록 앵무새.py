a_bd, a_ta = input().split()
b_bd, b_ta = input().split()

clr = []

if a_bd not in clr:
    clr.append(a_bd)
if a_ta not in clr:
    clr.append(a_ta)
if b_bd not in clr:
    clr.append(b_bd)
if b_ta not in clr:
    clr.append(b_ta)
clr.sort()

for i in range(len(clr)):
    for j in range(len(clr)):
        print(clr[i], clr[j])
