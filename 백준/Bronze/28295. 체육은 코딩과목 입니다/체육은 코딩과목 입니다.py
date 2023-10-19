N = 0
total = 0

for i in range (0,10) :
    order = int(input())

    if (order==1) :
        N += 1
    elif (order==2) :
        N += 2
    elif (order==3) :
        N += 3
    N %= 4

if (N == 0) :
    print("N")
elif (N == 1) :
    print("E")
elif (N == 2) :
    print("S")
elif (N == 3) :
    print("W")

