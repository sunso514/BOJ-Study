N = int(input())
count = 1

dic = {'ChongChong':True}
for i in range(N):
	a, b = input().split()
	if a not in dic:
	    dic[a] = False
	if b not in dic:
	    dic[b] = False
	if dic[a] == True:
	    if dic[b] == False:
	        dic[b] = True
	        count += 1
	else:
	    if dic[b] == True:
	        dic[a] = True
	        count += 1
print(count)
		