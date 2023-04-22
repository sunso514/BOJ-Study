dials = ('ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'WXYZ')
N = input()
c = 0
for j in range(len(N)):
    for i in dials:
        if N[j] in i:
            c += dials.index(i)+3
print(c)
