a,b,c,d,e,f = map(int,input().split())

for fs in range(-999,1000):
    for se in range(-999,1000):
        if a*fs + b*se == c and d*fs + e*se == f:
            print(fs,se)