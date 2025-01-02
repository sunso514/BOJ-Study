N = int(input())
wet = list(map(int, input().split()))
a = [0] * N 
st = 0 

for i in range(N):
    if wet[i] == 1:
        st += 1
    elif wet[i] == 0:
        st -= 1
    a[i] = st
print(sum(a))