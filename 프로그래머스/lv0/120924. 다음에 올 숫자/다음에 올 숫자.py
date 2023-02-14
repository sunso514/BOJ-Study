def solution(common):
    
    length = len(common)
    answer = 0
    
    if common[1] - common[0] == common[2] - common[1]:
        answer = common[length-1] + common[1] - common[0]
    else:
        answer = common[length-1] * common[1] / common[0]
        
    return answer