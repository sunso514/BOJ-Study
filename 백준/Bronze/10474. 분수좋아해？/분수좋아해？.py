while True:
    n, m = map(int, input().split())
    if n == m == 0:
        break
    print(f"{n//m} {n%m} / {m}")