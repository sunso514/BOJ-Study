N = int(input())

fib = [0 for i in range(10001)]
fib[0] = 0
fib[1] = 1

for i in range(2, 10001, 1):
    fib[i] = fib[i-1] + fib[i-2]

print(fib[N])