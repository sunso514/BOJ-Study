import sys
input = sys.stdin.readline
N = int(input())
st = []
for i in range(N):
    tmp = int(input())
    st.append(tmp) if tmp != 0 else st.pop()
print(sum(st))