highest = -1
value = -1
for i in range(5):
  score = sum(list(map(int, input().split())))
  if score > value:
    highest = i + 1
    value = score
print(highest, value)
