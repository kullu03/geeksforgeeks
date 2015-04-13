def getAnagramsTogether(l):
	ana_dict = {}
	for word in l:
		for w in l:
			if word.find(w)!=-1:
				if word not in ana_dict:
					ana_dict[word] = [word]
				else:
					ana_dict[word] = ana_dict[word].append(w)
		#if word not in ana_dict:
		#	ana_dict[word] = [word]
		#else:
			#ana_dict[word] = ana_dict[word].append(word)

	for(k,v) in ana_dict.iteritems():
		for word in v:
			print v







def getAnagramsTogether1(l):
	out = []
	if l == []:
		return
	for w in l:
		#print "w=",w
		for word in l:
			#print "word:", word
			if(w.find(word) >=0):
				out.append(word)
				l.remove(word)
				#print "l",l
	if(out) and if getAnagramsTogether1(l)):
		return out +  getAnagramsTogether1(l)
out = getAnagramsTogether1(["cat", "dog", "tac", "god", "act"])
print out
