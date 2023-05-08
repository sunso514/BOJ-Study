import sys
input = sys.stdin.readline
N = input()
for i in range((len(N)-1)//10 + 1):
    print(N[i*10:min((i+1)*10, len(N)-1)])


