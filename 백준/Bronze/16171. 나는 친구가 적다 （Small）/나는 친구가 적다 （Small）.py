s=input()
k=input()

cmpst = ""
for i in s:
    if i.isalpha():
        cmpst += i
if k in cmpst: print(1)
else: print(0)

