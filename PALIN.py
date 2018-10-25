#time limit exceeded

def getpal(n):
	flag=True
	while(1):
		n=n+1
		string=str(n)
		for x in range(len(string)//2):
			flag=True
		
			if(string[x]==string[len(string)-x-1]):
				continue
			else:
				flag=False
				break
		if(flag==True):
			return n
			
t = int(input())
for i in range(t):
	n = int(input())
	print(getpal(n))