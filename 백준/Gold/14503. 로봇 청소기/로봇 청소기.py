
def check_inboard(cx, cy):
    if cx < 0 or cx >= N:
        return False
    if cy < 0 or cy >= M:
        return False
    if lists[cx][cy] == 1:
        return False
    return True

drs = [(-1, 0), (0, 1), (1, 0), (0, -1)] # 북 동 남 서
dx = (-1, 1, 0, 0)
dy = (0, 0, -1, 1)


N, M = map(int, input().split())
x, y, dire = map(int, input().split())
lists = [list(map(int, input().split())) for i in range (N)]


count = 0
while True:
    if lists[x][y] == 0:  # 규칙 1번
        lists[x][y] = 2
        count += 1

    tmp_ls = []
    for i in range(4):
        if check_inboard(x+dx[i], y+dy[i]):
            tmp_ls.append(lists[x+dx[i]][y+dy[i]])
    if 0 in tmp_ls: # 3번 규칙
        dire = (dire+3)%4
        if check_inboard(x+drs[dire][0], y+drs[dire][1]):
            if lists[x+drs[dire][0]][y+drs[dire][1]] == 0:
                x = x+drs[dire][0]
                y = y+drs[dire][1]
    else: # 2번 규칙
        tmp = (dire + 2) % 4
        if check_inboard(x+drs[tmp][0], y+drs[tmp][1]):
            x = x+drs[tmp][0]
            y = y+drs[tmp][1]
        else:
            break

print(count)


