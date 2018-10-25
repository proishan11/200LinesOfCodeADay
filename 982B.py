n = int(input())
w = [int(x) for x in input().split()]
s = input()


x = []
result = ''

k=1
#seats = ['']*n
for i in w:
	temp = [k, i]
	x.extend([temp])
	k = k+1
x = sorted(x, key=lambda y: y[1])


result += str(x[0][0])

k = 1
indexes = [x[0]]
#print(indexes)

for i in range(1,len(s)):
	if(s[i] == '0'):
		result += str(x[k][0])
		
		indexes.extend([x[k]])
		
		
		k+=1
		#print(indexes)

	if(s[i] == '1'):
		

		result+=str(indexes[len(indexes)-1][0])
		indexes=indexes[0:len(indexes)-1]
		#print(indexes)

	


for i in result:
	print(i, end=' ')
print('')
