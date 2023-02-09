for _ in range(int(input())):
    
    n, m = input().split()
    
    if m == "kg":
        print("%.4f %s" % (float(n) * 2.2046, "lb"))
    elif m == "lb":
        print("%.4f %s" % (float(n) * 0.4536, "kg"))
    elif m == "l":
        print("%.4f %s" % (float(n) * 0.2642, "g"))
    else:
        print("%.4f %s" % (float(n) * 3.7854, "l"))