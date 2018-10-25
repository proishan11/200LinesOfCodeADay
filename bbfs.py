def equalChar(a,b):
	temp1=[]
	temp2=[]
	if(len(a) != len(b)):
		return false
	for i in a:
		temp1.append(i)
	for j in b:
		temp2.append(j)
	
	temp1.sort()
	temp2.sort()
	return(temp1 == temp2)

def getMin(fr="", to=""):
	parent = {fr:None}  
	level = {fr:0}
	l=1
	frontier = [fr]
	while(frontier):
		next = []
		for i in frontier:
			temp = i
			length = len(i)
			for x in range(length):
				for y in range(x+1,length):
					temp2 = list(temp)
					temp2[x], temp2[y] = temp2[y], temp2[x]
					temp2 = ''.join(temp2)
					if (temp2 not in frontier) and (temp2 not in parent):
						parent[temp2] = i
						level[temp2] = l
						next.append(temp2)
					#if(temp2 == to):
					#	return level
			#print(level)
			#print("")
			#print("")
			frontier = next
		l+=1
	return level

def main():
	#counter=1
	while(1):
		print("Enter the from string")
		fr = input()
		print("Enter the to string")
		to = input()
		if(equalChar(fr,to)):

			level = getMin(fr, to)
			print("Minimum swaps required for conversion is")
			print(level[to])
			break			
		else:
			print("Cannot be converted. Enter the value again")
	#print(equalChar("rimsha", "ahsrim"))
	#print(equalChar("abc", "abd"))

if __name__ == '__main__':
	main()
