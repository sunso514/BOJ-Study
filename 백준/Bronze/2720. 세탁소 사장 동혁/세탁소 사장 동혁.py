cse = int(input())
money = (25, 10, 5, 1)
count = [0] * 4

for i in range(cse):
    p = int(input())

    for j in range(len(money)):
        count[j] = p // money[j]
        p = p % money[j]

    print(' '.join(map(str, count)))