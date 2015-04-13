def mapDigitToAlphabet(arr):
	dic = {1:'a',2:'b',3:'c',4:'d',5:'e',6:'f',7:'g',8:'h',9:'i',10:'j',11:'k',12:'l',13:'m',14:'n',15:'o',16:'p',
17:'q',18:'r',19:'s',20:'t',21:'u',22:'v',23:'w',24:'x',25:'y',26:'z'}
	a = []
	b = []
	c = []
	d = []
	for i in arr:
		if i < 27:
			a.append(dic[i])
	# 2's comb
	i = 0
	while(i <= len(arr)-2 and len(arr)%2 == 0):
			num = arr[i]*10 + arr[i+1]
			if num <27:
				b.append(dic[num])
			i = i+2
	# 2's and 1's comb
	i = 0
	while(i <= len(arr)-2):
			num =  arr[i]*10 + arr[i+1]
			if num < 27:
				c.append(dic[num])
			num1 = arr[i+2]
			if num <27 and num1 < 27:
				c.append(dic[num1])
			i = i+3
	# 1's and 2's comb
	i = 0
	while(i <= len(arr)-2):
			num1 = arr[i]
			if num1 < 27:
				d.append(dic[num1])
			num = arr[i+1]*10 + arr[i+2]
			if num<27:
				d.append(dic[num])
			i = i+3

	print a,b,c,d

mapDigitToAlphabet([2,2,2,2,2])
