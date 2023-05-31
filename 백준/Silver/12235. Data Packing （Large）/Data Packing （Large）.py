from collections import deque

T =int(input())

for T in range(T):
    N, X = map(int, input().split())
    lst = list(map(int, input().split()))

    lst.sort()
    que = deque(lst)

    disk = 0
    while len(que) > 0:
        if que[0] + que[len(que)-1] <= X:
            if len(que) > 0:
                que.popleft()
        if len(que) > 0:
            que.pop()
        disk += 1
    print(f"Case #{T+1}: {disk}")