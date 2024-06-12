K,W,M = map(int, input().split())
print((W-K)//M+(1 if (W-K)%M else 0))