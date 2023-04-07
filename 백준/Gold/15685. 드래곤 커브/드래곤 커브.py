from collections import deque

board = [[0 for _ in range(101)] for _ in range(101)]

dx = (0, -1, 0, 1)
dy = (1, 0, -1, 0)
N = int(input())
log = deque()


def make_dragon():  # 규칙 : 뒤집어서 +1
    global now_x, now_y
    for i in range(len(log) - 1, -1, -1):
        dirs = (log[i] + 1) % 4
        now_x = now_x + dx[dirs]
        now_y = now_y + dy[dirs]
        board[now_x][now_y] = 1
        log.append(dirs)


for i in range(N):
    log.clear()
    y, x, d, g = map(int, input().split())
    board[x][y] = 1
    now_x = x + dx[d]
    now_y = y + dy[d]
    board[now_x][now_y] = 1
    log.append(d)

    for j in range(g):
        make_dragon()

count = 0
for i in range(100):
    for j in range(100):
        if board[i][j] and board[i+1][j] and board[i+1][j+1] and board[i][j+1]:
            count += 1
print(count)
