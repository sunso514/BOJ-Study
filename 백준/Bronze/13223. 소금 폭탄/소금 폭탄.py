h, m, s = map(int, input().split(':'))
H, M, S = map(int, input().split(':'))
t = h*60*60 + m*60 + s
T = H*60*60 + M*60 + S

t = T - t if T > t else T-t+24*60*60
h = t//60//60
m = t//60 % 60
s = t%60

print("%02d:%02d:%02d" % (h, m, s))