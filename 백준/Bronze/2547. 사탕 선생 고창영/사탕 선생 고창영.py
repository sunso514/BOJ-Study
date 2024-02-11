T = int(input())
for _ in range(T):
    Q = input()
    N = int(input())
    lis = [int(input()) for i in range(N)]
    print("YES" if sum(lis)%N == 0 else "NO")