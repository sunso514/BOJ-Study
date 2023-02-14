def solution(num, total):
    d = 0
    for i in range(num):
        d += i
    total = (total-d)/num
    
    answer = []
    for i in range(num):
        answer.append(total+i)
    return answer