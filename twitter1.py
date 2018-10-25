def decrypt(string, key):
	i=0
	j=0
	result = ""
	while(i<len(string)):
		
		temp = ord(string[i])
		if(temp>=65 and temp<=90):
			if(temp-int(key[j])<65):
				req = temp-int(key[j])+26
			else:
				req = temp-int(key[j])
			result+=chr(req)
			j=j+1
		elif(temp>=97 and temp<=122):
			if(temp-int(key[j])<97):
				req = temp-int(key[j])+26
			else:
				req = temp-int(key[j])
			result+=chr(req)
			j=j+1
		if(j==len(key)):
			j=0
		else:
			result+=string[i]
		i=i+1
	return result

key='8251220'
string = 'Otjfvk'
print(decrypt(string,key))
