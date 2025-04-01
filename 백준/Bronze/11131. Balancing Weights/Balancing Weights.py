for i in range(int(input())):
    N = input()
    res = sum(map(int, input().split()))
    if res > 0:
        print("Right")
    elif res < 0:
        print("Left")
    else:
        print("Equilibrium")
