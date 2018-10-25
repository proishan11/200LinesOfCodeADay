#Sieve of Eratosthenes(Classical) O(nlog(logn)) time
#Can be done in O(n)

import math

def generate(n):
	prime = [1]*n
	for i in range(2, int(math.sqrt(n))+1):
		if(prime[i]):
			for j in range(2*i,n,i):
				prime[j] = 0
	for i in range(2,n):
		if(prime[i]):
			print(i,end=" ")

def main():
	print("Enter the value of n")
	n = int(input())
	print("Prime numbers less than n are")
	generate(n)

if __name__ == '__main__':
	main()