import sys
input = sys.stdin.readline
N = input()
for i in range(0, len(N)-1, 10):
    print(N[i:min(i+10, len(N)-1)])


