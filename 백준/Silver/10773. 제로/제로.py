import sys
input = sys.stdin.readline
N = int(input())
stackoverflow = []
def gt():
    if len(stackoverflow) > 0:
        stackoverflow.pop()
for i in range(N):
    tmp = int(input())
    stackoverflow.append(tmp) if tmp != 0 else gt()
print(sum(stackoverflow))
