
def binary_search(sto, min, max, target):
    res = 0
    while(min <= max):
        mid = (min + max) // 2
        if(b_block[mid] > target):
            max = mid - 1
        elif(b_block[mid] <= target):
            min = mid + 1
            res = mid
    #print (f"?? 뭐지 {mid}, {sto}")
    return res-sto




block_amount = int(input())
ink = list(map(int,input().split()))
b_block = list(map(int, input().split()))

for i in range(block_amount):
    print(binary_search(i, i,block_amount-1,ink[i]), end=' ')

