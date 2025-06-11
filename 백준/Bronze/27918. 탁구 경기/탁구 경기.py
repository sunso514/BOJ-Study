import sys

N = int(sys.stdin.readline())

ct1 = 0
ct2 = 0

for _ in range(N):
    c = input()
    if c == 'D':
        ct1 = ct1 + 1
    else:
        ct2 = ct2 + 1

    if ct1>ct2 and ct1 == ct2 + 2:
        break
    if ct1 + 2 == ct2:
        break
        
print(str(ct1)+":"+str(ct2))