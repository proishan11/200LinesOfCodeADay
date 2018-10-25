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
	tolevel={end: 0}
	l=1
	tol = 1
	frontier = [start]
	tofrontier = [end]

	while(frontier and tofrontier):
		#print(frontier)
		flag = False
		toflag = False
		next = []
		tonext = []
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
						if(temp in tolevel):
							return level[temp]+tolevel[temp]

					temp = next_node
		if(flag==False):
			return -1
		else:
			flag=False
			frontier=next
			l=l+1

		for todna in tofrontier:
			tonext_node = todna
			for i in range(8):
				totemp = tonext_node
				tostrand = totemp[i]
				for x in changes[tostrand]:
					totemp = replace(temp, i ,x)
					if(totemp in bank):
						toflag = True
						tonext.extend([totemp])
						tolevel[totemp] = tol
						if(totemp in level):
							return level[totemp]+tolevel[totemp]
					totemp = tonext_node
		if(toflag==False):
			return -1
		else:
			toflag=False
			tofrontier=tonext
			tol=tol+1




start = "AAAAAAAA"
end = "GGAAAAAA"
bank = ["GAAAAAAA","AAGAAAAA", "AAAAGAAA", "GGAAAAAA"]
print(findMutation(start, end, bank))


