lst1 = [int(input()) for _ in range(3)]
lst2 = [int(input()) for _ in range(3)]
A = lst1[0]*3 + lst1[1]*2 + lst1[2]
B = lst2[0]*3 + lst2[1]*2 + lst2[2]
if A == B:
    print("T")
elif A > B:
    print("A")
else:
    print("B")