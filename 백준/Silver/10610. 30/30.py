N,tot = sorted(input(), reverse=True), 0
for i in range(len(N)) : tot += int(N[i])
print(-1) if (N[0] == '0' or N[len(N)-1] != '0' or tot % 3 != 0) else print(''.join(N))
