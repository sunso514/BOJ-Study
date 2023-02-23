bg = []
for _ in range(3):  
    bg.append(int(input()))
dr = []
for _ in range(2):
    dr.append(int(input()))
set = min(dr) + min(bg) - 50 
print(set)