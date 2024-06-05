lst = list(map(int, input().split()))
x, y, r = map(int, input().split())
print(lst.index(x) + 1 if x in lst else 0)