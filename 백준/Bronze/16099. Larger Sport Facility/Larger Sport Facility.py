N = int(input())
for i in range(N):
    t,wt,e,we=map(int,input().split())
    if t*wt<e*we:
        print("Eurecom")
    elif t*wt>e*we:
        print('TelecomParisTech')
    else:
        print('Tie')