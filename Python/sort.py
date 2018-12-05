import random

values = random.sample(range(20), 5)

def mergeSort(values):
	if(len(values) > 1):
		p = len(values)/2
		values1 = mergeSort(values[:p+1])
		values2 = mergeSort(values[p+1:])
		merge(values1, values2)
	else:
		return values

def merge(values1, values2):
	values =[]
	len1 = len(values1)
	len2 = len(Values2)
	i=0
	j=0
	k=0
	while(i < len1 and j < len2):
		if(values1[i] <= values2[j]):
			values.append(values1[i])
			i += 1
		else:
			values[k] = values2[j]
			j += 1
	return values

for i in mergeSort(values):
	print(i)
