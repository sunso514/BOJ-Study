import sys
input = sys.stdin.readline
N = int(input())
stackoverflow = []
for i in range(N):
    tmp = int(input())
    stackoverflow.append(tmp) if tmp != 0 else stackoverflow.pop() if len(stackoverflow) > 0 else print(end = "")
print(sum(stackoverflow))