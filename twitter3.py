def difference(start, bank, count):
	result = []
	for value in bank:
		cost = sum([0 if value [i] == start[i] else 1 for i in range(8)])
		if cost == count:
			result.append(value)

	return result if len(result) else -1

def delete(one_diff_arr, bank):
	for i, val in enumerate(bank):
		if val == one_diff_arr:
			del(bank[i])
	return bank


def solution(start, end, bank):
	level = 0
	count = 1
	while(bank):
		level+=1
		one_diff_arr = difference(start, bank, count)
		if(one_diff_arr):
			if end in one_diff_arr:
				return level
			else:
				count=count+1
				bank = delete(one_diff_arr, bank)
		else:
			return -1

start = "AAAAAAAA"
end = "GGAAAAAA"
bank = ["GAAAAAAA","AAGAAAAA", "AAAAGAAA", "GGAAAAAA"]
print(solution(start, end, bank))

