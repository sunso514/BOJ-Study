N = int(input())
print(' ' * (N-1) + '*')
for i in range(N-1):
    print(' ' * (N-2-i) + '*' + ' ' * (2*i+1) + '*')