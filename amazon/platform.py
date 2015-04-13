def numberOfplatfrom(arr,dept):
	arr.sort()
	dept.sort()
	n = len(arr)
	#print arr
	#print dept
	i =1
	j= 0
	platform = 1
	result = 1
	while i < n and j < n :
		print i,j
		if(arr[i] < dept[j]):
			#print i,j
			platform = platform +1
			i = i+1
			#print platform
			if(platform > result):
				result = platform
			#	print result
		else:
			platfrom = platform-1
			j = j+1
			#print j
	return result

def main():
	arr = [900, 940, 950, 1100, 1500, 1800]
	dep = [910, 1200, 1120, 1130, 1900, 2000]
	r = numberOfplatfrom(arr,dep)
	print r


if __name__ == "__main__":
	main()
			
