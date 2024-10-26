while True:
    a, b, c = map(int, input().split())
    if a == b == c == 0:
        break
    if c-b == b-a:
        print(f"AP {c + c-b}")
    else:
        print(f"GP {c * (c//b)}")