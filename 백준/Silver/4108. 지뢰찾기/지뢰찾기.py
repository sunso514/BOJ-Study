while True:
  row, col = map(int, input().split())
  if (col == 0 and row == 0) : break;

  mine = [input() for i in range(row)]
  check = [[0 for i in range(col)] for i in range(row)]


  dx = (1, -1, 0, 0, 1, -1, -1, 1)
  dy = (0, 0, -1, 1, 1, -1, 1, -1)

  for i in range(row):
    for j in range(col):
      if (mine[i][j] ==  '*') : continue;
      for k in range(8):
        tmpx = i + dx[k]
        tmpy = j + dy[k]

        if (tmpx < 0 or tmpy < 0 or tmpx >= row or tmpy >= col) :
          continue
        if (mine[tmpx][tmpy] == '*') :
          check[i][j] += 1

  for i in range(row):
    for j in range(col):
      print(check[i][j], end='') if (mine[i][j] == '.') else print('*', end='')
    print()