def seggegate(l):
	s=0
	m=0
	h = len(l)-1
	while m <=h :
		if l[m] == 0 :
			l[s],l[m]= l[m],l[s]
			s = s+1
			m = m+1
		elif l[m]==1:
			m = m+1
		elif l[m]==2:
			l[m],l[h] = l[h],l[m]
			h = h-1

	return l


li = seggegate([2,1,1,0,0,2,0,0,1,1,2,0,1])

print li



