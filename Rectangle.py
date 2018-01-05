#Done

t = int(input());
while(t):
	
	l=[int(x) for x in input().split()]
	if(l[0] == l[1]):
		if(l[2]==l[3]):
			print("YES")
		else:
			print("NO")
	elif(l[0]==l[2]):
		if(l[1]==l[3]):
			print("YES")
		else:
			print("NO")
	elif(l[0]==l[3]):
		if(l[1]==l[2]):
			print("YES")
		else:
			print("NO")
	else:
		print("NO")
	t=t-1