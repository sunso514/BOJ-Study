import math

def solution(denum1, num1, denum2, num2):
    boonmo = num1 * num2
    boonja = denum1 * num2 + denum2 * num1
    gcd_value = math.gcd(boonmo, boonja)
    answer = [boonja / gcd_value, boonmo / gcd_value]
    return answer