a, b = map(int, input().split())
lst = [a/b]
for i in range(int(input())):
    a, b = map(int, input().split())
    lst.append(a/b)
print("%.2f" % (min(lst)*1000))