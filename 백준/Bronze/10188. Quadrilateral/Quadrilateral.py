for _ in range(int(input())) :
    길이, wid = map(int, input().split())
    for _ in range(wid) :
        print('X' * 길이)
    print()