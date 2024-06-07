cs = int(input())

for c in range(cs):
    
    n = int(input())
    print(f"Case {c+1}:")
    
    for i in range(1, 7):
        for j in range(i, 7):
            if i+j == n:
                print(f"({i},{j})")