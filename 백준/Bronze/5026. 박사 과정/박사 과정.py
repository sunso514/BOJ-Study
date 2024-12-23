N = int(input())

for i in range(N):
    get = input()
    if get == "P=NP":
        print("skipped")
    else:
        a, b = map(int, get.split("+"))
        print(a + b)
