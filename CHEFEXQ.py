n,q = input().split()
n = int(n)
q = int(q)
a = [int(x) for x in input().split()]
for i in range(q):
	query = [int(x) for x in input().split()]
	if(query[0] == 1):
		a[query[1]-1] = query[2]
		#print(a)
	else:
		count = 0
		temp=1
		k = query[2]
		j = query[1]
		xor = a[0]
		if(k == xor):
			count+=1
		for y in range(1,j):
			xor = xor^a[y]
			#print("xor = ", xor)
			if(xor==k):
				count+=1
		print(count)
		

