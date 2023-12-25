lst = [] 
for i in range(1, 6): 
    wow = input() 
    if "FBI" in wow: 
        lst.append(i) 
if lst: 
    print(*lst) 
else: 
    print("HE GOT AWAY!")

