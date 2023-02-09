#goal_e, goal_s, goal_m = map(int, input().split())



casenum = 1

while(True):
    people = int(input())
    list = [0]*people
    if people == 0:
        break

    name = [input() for i in range(people)] # 이름 목록 추가
    for i in range(people*2-1):
        num, check = input().split()
        list[int(num)-1] += 1
    for i in range(people):
        if list[i] != 2:
            print(f"{casenum} {name[i]}")
            break
    casenum += 1
    
