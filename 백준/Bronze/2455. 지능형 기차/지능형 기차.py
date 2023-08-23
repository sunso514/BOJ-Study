on = []
ppl = 0

for _ in range(4):
    a, b = map(int, input().split())
    ppl += b
    ppl -= a
    on.append(ppl)

print(max(on))