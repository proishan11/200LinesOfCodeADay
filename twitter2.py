def replace(temp, i ,x):
	result = list(temp)
	result[i] = x
	return "".join(result)

def findMutation(start, end, bank):
	changes = {'A': ['C','T','G'],
				'C': ['A','T', 'G'],
				'T': ['A', 'C', 'G'],
				'G': ['A', 'C', 'T']}
	level={start:0}
	l=1
	frontier = [start]
	while(frontier):
		print(frontier)
		flag = False
		next = []
		for dna in frontier:
			next_node = dna
			#print(next_node)
			for i in range(8):
				temp=next_node
				#print("temp=",temp)
				strand = temp[i]
				#print(changes[strand])
				for x in changes[strand]:
					#print(temp)
					temp = replace(temp, i, x)
					#print(temp)
					if(temp in bank):
						flag=True
						next.extend([temp])
						level[temp]=l
						if(temp==end):
							return level[temp]
					temp = next_node
		if(flag==False):
			return -1
		else:
			flag=False
			frontier=next
			l=l+1


start = "AAAAAAAA"
end = "GGAAAAAA"
bank = ["GAAAAAAA","AAGAAAAA", "AAAAGAAA", "GGAAAAAA"]
print(findMutation(start, end, bank))


