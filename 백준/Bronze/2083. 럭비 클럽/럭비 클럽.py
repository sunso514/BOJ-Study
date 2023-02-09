if __name__ == '__main__':
    while True:
        n, a, w = input().split()
        a, w = int(a), int(w)
        if n == '#' and w == 0 and a == 0:
            quit()
        if a > 17 or w >= 80:
            print("%s Senior"%n)
        else:
            print("%s Junior"%n)