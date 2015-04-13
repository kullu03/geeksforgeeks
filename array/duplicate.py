from sets import Set
def isDuplicate(arr,k):
	s = set()
	for i in range(0,len(arr)):
		if arr[i] in s:
			return 1
		else:
			s.add(arr[i])
		if(i>=k):
			#s.remove(arr[i-k])
			s.clear()
	return 0
	



if(isDuplicate([1, 2, 3,4,1, 2, 3, 4],3)):
	print "yes"
else:
	print "NO"


