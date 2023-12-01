for c in range(int(input())) :
    p = ''
    s = input()
    for i in range(len(s)) :
        if p != s[i] :
            print(s[i], end = "")
            p = s[i]
    print()