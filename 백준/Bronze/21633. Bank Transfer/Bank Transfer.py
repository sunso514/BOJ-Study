k = int(input())
f = 25 + k*0.01

if f < 100:
    print(100)
elif f > 2000:
    print(2000)
else:
    print(f)