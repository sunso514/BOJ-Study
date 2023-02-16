import math
def solution(n):
    answer = 2
    a = pow(n, 0.5)
    b = int(pow(n, 0.5))
    print(a, b)
    c = str(b) + ".0"
    if str(a) == c:
        answer = 1
    return answer